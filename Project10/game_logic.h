#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include <cstdlib>
#include <ctime>
#include <cmath>

// ================= Player ===================
extern double playX, playY;
extern int health;
extern int groundY;
double playerWidth = 110;
double playerHeight = 120;

// ================= Shield ===================
bool shieldActive = false;
double shieldX = 0, shieldY = 0;
int shieldTimer = 0;
const int SHIELD_DURATION = 50000;
int shieldRadius = (int)(playerHeight * 0.6);

void updateShieldPosition() {
	if (shieldActive) {
		shieldX = playX + playerWidth / 2;
		shieldY = playY + playerHeight / 2;
	}
}

void drawShield() {
	if (shieldActive) {
		iSetColor(0, 255, 255);
		iCircle(shieldX, shieldY, shieldRadius);
		iCircle(shieldX, shieldY, shieldRadius + 6);
	}
}

// ================= Crystals ===================
#define MAX_CRYSTALS 100
double crystalX[MAX_CRYSTALS];
double crystalY[MAX_CRYSTALS];
bool crystalVisible[MAX_CRYSTALS];

void initCrystals() {
	int startingX = 1800;
	int gap = 1000;
	for (int i = 0; i < MAX_CRYSTALS; i++) {
		crystalX[i] = startingX + i * gap;
		crystalY[i] = groundY + 120 + rand() % 300;
		crystalVisible[i] = true;
	}
}

void spawnCrystal() {
	if (page != 10) return;
	for (int i = 0; i < MAX_CRYSTALS; i++) {
		if (!crystalVisible[i] && rand() % 3 == 0) {
			crystalVisible[i] = true;
			crystalX[i] = 1280 + rand() % 500;
			crystalY[i] = groundY + rand() % 400;
			break;
		}
	}
}

void moveCrystals() {
	for (int i = 0; i < MAX_CRYSTALS; i++) {
		if (!crystalVisible[i]) continue;

		bool onPipeHere = false;
		for (int j = 0; j < MAX_PIPES; j++) {
			if (crystalX[i] + 30 >= pipeX[j] && crystalX[i] <= pipeX[j] + pipeWidth &&
				abs(crystalY[i] - (pipeY[j] + pipeHeight)) <= 5) {
				onPipeHere = true;
				break;
			}
		}

		if (!onPipeHere) crystalX[i] -= 0.08;

		if (crystalX[i] < -50) {
			crystalX[i] = 1280 + rand() % 400;
			crystalY[i] = groundY + 120 + rand() % 300;
		}
	}
}

void showCrystals() {
	for (int i = 0; i < MAX_CRYSTALS; i++) {
		if (crystalVisible[i])
			iShowImage(crystalX[i], crystalY[i], 40, 40, crystalImg);
	}
}

// ================= Fireballs ===================
#define ENEMY_FIREBALL 0
#define PLAYER_FIREBALL 1
const int MAX_FIREBALLS = 3;
double fireballDX[MAX_FIREBALLS], fireballDY[MAX_FIREBALLS];
double fireballX[MAX_FIREBALLS], fireballY[MAX_FIREBALLS];
double fireballSpeed[MAX_FIREBALLS];
bool fireballVisible[MAX_FIREBALLS], fireballToRight[MAX_FIREBALLS], reflected[MAX_FIREBALLS];
int fireballOwner[MAX_FIREBALLS];
double fireballWidth = 40, fireballHeight = 40;

void initFireballs() {
	for (int i = 0; i < MAX_FIREBALLS; i++)
		fireballVisible[i] = false;
}

void spawnFireball(double x, double y, bool toRight = true) {
	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballVisible[i]) {
			fireballX[i] = x;
			fireballY[i] = y;
			fireballSpeed[i] = 0.2;
			fireballVisible[i] = true;
			fireballToRight[i] = toRight;
			fireballDY[i] = 0;
			reflected[i] = false;
			fireballOwner[i] = ENEMY_FIREBALL;
			break;
		}
	}
}

