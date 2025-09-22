#include "iGraphics.h"
#include "pages.h"
#include "Ui_elements.h"
#include "player.h"
#include "coins.h"
#include "pipe.h"
#include "animation.h"
#include "mystery.h"
#include "enemy.h"
#include "level1.h"
#include "level2.h"
#include"level3.h"
#include"game_logic.h"
#include"bullet.h"
#include"reset.h"
#include"draw.h"
#include"timer.h"
#include"pause.h"
#include "music.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int level3timer;

double pipeMoveDir[MAX_PIPES]; 
int boyPopupX = 180, girlPopupX = 650;
int boyPopupY = -300, girlPopupY = -300;
bool popupAnimationRunning = false;
bool levelCompleted = false;

int fireballcollisiontimer, mysteryboxcollision, crystalcollision, sheildtimerid, mysteryboxtimer;
 

void playClickSound()
{
	PlaySound("music/button_click.wav", NULL, SND_ASYNC | SND_FILENAME);
}

void iDraw()
{
	iClear();

	switch (page) {
	case 0: page0(); break;
	case 1: page1(); break;
	case 2: page2(); break;
	case 3: page3(); break;
	case 4: page4(); break;
	case 5: page5(); break;
	case 6: page6(); break;
	case 7: page7(); break;
	case 8: page8(); break;
	case 9: page9(); break;
	case 10: page10(); break;
	case 11: page11(); break;
	case 12: page12(); break;
	case 13: page13(); break;
	case 14: page14(); break;
	case 15: page15(); break;
	case 16: page16(); break;
	default: break;
	}
	drawMusicButton();

}



