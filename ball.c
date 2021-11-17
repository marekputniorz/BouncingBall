#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define ROWS 20
#define COLS 70

int main() {
    char window[ROWS][COLS];
    srand(time(0));    
    //Ohraničení
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if (c == 0 || c == COLS-1 || r == 0 || r == ROWS-1) {
                window[r][c] = '#';
            }
            else {
                window[r][c] = ' ';
            }
        }
    }
    //Generování náhodné pozice kuličky
    int ballPosCol = (rand() % COLS-3) + 3;
    int ballPosRow = (rand() % ROWS-3) + 3;

    while(ballPosRow >= ROWS-1 || ballPosRow <= 0 || ballPosCol >= COLS-1 || ballPosCol <= 0) {
            ballPosRow = (rand() % ROWS-3) + 3;
            ballPosRow = (rand() % COLS-3) + 3;
    }

    //Generování pohybu
    int hMov = (rand()%2)*2-1;
    int vMov = (rand()%2)*2-1;
    
    while (1){
        for (int r = ROWS-2; r > 0; --r) {
            for (int c = 1; c < COLS-1; c++) {
                window[r][c] = ' ';
            }
        }
        
        //Nastavení pozice kuličky a pohyb kuličky po obrazovce
        window[ballPosRow][ballPosCol] = 'O';
        ballPosRow += vMov;
        ballPosCol += hMov;
        //Odrážení kuličky
        if (ballPosRow >= ROWS-2 || ballPosRow <= 1) {
            vMov*=-1;
        }
        
        if (ballPosCol >= COLS-2 || ballPosCol <= 1) {
            hMov*=-1;
        }
        
        //Výpis ohraničení na obrazovku
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                printf("%c", window[r][c]);
            }
            printf("\n");
        }
        usleep(250000);
    }
    return 0;
}