#include <stdio.h>
#include "../include/config.h"

extern char grid[ROWS][COLS];

void clearGrid() {
    // Fill with spaces
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            grid[r][c] = ' ';
        }
    }

    // Vertical lane borders
    for (int r = 0; r < ROWS; r++) {
        grid[r][0]  = '|';
        grid[r][10] = '|';
        grid[r][20] = '|';
        grid[r][30] = '|';
        grid[r][39] = '|';
    }

    // Lane labels
    grid[0][5]  = 'A';
    grid[0][15] = 'S';
    grid[0][25] = 'D';
    grid[0][35] = 'F';

    // Perfect row
    for (int c = 1; c < 39; c++) {
        if (c == 10 || c == 20 || c == 30) continue;
        grid[PERFECT_ROW][c] = '=';
    }
}
