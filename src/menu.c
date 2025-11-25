#include <stdio.h>
#include <string.h>
#include "../include/config.h"

int showMainMenu(){
  int choice;

  printf("=============================================================\n");
  printf("======================== Rhythm Game! =======================\n");
  printf("=============================================================\n");
  printf("1. Start Game!\n");
  printf("2. Select Level!\n");
  printf("3. Instructions\n");
  printf("4. Exit\n");

  printf("=============================================================\n");
  printf("Enter choice: \n");
  scanf("%d", &choice);
  getchar();

  return choice;
}

void showInstructions(){
  printf("======================= Instructions ========================\n");
  printf("Controls: \n");
  printf(" - Use A, S, D and F to hit the notes!\n");
  printf(" - Hit when the notes reach the line!\n");
  printf(" - Hit notes to increase score and combo! Missing a note resets the combo.\n");
  printf("==============================================================\n");
  getchar();
}

int selectSong(char *outFilename){
  int choice;
  printf("===============================================================\n");
  printf("========================= Select Level ========================\n");
  printf("1. Level 1 - Easy\n");
  printf("2. Level 2 - Medium\n");
  printf("3. Level 3 - Hard\n");
  printf("Enter choice: \n");
  scanf("%d", &choice);
  getchar();

  if (choice == 1){
    strcpy(outFilename, "../songs/easy.txt");
    return 1;
  }
  else if (choice == 2){
    strcpy(outFilename, "../songs/medium.txt");
    return 1;
  }
  else if (choice == 3){
    strcpy(outFilename, "../songs/hard.txt");
    return 1;
  }

  return 0;
}