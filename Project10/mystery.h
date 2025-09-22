#ifndef MYSTERY_HPP
#define MYSTERY_HPP

extern int health;
extern bool levelCompleted;

double boxX = 1400, boxY = 200; // start off-screen
bool boxActive = false;
bool reverseControl = false;

int boxSpawnTimer = 0;
int reverseTimer = 0;

void spawnMysteryBox()
{
	if (!boxActive && boxSpawnTimer >= 6)  // 60 seconds
	{
		boxX = 1280; // spawn from right edge
		boxY = 150 + rand() % 300; // random height
		boxActive = true;
		boxSpawnTimer = 0;
	}
}
double boxspeed = 0.3;
void moveMysteryBox()
{
	if (levelCompleted) return;
	if (boxActive)
	{
		boxX -= boxspeed; // move left
		if (boxX < -50) // went off screen
		{
			boxActive = false;
		}
	}
}

void showMysteryBox()
{
	if (boxActive)
	{
		iShowImage(boxX, boxY, 50, 50, mysteryBoxImg);
	}
}

void checkMysteryBoxCollision()
{
	if (levelCompleted) return;
	if (boxActive)
	{
		if (playX + 50 > boxX && playX < boxX + 50 &&
			playY + 50 > boxY && playY < boxY + 50)
		{
			health += 1;
			reverseControl = true;
			reverseTimer = 0;
			boxActive = false;
		}
	}
}

void updateTimers()
{
	static int lastTime = time(0);
	int currentTime = time(0);
	if (currentTime != lastTime)
	{
		lastTime = currentTime;
		boxSpawnTimer++;
		if (reverseControl)
		{
			reverseTimer++;
			if (reverseTimer >= 10) // 10 seconds reverse control
			{
				reverseControl = false;
			}
		}
	}
}



#endif