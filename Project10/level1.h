#ifndef LEVEL1_HPP
#define LEVEL1_HPP

//-------------------- Level 1 Flags & Variables --------------------//

bool levelComplete = false;        // level complete flag
bool showNextButton = false;       // next button show flag


// Timer IDs (must be global to pause/resume)
int updateTimerID, movePipeTimerID, moveCoinTimerID, enemyTimerID;

bool gameOver = false;          // Triggered when health <= 0
bool showTryAgainButton = false; // Show Try Again button
extern int health, score;

extern void updateLevel2();
extern void level2CompleteCheck();
extern void updateLevel3();

extern int movePipeTimerID, moveCoinTimerID, enemyTimerID, enemyAutoFireballID;
extern int moveFireballsTimerID, moveCrystalsTimerID;
extern int fireballcollisiontimer, mysteryboxcollision, crystalcollision, sheildtimerid, mysteryboxtimer;
void level11()
{
	if (!levelComplete && coin >= 2 && score >= 2)
	{
		levelComplete = true;
		levelCompleted = true;
		showNextButton = true;
	}
}

void update()
{
	if (page == 3) {
		level11(); // Level 1 completion
	}
	else if (page == 10) {
		updateLevel2(); // Level 2 completion
	}
	else if (page == 14) {
		updateLevel3();
	}

	// Game Over Logic
	if ((page == 3 || page == 10 || page == 14) && health <= 0 && !gameOver)
	{
		gameOver = true;
		showTryAgainButton = true;

		// Pause all timers
		
		iPauseTimer(movePipeTimerID);
		iPauseTimer(moveCoinTimerID);
		iPauseTimer(enemyTimerID);
		iPauseTimer(moveFireballsTimerID);
		iPauseTimer(moveCrystalsTimerID);
		iPauseTimer(enemyAutoFireballID);
		iPauseTimer(fireballcollisiontimer);
		iPauseTimer(crystalcollision);
		iPauseTimer(sheildtimerid);
	}
}









#endif