void moveFireballs() {
	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballVisible[i]) continue;

		if (fireballToRight[i])
			fireballX[i] += fireballSpeed[i];
		else
			fireballX[i] -= fireballSpeed[i];

		fireballX[i] += fireballDX[i];
		fireballY[i] += fireballDY[i];


		if (fireballX[i] < -fireballWidth || fireballX[i] > 1280 ||fireballY[i] < 0 || fireballY[i] > 780)
			fireballVisible[i] = false;
	}
}

void showFireballs() {
	for (int i = 0; i < MAX_FIREBALLS; i++)
	if (fireballVisible[i])
		iShowImage(fireballX[i], fireballY[i], fireballWidth, fireballHeight, fireballImg);
}

void enemyAutoFireball() {
	if (page != 10) return;
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (!enemyVisible[i]) continue;

		int spawnChance;
		if (shieldActive)
			spawnChance = 40;
		else
			spawnChance = 30;

		if (rand() % spawnChance == 0)
			spawnFireball(enemyX[i], enemyY[i] + enemyHeight / 2, false);
	}
}

// ================= Collision ===================
extern double enemyX[], enemyY[], enemyWidth, enemyHeight;
extern bool enemyVisible[];
extern int score;

void checkCrystalCollision() {
	for (int i = 0; i < MAX_CRYSTALS; i++) {
		if (!crystalVisible[i]) continue;

		bool collided = (playX + playerWidth >=crystalX[i] && playX <=crystalX[i] + 40 &&playY + playerHeight >= crystalY[i] && playY <= crystalY[i] + 40);
		if (collided) {
			shieldActive = true;
			shieldTimer = SHIELD_DURATION;
			crystalVisible[i] = false;
			crystalX[i] = 800 + rand() % 400;
			crystalY[i] = groundY + 120 + rand() % 200;
			health += 2;
		}
	}
}

double sq(double v) 
{ 
	return v * v;
}

void checkFireballCollision() {
	for (int i = 0; i < MAX_FIREBALLS; i++) {
		if (!fireballVisible[i]) continue;

		// --- Shield reflection ---
		if (shieldActive) {
			double fx = fireballX[i] + fireballWidth / 2;  //fireball center
			double fy = fireballY[i] + fireballHeight / 2; //fireball center
			double dx = fx - shieldX;  
			double dy = fy - shieldY;
			double distance = sqrt(dx*dx + dy*dy);
			double fireballRadius = fireballWidth / 2;

			if (distance <= shieldRadius + fireballRadius) {
				fireballToRight[i] = !fireballToRight[i];
				reflected[i] = true;
				fireballOwner[i] = PLAYER_FIREBALL;

				double angle = atan2(dy, dx);
				double speed = 0.5;
				fireballDY[i] = speed * sin(angle);
				fireballSpeed[i] = speed;

				if (fireballToRight[i])
					fireballX[i] = shieldX + shieldRadius + 1;
				else
					fireballX[i] = shieldX - shieldRadius - fireballWidth - 1;
				
				continue;
			}
		}

		// --- Player collision ---
		if (fireballX[i] < playX + playerWidth && fireballX[i] + fireballWidth > playX &&fireballY[i] < playY + playerHeight && fireballY[i] + fireballHeight > playY) {
			health -= 1;
			fireballVisible[i] = false;
			reflected[i] = false;
			continue;
		}

		// --- Enemy hit by reflected fireball ---
		if (reflected[i] && fireballOwner[i] == PLAYER_FIREBALL) {
			for (int e = 0; e < MAX_ENEMIES; e++) {
				if (!enemyVisible[e]) continue;

				if (fireballX[i] < enemyX[e] + enemyWidth && fireballX[i] + fireballWidth > enemyX[e] &&
					fireballY[i] < enemyY[e] + enemyHeight && fireballY[i] + fireballHeight > enemyY[e]) {
					enemyVisible[e] = false;
					fireballVisible[i] = false;
					reflected[i] = false;
					score += 2;
					break;
				}
			}
		}
	}
}

// ================= Shield Timer ===================
void updateShieldTimer() {
	if (shieldActive) {
		shieldTimer--;
		if (shieldTimer <= 0) shieldActive = false;
	}
}

#endif
