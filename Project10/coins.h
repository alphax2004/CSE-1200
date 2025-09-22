#ifndef COINS_HPP
#define COINS_HPP

#define MAX_COINS 5
extern int coin;
#include "level1.h"

double coinX[MAX_COINS];
double coinY[MAX_COINS];
bool coinVisible[MAX_COINS];

extern bool levelCompleted;




void initCoins() {
	int startingX = 1800; // Start far right
	int coinGap = 1000;    // Big gap between coins

	for (int i = 0; i < MAX_COINS; i++) {
		coinX[i] = startingX + i * coinGap;   //x er side e coins er majhe koto gap
		coinY[i] = rand() % 350 + 350; // random Y
		coinVisible[i] = true;
	}
}


void moveCoins() {
	if (levelCompleted) return;
	for (int i = 0; i < MAX_COINS; i++) {
		if (!coinVisible[i]) continue;

		// Skip coin movement if it's on top of a pipe
		bool onPipeHere = false;
		for (int j = 0; j < MAX_PIPES; j++) {
			if (coinX[i] + 30 >= pipeX[j] && coinX[i] <= pipeX[j] + pipeWidth &&
				abs(coinY[i] - (pipeY[j] + pipeHeight)) <= 5) {
				onPipeHere = true;
				break;
			}
		}
		if (!onPipeHere)
			coinX[i] -= 0.08; // Move left

		// Reset if off screen
		if (coinX[i] < -50) {
			coinX[i] = 1280 + rand() % 400;
			coinY[i] = groundY + 120 + rand() % 300;
		}
	}
}
void showCoins() {
	for (int i = 0; i < MAX_COINS; i++) {
		if (coinVisible[i]) {
			// Draw normally
			iShowImage(coinX[i], coinY[i], 40, 40, coinImage);
		}

	}
}



void checkCoinCollision() {
	if (levelCompleted) return;
	for (int i = 0; i < MAX_COINS; i++) {
		if (!coinVisible[i]) continue;

		bool collided = playX + 110 >= coinX[i] && playX <= coinX[i] + 40 && playY + 120 >= coinY[i] && playY <= coinY[i] + 40;

		// Coin is only collected if the player is currently jumping
		if (collided) 
		{
			coin++;
			
			coinVisible[i] = false;  //collide korar por invisible 
		
			coinX[i] = 1280 + rand() % 500;
			coinY[i] = groundY + 120 + rand() % 300;
			coinVisible[i] = true;
		}
	}
}












#endif