/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d\n", mx, my);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= musicBtnX && mx <= musicBtnX + musicBtnW &&
			my >= musicBtnY && my <= musicBtnY + musicBtnH)
		{
			toggleMusic(); // Turn music ON/OFF
			return;        // Stop here, don't process other clicks
		}
		if (mx >= pauseBtnX && mx <= pauseBtnX + pauseBtnW &&
			my >= pauseBtnY && my <= pauseBtnY + pauseBtnH)
		{
			togglePause();
			return;
		}
		if (page == 2)
		{
			if (mx >= 500 && mx <= 800 && my >= 500 && my <= 650) // START button
			{
				playClickSound();
				page = 13; // Level selection
				popupAnimationRunning = false;

				// Reset Level 1 and Level 2 animation vars
				levelTextY = -200;
				showContinueText = false;
				showForestBackground = false;

				level2TextY = -200;
				showLevel2ContinueText = false;
				showLevel2Forest = false;

				level3TextY = -200;
				showLevel3ContinueText = false;
				showLevel3Forest = false;

				// Pause all level popup timers
				if (levelPopupTimerID) { iPauseTimer(levelPopupTimerID); levelPopupTimerID = 0; }
				if (level2PopupTimerID){ iPauseTimer(level2PopupTimerID); level2PopupTimerID = 0; }

				if (level3PopupTimerID){ iPauseTimer(level3PopupTimerID); level3PopupTimerID = 0; }
				return;
			}
			else if (mx >= 500 && mx <= 800 && my >= 400 && my <= 550)
			{
				playClickSound();
				page = 4;
			}
			else if (mx >= 500 && mx <= 800 && my >= 300 && my <= 380)
			{
				playClickSound();
				page = 5;
			}
			else if (mx >= 500 && mx <= 800 && my >= 200 && my <= 280)
			{
				playClickSound();
				page = 6;
			}
			else if (mx >= 500 && mx <= 800 && my >= 100 && my <= 260)
			{

				playClickSound();
				page = 7;
				popupAnimationRunning = true;
				boyPopupY = -300;
				girlPopupY = -300;
			}
			else if (mx >= 500 && mx <= 800 && my >= 50 && my <= 250) // Character Button
			{
				exit(0);
			}
		}

		// ::::: Page 3-6: Back Button
		if (page == 3 || page == 4 || page == 5 || page == 6)
		{
			if (mx >= 50 && mx <= 200 && my >= 50 && my <= 110)
			{
				playClickSound();
				page = 2;
			}

			if (mx >= 1140 && mx <= 1240 && my >= 660 && my <= 760)
			{
				playClickSound();
				showExitDialog = true;  // Dialog show
			}
		}

		if (page == 10)
		{
			if (mx >= 1140 && mx <= 1240 && my >= 660 && my <= 760) // home button er coordinate
			{
				playClickSound();
				showExitDialog = true; // Dialog show
			}
		}


		if (showExitDialog && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			// YES button
			if (mx >= yesButtonX && mx <= yesButtonX + yesButtonW && my >= yesButtonY && my <= yesButtonY + yesButtonH)
			{
				playClickSound();
				showExitDialog = false;

				page = 13; // Main menu

				//prevoius activate timers stop,backgroud stop,continue stop
				levelTextY = -200;
				showContinueText = false;
				showForestBackground = false;
				level2TextY = -200;
				showLevel2ContinueText = false;
				showLevel2Forest = false;

				level3TextY = -200;
				showLevel3ContinueText = false;
				showLevel3Forest = false;

				if (levelPopupTimerID != 0) {
					iPauseTimer(levelPopupTimerID);
					levelPopupTimerID = 0;
				}

				//again start after entering
				if (level2PopupTimerID != 0) {
					iPauseTimer(level2PopupTimerID);
					level2PopupTimerID = 0;
				}
				if (level3PopupTimerID != 0) {
					iPauseTimer(level3PopupTimerID);
					level3PopupTimerID = 0;
				}
			}

			// NO button
			if (mx >= noButtonX && mx <= noButtonX + noButtonW && my >= noButtonY && my <= noButtonY + noButtonH)
			{
				playClickSound();
				showExitDialog = false; // Close dialog, continue game
			}
		}

		if (levelComplete && showNextButton)
		{
			int nextBtnX = 5;
			int nextBtnY = 0;
			int nextBtnW = 250;
			int nextBtnH = 150;

			if (mx >= nextBtnX && mx <= nextBtnX + nextBtnW &&
				my >= nextBtnY && my <= nextBtnY + nextBtnH)
			{
				
				iPauseTimer(movePipeTimerID);
				iPauseTimer(moveCoinTimerID);
				iPauseTimer(enemyTimerID);
			
				startLevel(2);				
			}
		}
		if (level2Complete && showLevel2NextButton) {
			int nextBtnX = 5, nextBtnY = 0, nextBtnW = 250, nextBtnH = 150;
			if (mx >= nextBtnX && mx <= nextBtnX + nextBtnW && my >= nextBtnY && my <= nextBtnY + nextBtnH){
				level2Complete = false;
				showLevel2NextButton = false;
				levelCompleted = false;
				level2CompletedPopup = false;
	
				// Pause level 2 gameplay timers    
				iPauseTimer(movePipeTimerID);
				iPauseTimer(moveCoinTimerID);
				iPauseTimer(enemyTimerID);
				iPauseTimer(updateTimerID);
				iPauseTimer(moveCrystalsTimerID);
				iPauseTimer(moveFireballsTimerID);
				iPauseTimer(enemyAutoFireballID);
				iPauseTimer(fireballcollisiontimer);
				iPauseTimer(crystalcollision);
				iPauseTimer(sheildtimerid);
				
				startLevel(3);
			
			}
		}

		else if (level3Complete && showLevel3NextButton)
		{
			int nextBtnX = 5;
			int nextBtnY = 0;
			int nextBtnW = 250;
			int nextBtnH = 150;

			if (mx >= nextBtnX && mx <= nextBtnX + nextBtnW &&
				my >= nextBtnY && my <= nextBtnY + nextBtnH)
			{

				page = 2;  // Level selection or next level

				// Reset Level 2 popup states
				level3Complete = false;
				showLevel3NextButton = false;

				// Pause all Level 2 gameplay timers
				iPauseTimer(movePipeTimerID);
				iPauseTimer(moveCoinTimerID);
				iPauseTimer(enemyTimerID);

				if (level3PopupTimerID) iPauseTimer(level3PopupTimerID);

			}
		}
		//function true check from level1.h gameover=true and showtryagain=true of void update()
		if (gameOver && showTryAgainButton)
		{
			int btnWidth = 250, btnHeight = 80;
			int btnX = (1280 - btnWidth) / 2;  //ekdom center borabor
			int btnY = (780 - 300) / 2 - 100; // same as drawing Y center borabor

			if (mx >= btnX && mx <= btnX + btnWidth && my >= btnY && my <= btnY + btnHeight)
			{
				playClickSound();

				int currentPage = page;
				gameOver = false;
				showTryAgainButton = false;

				if (currentPage == 3)   // Level 1 gameplay page
				{
					page = 3; // ensure gameplay page
					health = 5; coin = 0; score = 0;
					levelCompleted = false;
					shieldActive = false;

					leveltimer1();
				}
				else if (currentPage == 10) // Level 2 gameplay page
				{
					page = 10;
					health = 5; coin = 0; score = 0;
					levelCompleted = false;
					shieldActive = false;
					leveltimer2();
				}
				else if (currentPage == 14) // Level 3 gameplay page
				{
					page = 14;
					health = 5; coin = 0; score = 0;
					levelCompleted = false;

					leveltimer3();
				}
			}
		}
		// Character Selection Page (Page 7)
		if (page == 7)
		{
			// Back Button
			if (mx >= 50 && mx <= 200 && my >= 50 && my <= 110)
			{
				playClickSound();
				page = 2;
			}

			if (!popupAnimationRunning) // Only allow selection after animation ends
			{
				// Boy Selection
				if (mx >= 300 && mx <= 600 && my >= boyPopupY && my <= boyPopupY + 420)
				{
					playClickSound();
					boySelected = true;
					girlSelected = false;
					popupAnimationRunning = true;
					boyPopupY = -300;
					girlPopupY = -300;
					page = 2;
				}
				// Girl Selection
				else if (mx >= 600 && mx <= 900 && my >= girlPopupY && my <= girlPopupY + 420)
				{
					playClickSound();
					boySelected = false;
					girlSelected = true;
					popupAnimationRunning = true;
					boyPopupY = -300;
					girlPopupY = -300;
					page = 2;
				}
			}
		}
		if (page == 13)
		{
			// Level 1 image click
			if (mx >= 380 && mx <= 380 + 400 && my >= 400 && my <= 400 + 300)
			{
				playClickSound();
				
				page = 8; // Level 1 popup

				startLevel(1);
			}
		}
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == '\r') {}

	if (key == 'f' || key == 'F') {
		printf("f pressed cooldown = %d\n", cooldown);
		if (cooldown == 0) {
			spawnbullet();
			cooldown = 8;
		}
	}

	if (key == ' ')
	{
		// Pause all gameplay timers before starting new ones
		pauseAllTimers();

		// ---------- Handle page changes ----------

		if (page == 0) page = 1;
		else if (page == 1) page = 2;

		else if (page == 8 && showForestBackground && showContinueText) page = 11;

		else if (page == 11) // Level 1 gameplay
		{
			page = 3;
			health = 5; coin = 0; score = 0; levelCompleted = false; shieldActive = false;

			leveltimer1();

			
		}

		else if (page == 9 && showLevel2Forest && showLevel2ContinueText) page = 12;

		else if (page == 12) // Level 2 gameplay
		{
			page = 10;
			health = 5; coin = 0; score = 0; levelCompleted = false; shieldActive = false;

			leveltimer2();

			
		}

		else if (page == 15 && showLevel3Forest && showLevel3ContinueText) page = 16;

		else if (page == 16) // Level 3 gameplay
		{
			page = 14;
			health = 5; coin = 0; score = 0; levelCompleted = false;

			leveltimer3();

			
		}
	}
}


