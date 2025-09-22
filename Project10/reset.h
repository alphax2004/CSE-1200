#ifndef RESET_HPP
#define RESET_HPP

extern bool showExitDialog;

bool level1PopupRunning = false;
bool level2PopupRunning = false;
bool level3PopupRunning = false;
extern int fireballcollisiontimer, mysteryboxcollision, crystalcollision, sheildtimerid, mysteryboxtimer;
void pauseAllTimers()
{
	//if (updateTimerID) { iPauseTimer(updateTimerID); updateTimerID = 0; }
	if (movePipeTimerID) { iPauseTimer(movePipeTimerID); movePipeTimerID = 0; }
	if (moveCoinTimerID) { iPauseTimer(moveCoinTimerID); moveCoinTimerID = 0; }
	if (enemyTimerID) { iPauseTimer(enemyTimerID); enemyTimerID = 0; }
	if (moveCrystalsTimerID) { iPauseTimer(moveCrystalsTimerID); moveCrystalsTimerID = 0; }
	if (moveFireballsTimerID) { iPauseTimer(moveFireballsTimerID); moveFireballsTimerID = 0; }
	if (enemyAutoFireballID) { iPauseTimer(enemyAutoFireballID); enemyAutoFireballID = 0; }
	if (fireballcollisiontimer) { iPauseTimer(fireballcollisiontimer); fireballcollisiontimer = 0; }
	if (crystalcollision) { iPauseTimer(crystalcollision); crystalcollision = 0; }
	if (sheildtimerid) { iPauseTimer(sheildtimerid); sheildtimerid = 0; }
	if (mysteryboxtimer) { iPauseTimer(mysteryboxtimer); mysteryboxtimer = 0; }
	if (mysteryboxcollision) { iPauseTimer(mysteryboxcollision); mysteryboxcollision = 0; }
	if (levelPopupTimerID) { iPauseTimer(levelPopupTimerID); levelPopupTimerID = 0; }
	if (level2PopupTimerID) { iPauseTimer(level2PopupTimerID); level2PopupTimerID = 0; }
	if (level3PopupTimerID) { iPauseTimer(level3PopupTimerID); level3PopupTimerID = 0; }
}




void startLevel(int level)
{
	pauseAllTimers();   // <-- everything paused first

	// Reset player/game statea
	playX = 100; playY = groundY;
	health = 5; coin = 0; score = 0;
	isjumping = false; leftFlag = rightFlag = direction = 0;
	gameOver = levelComplete = levelCompleted = false;
	shieldActive = false; popupAnimationRunning = true;
	levelTextY = -200; showContinueText = false; showForestBackground = false;
	level2TextY = -200; showLevel2ContinueText = false; showLevel2Forest = false;
	level3TextY = -200; showLevel3ContinueText = false; showLevel3Forest = false;

	switch (level)
	{
	case 1:
		page = 8; level1PopupRunning = true;
		showContinueText = true;
		showForestBackground = true;
		levelPopupTimerID = iSetTimer(20, level1PopupAnimation);
		break;
	case 2:
		page = 9; level2PopupRunning = true;
		showLevel2ContinueText = true;
		showLevel2Forest = true;
		level2PopupTimerID = iSetTimer(20, level2PopupAnimation);
		break;
		
	case 3:
		page = 15; level3PopupRunning = true;
		showLevel3ContinueText = true;
		showLevel3Forest = true;
		level3PopupTimerID = iSetTimer(20, level3PopupAnimation);
		break;
		
	}
}




#endif