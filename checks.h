#ifndef _CHECKS_H_
#define _CHECKS_H_

/*Checks if you won the game*/
void checkIf2048(int** grid);

/*Checks if you lost the game*/
void checkifGameOver(int** grid);

/*Checks for new high score*/
void checkAndStoreHighScore(int** grid);

/*Returns 0 if grids are the same*/
int checkIfGridsAreTheSame(int** currentgrid, int** nextgrid);

#endif