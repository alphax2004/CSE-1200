#ifndef LEVEL3_HPP
#define LEVEL3_HPP

//-------------------- Level 2 Flags & Variables --------------------//
bool level3Complete = false;
extern bool gameOver;
bool showLevel3NextButton = false;
extern int  movePipeTimerID, moveCoinTimerID, enemyTimerID;
extern int moveFireballsTimerID;
extern int moveCrystalsTimerID;
extern int health, score, coin;

void level3CompleteCheck()
{
	// Example condition: coin >= 5 && score >= 5 (adjust as needed)
	if (!level3Complete && coin >= 5 && score >= 5)
	{
		level3Complete = true;
		levelCompleted = true;  // reuse global variable to show popup
		showLevel3NextButton = true;
	}
}
void updateLevel3();

void updateLevel3()
{
	if (page == 14)
	{
		level3CompleteCheck();
	}

	if (page == 14 && health <= 0 && !gameOver)
	{
		gameOver = true;
		showTryAgainButton = true;

		// Pause gameplay timers
		iPauseTimer(movePipeTimerID);
		iPauseTimer(moveCoinTimerID);
		iPauseTimer(enemyTimerID);
		
	}
}

#endif
