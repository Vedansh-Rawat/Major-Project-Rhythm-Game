#include <stdio.h>
#include "../include/config.h"

extern Note notes[MAX_NOTES];
extern int noteCount;

void updateNotes() {
    for (int i = 0; i < noteCount; i++) {
        if (notes[i].active) {
            notes[i].row++;

            if (notes[i].row >= ROWS) {
                notes[i].active = 0;  // remove notes leaving screen
            }
        }
    }
}
