#include <stdio.h>
#include "../include/config.h"

extern char grid[ROWS][COLS];
extern int score;

void drawGrid() {
    printf("\033[H");  // move cursor to top-left

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c", grid[r][c]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}
