#ifndef PAUSE_HPP
#define PAUSE_HPP


bool gamePaused = false;
int pauseBtnX = 1160, pauseBtnY = 600, pauseBtnW = 70, pauseBtnH = 70; // Pause button coordinate

void togglePause()
{
	gamePaused = !gamePaused;

	if (gamePaused)
	{
		// Pause gameplay timers
		if (updateTimerID) iPauseTimer(updateTimerID);
		if (movePipeTimerID) iPauseTimer(movePipeTimerID);
		if (moveCoinTimerID) iPauseTimer(moveCoinTimerID);
		if (enemyTimerID) iPauseTimer(enemyTimerID);
		if (moveCrystalsTimerID) iPauseTimer(moveCrystalsTimerID);
		if (moveFireballsTimerID) iPauseTimer(moveFireballsTimerID);
		if (enemyAutoFireballID) iPauseTimer(enemyAutoFireballID);
		if (fireballcollisiontimer) iPauseTimer(fireballcollisiontimer);
		if (crystalcollision) iPauseTimer(crystalcollision);
		if (sheildtimerid) iPauseTimer(sheildtimerid);
		if (mysteryboxtimer) iPauseTimer(mysteryboxtimer);
		if (mysteryboxcollision) iPauseTimer(mysteryboxcollision);
	}
	else
	{
		// Resume timers instead of creating new timers
		if (updateTimerID) iResumeTimer(updateTimerID);
		if (movePipeTimerID) iResumeTimer(movePipeTimerID);
		if (moveCoinTimerID) iResumeTimer(moveCoinTimerID);
		if (enemyTimerID) iResumeTimer(enemyTimerID);
		if (moveCrystalsTimerID) iResumeTimer(moveCrystalsTimerID);
		if (moveFireballsTimerID) iResumeTimer(moveFireballsTimerID);
		if (enemyAutoFireballID) iResumeTimer(enemyAutoFireballID);
		if (fireballcollisiontimer) iResumeTimer(fireballcollisiontimer);
		if (crystalcollision) iResumeTimer(crystalcollision);
		if (sheildtimerid) iResumeTimer(sheildtimerid);
		if (mysteryboxtimer) iResumeTimer(mysteryboxtimer);
		if (mysteryboxcollision) iResumeTimer(mysteryboxcollision);
	}
}

void drawPauseButton();

void drawPauseButton()
{
	if (gamePaused)
		iShowImage(pauseBtnX, pauseBtnY, pauseBtnW, pauseBtnH, resumeIcon); // Show resume icon
	else
		iShowImage(pauseBtnX, pauseBtnY, pauseBtnW, pauseBtnH, pauseIcon); // Show pause icon
}












#endif