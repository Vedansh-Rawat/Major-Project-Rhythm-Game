// Header Files!
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "../include/config.h"
#include "../include/menu.h"

char grid[ROWS][COLS];
Note notes[MAX_NOTES];
char beats[MAX_BEATS][5];

int noteCount = 0;
int score = 0;
int totalBeats = 0;
int currentBeat = 0;
int frameCounter = 0;
int beatInterval = 1;
char feedbackText[20] = "";
int feedbackTimer = 0;
int combo = 0;

void clearGrid();
void drawGrid();
void loadSong(const char* filename);
void updateNotes();

int main() {
    int choice;
    char selectedSong[256] = "../songs/easy.txt";
    printf("\033[2J");

    // Main Menu Loop
    while(1){
        choice = showMainMenu();

        if (choice == 1){
            break; // Default difficulty set to Easy
        }
        else if (choice == 2){
            if (selectSong(selectedSong)){
                break;
            }
        }
        else if (choice == 3){
            showInstructions();
        }
        else if (choice == 4){
            return 0;
        }
    }

    noteCount = 0;
    score = 0;
    combo = 0;
    feedbackText[0] = '\0';
    feedbackTimer = 0;
    currentBeat = 0;
    frameCounter = 0;

    loadSong(selectedSong);
    printf("\033[2J\033[H");

    // Main Game Loop
    while (1) {
    if (frameCounter % beatInterval == 0) {
        if (currentBeat < totalBeats) {

            for (int i = 0; i < 4; i++) {
                char ch = beats[currentBeat][i];

                if (ch == 'A' || ch == 'S' || ch == 'D' || ch == 'F') {
                    notes[noteCount].row = 0;
                    notes[noteCount].active = 1;
                    notes[noteCount].lane = i;
                    noteCount++;
                }
            }
            currentBeat++;
        }
    }

    frameCounter++;


    clearGrid();

    // draw existing notes
    for (int i = 0; i < noteCount; i++) {
        if (notes[i].active) {
            int r = notes[i].row;
            int lane = notes[i].lane;

            if (r >= 0 && r < ROWS) {
                if (lane == 0) grid[r][5]  = 'O';
                if (lane == 1) grid[r][15] = 'O';
                if (lane == 2) grid[r][25] = 'O';
                if (lane == 3) grid[r][35] = 'O';
            }
        }
    }

    drawGrid();
    updateNotes();

    // Ending Check
    int activeNotes = 0;
    for (int i = 0; i < noteCount; i++){
        if (notes[i].active){
            activeNotes = 1;
            break;
        }
    }

    if (currentBeat >= totalBeats && !activeNotes){
        break;
    }



    Sleep(200);

    char keyPressed = 0;
    if (_kbhit()){
        keyPressed = _getch();
    }
    int laneHit = -1;
    if (keyPressed == 'a' || keyPressed == 'A'){
        laneHit = 0;
    }
    if (keyPressed == 's' || keyPressed == 'S'){
        laneHit = 1;
    }
    if (keyPressed == 'd' || keyPressed == 'D'){
        laneHit = 2;
    }
    if (keyPressed == 'f' || keyPressed == 'F'){
        laneHit = 3;
    }

    if (laneHit != -1){
        int hitSomething = 0;
        for (int i = 0; i < noteCount; i++){
            if (notes[i].active && notes[i].lane == laneHit){
                if (notes[i].row == PERFECT_ROW || notes[i]. row == PERFECT_ROW - 1 || notes[i].row == PERFECT_ROW + 1){
                    notes[i].active = 0;
                    score += 100;
                    combo++;

                    strcpy(feedbackText, "\033[32mHIT!\033[0m");
                    feedbackTimer = 5;
                    hitSomething = 1;
                    break;
                    }
                }
            }
        }
    }   

    // Result Screen
    printf("\033[2J\033[H");
    printf("============= Level Complete =============\n");
    printf("Final Score: %d\n", score);
    printf("===== Press Enter to go back to menu =====\n");
    printf("==========================================\n");
    getchar();
    main();
}
