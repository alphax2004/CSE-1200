#ifndef PLAYER_HPP
#define PLAYER_HPP
#define MAX_PIPES 4

//value in imain.cpp
extern bool levelCompleted;

bool boySelected = true;
bool girlSelected = false;

int rightFlag = 0, leftFlag = 0;

double playX = 160;
double playY = 145;
bool isjumping = false;
double jumpvelo = 0.0;

const double deltatime = 1.0 / 350.0;

int onPipeIndex = -1;
bool onPipe = false;
bool isStandingStillOnPipe = false;


double pipeX[MAX_PIPES];
double pipeY[MAX_PIPES];
//value in pipe.h
extern double pipeMoveDir[MAX_PIPES];

int groundY = 145;
int pipeWidth = 200;
int pipeHeight = 40;
int framecounter = 0;
int direction = 1;


void checkPipeCollision() {
	if (levelCompleted) return;
	onPipe = false;
	onPipeIndex = -1;
	isStandingStillOnPipe = false;

	for (int i = 0; i < MAX_PIPES; i++) {
		if (playX + 110 >= pipeX[i]-5 && playX <= pipeX[i] + pipeWidth) {
			if (abs(playY - (pipeY[i] + pipeHeight)) <= 10) {
				onPipe = true;
				onPipeIndex = i;
				if (!leftFlag && !rightFlag)
					isStandingStillOnPipe = true;
				return;
			}
		}
	}
}

void applyGravity() {
	
	if (!isjumping) {
		checkPipeCollision();

		if (onPipe) {
			if (isStandingStillOnPipe && onPipeIndex != -1) {
				playX += pipeMoveDir[onPipeIndex]; 
				playY = pipeY[onPipeIndex] + pipeHeight-10; // Player moves with pipe if standing still
			}
		}
		else {
			playY -= 6;
			bool landed = false;

			for (int i = 0; i < MAX_PIPES; i++) {
				if (playX + 110 >= pipeX[i] && playX <= pipeX[i] + pipeWidth &&
					abs(playY - (pipeY[i] + pipeHeight)) <= 5) {
					playY = pipeY[i] + pipeHeight-12;
					onPipe = true;
					onPipeIndex = i;
					landed = true;
					break;

				}
			}

			if (!landed && playY <= groundY) {
				playY = groundY;
				onPipe = false;
				onPipeIndex = -1;
			}
		}
	}
	
}


void characterjump() {
	if (isjumping) {
		playY += jumpvelo * deltatime;
		jumpvelo -= (250 * deltatime);

		// Show jump animation
		if (direction == 1) {
			if (boySelected)
				iShowImage(playX, playY, 110, 120, runSprite[0]);
			else if (girlSelected)
				iShowImage(playX, playY, 110, 120, girlRun[0]);
		}
		else {
			if (boySelected)
				iShowImage(playX, playY, 110, 120, runleft[0]);
			else if (girlSelected)
				iShowImage(playX, playY, 110, 120, girlLeft[0]);
		}

		if (jumpvelo < 0) {
			for (int i = 0; i < MAX_PIPES; i++) {
				if (playY >= pipeY[i] + pipeHeight && playY + jumpvelo * deltatime <= pipeY[i] + pipeHeight &&
					playX + 110 >= pipeX[i] && playX <= pipeX[i] + pipeWidth) {
					playY = pipeY[i] + pipeHeight-10;
					isjumping = false;
					jumpvelo = 0;
					onPipeIndex = i;
					return;
				}
			}

			if (playY <= groundY) {
				playY = groundY;
				isjumping = false;
				jumpvelo = 0;
				onPipeIndex = -1;
			}
		}
	}
	else {
		applyGravity();
	}
}

void charactermove()
{
	if (levelCompleted) return;
	checkPipeCollision();

	int currentFrame = (framecounter / 90) % 6;

	if (rightFlag)
	{
		playX += 0.3;
		direction = 1;

		if (boySelected)
			iShowImage(playX, playY, 110, 120, runSprite[currentFrame]); // boy right run
		else
			iShowImage(playX, playY, 110, 135, girlRun[currentFrame]);   // girl right run
	}
	else if (leftFlag)
	{
		playX -= 0.5;
		direction = 0;

		if (boySelected)
			iShowImage(playX, playY, 110, 120, runleft[currentFrame]); // boy left run
		else
			iShowImage(playX, playY, 110, 135, girlLeft[currentFrame]); // girl left run
	}
	else
	{
		if (direction == 1) // facing right
		{
			if (boySelected)
				iShowImage(playX, playY, 110, 120, runSprite[0]); // boy idle right
			else
				iShowImage(playX, playY, 110, 135, girlRun[0]);   // girl idle right
		}
		else // facing left
		{
			if (boySelected)
				iShowImage(playX, playY, 110, 120, runleft[0]); // boy idle left
			else
				iShowImage(playX, playY, 110, 135, girlLeft[0]); // girl idle left
		}
	}

	// Boundary touch
	if (playX < 0) playX = 0;
	if (playX > 1280 - 10) playX = 1280 - 110;

	framecounter++;
}


#endif