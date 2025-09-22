#ifndef ENEMY_HPP
#define ENEMY_HPP

#define MAX_ENEMIES 4
#include "level1.h"

//value in player.h
extern int health;
extern int groundY;   
extern double playX, playY;
extern int page;

// Enemy properties
double enemyX[MAX_ENEMIES];
double enemyY[MAX_ENEMIES];
bool enemyVisible[MAX_ENEMIES];
float enemySpeed[MAX_ENEMIES];
int enemyFrame[MAX_ENEMIES];

//value in imain.cpp
extern int score;
extern bool levelCompleted;

double enemyWidth = 110;
double enemyHeight = 115;



// Initialize enemies (all invisible at start)
void initEnemies() {
	for (int i = 0; i < MAX_ENEMIES; i++) {
		enemyVisible[i] = false;
	}
}

// Spawn a new enemy at random Y position
void spawnEnemy() {
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (!enemyVisible[i]) {
			enemyX[i] = 1280 + rand() % 300;               // spawn off screen to right
			enemyY[i] = groundY + (rand() % 450);          // anywhere from ground to top area
			enemySpeed[i] = 0.02 + ((rand() % 5) * 0.02); // very slow speed
			enemyFrame[i] = rand() % 5;                     // random starting frame
			enemyVisible[i] = true;
			break; // only one spawn per call
		}
	}
}

// Move enemies
void moveEnemies() {
	if (levelCompleted) return;
	for (int i = 0; i<MAX_ENEMIES; i++){
		if (!enemyVisible[i]) continue;

		enemyX[i] -= enemySpeed[i]*1;

		if (enemyX[i]<-enemyWidth) enemyVisible[i] = false;

		// Animate every frame
		
			enemyFrame[i] = (enemyFrame[i]+1) % 5;

	}
}

// Draw enemies
void showEnemies() {
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (enemyVisible[i]) {
			iShowImage(enemyX[i], enemyY[i], enemyWidth, enemyHeight, enemyleft[enemyFrame[i]]);
		}
	}
}

// Collision detection
void checkEnemyCollision() {
	if (levelCompleted) return;
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (!enemyVisible[i]) continue;

		bool collided = (playX + 110 >= enemyX[i] &&
			playX <= enemyX[i] + enemyWidth &&
			playY + 120 >= enemyY[i] &&
			playY <= enemyY[i] + enemyHeight);

		if (collided) {
			// Check if player is hitting from FRONT (not from top)
			if (playY < enemyY[i] + enemyHeight - 20) {
			
				enemyVisible[i] = false;
				
				health--;
			}
			else {
				
				enemyVisible[i] = false;
				score += 1;
				
			
			}
		}
	}
}


#endif