/*
function iSpecialKeyboard() is called whenver user hits special keys like-function keys, home, end, pg up, pg down, arraows etc. you have to useappropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (reverseControl)
	{
		// Swap left/right movement
		if (key == GLUT_KEY_RIGHT) leftFlag = 1;
		if (key == GLUT_KEY_LEFT) rightFlag = 1;
	}
	else
	{
		if (key == GLUT_KEY_RIGHT)
		{
			direction = 1;
			rightFlag = 1;
		}
		if (key == GLUT_KEY_LEFT)
		{
			direction = -1;
			leftFlag = 1;
		}

	}
	if (key == GLUT_KEY_UP)
	{
		if (!isjumping)
		{
			isjumping = true;
			jumpvelo = 400.0;
		}
	}
}
void specialKeyUp(int key, int x, int y)
{
	if (reverseControl)
	{
		if (key == GLUT_KEY_RIGHT) leftFlag = 0;
		if (key == GLUT_KEY_LEFT) rightFlag = 0;
	}
	else
	{
		if (key == GLUT_KEY_RIGHT) rightFlag = 0;
		if (key == GLUT_KEY_LEFT) leftFlag = 0;
	}
}

int popupanimationtimer, popupanimation2timer;

int main()
{
	srand((unsigned)time(NULL));
	///srand((unsigned)time(NULL));
	
	playBackgroundMusic();
	iInitialize(1280, 780, "Colorland Heroes");

	loadimage();
	enemyimage();
	gameNameImage = iLoadImage("images/gamename2.png");
	popupanimationtimer=iSetTimer(16, popupAnimation);
	popupanimation2timer = iSetTimer(16, popupAnimation2);

	initPipes();
	initCoins();
	initEnemies();
	initCrystals();
	initFireballs();
	inibullet();
	glutSpecialUpFunc(specialKeyUp); // Enable key release handling
	
	iStart();
	return 0;
}