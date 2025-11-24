#include <stdio.h>
#include "../include/config.h"

extern char beats[MAX_BEATS][5];
extern int totalBeats;

void loadSong(const char* filename) {

    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: Could not open file: %s\n", filename);
        return;
    }

    char line[10];

    totalBeats = 0;

    while (fgets(line, sizeof(line), f)) {
        for (int i = 0; i < 4; i++) {
            beats[totalBeats][i] = line[i];
        }

        beats[totalBeats][4] = '\0'; 
        totalBeats++;
    }

    fclose(f);
}
