#ifndef LEVEL2_HPP
#define LEVEL2_HPP

// Level 2 Flags & Variables
bool level2Complete = false;
bool showLevel2NextButton = false;
bool level2CompletedPopup = false; // separate popup flag
extern bool shieldActive;

extern int health, score, coin;
extern int movePipeTimerID, moveCoinTimerID, enemyTimerID, enemyAutoFireballID;
extern int moveFireballsTimerID, moveCrystalsTimerID;
extern bool gameOver, showTryAgainButton;
extern int fireballcollisiontimer, mysteryboxcollision, crystalcollision, sheildtimerid, mysteryboxtimer;
void level2CompleteCheck()
{
	if (!level2Complete && coin >= 5 && score >= 5)
	{
		level2Complete = true;
		levelCompleted = true;
		showLevel2NextButton = true;
		level2CompletedPopup = true;

		// Pause Level 2 gameplay timers
		iPauseTimer(movePipeTimerID);
		iPauseTimer(moveCoinTimerID);
		iPauseTimer(enemyTimerID);
		
		iPauseTimer(moveCrystalsTimerID);
		iPauseTimer(moveFireballsTimerID);
		iPauseTimer(enemyAutoFireballID);
		iPauseTimer(fireballcollisiontimer);
		iPauseTimer(crystalcollision);
		iPauseTimer(sheildtimerid);
	}
}

void updateLevel2();

void updateLevel2()
{
	if (page == 10)
	{
		level2CompleteCheck();
	}

}


#endif
