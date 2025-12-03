# Rhythm Game in C Terminal!
This project is a simple terminal-based rhythm game created using the C programming language.
Notes fall down the screen in four lanes (A, S, D, F), and the player must press the correct key at the correct time to score points.

# Features
- 4-lane rhythm gameplay (A / S / D / F keys)
- Falling notes rendered in terminal using a grid system
- Reads beatmaps from .txt files (easy, medium, hard)
- Score system with hit detection
- Main menu (Start Game, Select Difficulty, Instructions, Exit)
- Level complete summary screen
- Modular C code split into multiple .c and .h files

# How to Compile and Run
### Compile

Open terminal inside src/ folder:

`` gcc main.c clearGrid.c drawGrid.c loadSong.c updateNotes.c menu.c -I ../include -o game ``

### Run
`` ./game ``

# Built by
Vedansh Rawat
B.Tech CSE Batch 48
SAP - 590027560
