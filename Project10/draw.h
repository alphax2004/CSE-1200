#ifndef DRAW_HPP
#define DRAW_HPP
#include"pause.h"
#include"music.h"

bool showLevel2ContinueText = false;
bool showLevel2Forest = false;
int level2PopupTimerID;
const double level2PopupSpeed = 20.0;
int level2TextY = -200;

bool showLevel3ContinueText = false;
bool showLevel3Forest = false;
int level3PopupTimerID;

int level3TextY = -200;
int moveFireballsTimerID, enemyAutoFireballID;
int moveCrystalsTimerID;

int health = 5;
int coin = 0;
int score = 0;
char txt[30];
//extern bool Music ;

bool showExitDialog = false;  // Dialog

// Dialog box position
int dialogX = 350, dialogY = 250;

// YES / NO click area
int yesButtonX = 506, yesButtonY = 437, yesButtonW = 100, yesButtonH = 50;
int noButtonX = 659, noButtonY = 437, noButtonW = 100, noButtonH = 50;



void page0()
{
	iShowImage(0, 0, 1280, 780, gamename);

	gamenameanimation();
	iShowImage(400, 100, 420, 130, press);

	iSetColor(255, 255, 255);
	iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
}
void page1()
{
	iShowImage(0, 0, 1280, 780, storypage);

	for (int i = 0; i < 5; i++)
		iShowImage(90, 550 - i * 60, 950, 150, storybutton);

	showstory();
	iShowImage(400, 100, 420, 130, press);
	iSetColor(255, 255, 255);
	iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
}
void page2()
{
	iShowImage(0, 0, 1280, 780, startpage);

	for (int i = 0; i < 6; i++)
		iShowImage(500, 500 - i * 100, 300, 150, startpagebutton);

	showbuttons();
	characteranimation();

}
void page3()
{
	iShowImage(0, 0, 1280, 780, forest);
	drawPauseButton();

	iSetColor(0, 0, 0);

	sprintf_s(txt, "HEALTH : %d", health);
	iShowImage(20, 690, 140, 30, uibutton);
	iText(40, 700, txt, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(txt, "COINS : %d", coin);
	iShowImage(20, 640, 140, 30, uibutton);
	iText(40, 650, txt, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(txt, "SCORE : %d", score);
	iShowImage(20, 590, 140, 30, uibutton);
	iText(40, 600, txt, GLUT_BITMAP_HELVETICA_18);

	if (!gamePaused) // Pause check
	{
		showPipes();
		showCoins();
		showMysteryBox();
		spawnEnemy();
		showEnemies();
		movePipes();
		moveCoins();
		moveEnemies();
		moveMysteryBox();
		checkPipeCollision();
		characterjump();
		charactermove();
		checkCoinCollision();
		checkMysteryBoxCollision();
		checkEnemyCollision();
	}

	iShowImage(1140, 660, 100, 100, homeButtonImg);

	if (showExitDialog)
		iShowImage(dialogX, dialogY, 580, 500, exitDialogImg);

	if (levelComplete)
	{
		iShowImage(0, 0, 1280, 780, forest);
		int centerX = 180;
		int centerY = 0;
		iShowImage(centerX, centerY, 1000, 750, levelCompleteImage);

		if (showNextButton)
		{
			int nextBtnX = 5;
			int nextBtnY = 0;
			iShowImage(nextBtnX, nextBtnY, 250, 150, nextButtonImage);
			iSetColor(0, 0, 0);
			iText(80, 70, "NEXT", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (gameOver)
	{
		iShowImage(0, 0, 1280, 780, forest);
		int centerX = 110;
		int centerY = 100;
		iShowImage(centerX, centerY, 1110, 750, gameOverImage);

		if (showTryAgainButton)
		{
			int btnX = 550;
			int btnY = 50;
			iShowImage(btnX, btnY, 150, 150, nextButtonImage);
			iSetColor(0, 0, 0);
			iText(570, 119, "TRY AGAIN", GLUT_BITMAP_HELVETICA_18);
		}
	}
}

void page4()
{

	iShowImage(0, 0, 1280, 780, startpage);

	for (int i = 0; i < 5; i++)
		iShowImage(90, 550 - i * 60, 950, 150, storybutton);

	showinstructions();
	characteranimation();
}
void page5()
{
	iShowImage(0, 0, 1280, 780, storypage);
	showscorepage();
	characteranimation();
}
void page6()
{
	iShowImage(0, 0, 1280, 780, storypage);

	iShowImage(90, 490, 950, 150, storybutton);
	iShowImage(90, 430, 950, 150, storybutton);
	iShowImage(90, 370, 950, 150, storybutton);

	showcredits();//mainly back button show image function call at ui elements.h
	characteranimation();
}
void page7()
{
	iShowImage(0, 0, 1280, 780, storypage); // reused background

	// Animate popup
	if (popupAnimationRunning)
	{
		if (boyPopupY < 400) boyPopupY += 2;
		if (girlPopupY < 400) girlPopupY += 2;

		if (boyPopupY >= 400 && girlPopupY >= 400)
			popupAnimationRunning = false;
	}

	// Character Images
	iShowImage(300, boyPopupY - 90, 350, 450, characterBoyImage);   // Use loaded image
	iShowImage(650, girlPopupY - 90, 300, 420, characterGirlImage); // Use loaded image

	iShowImage(370, 550, 470, 300, charname);//choose your character image

	// Back button
	iShowImage(50, 50, 150, 60, backbutton);

	showscorepage(); // mainly bac
}
void page8()
{

	iShowImage(0, 0, 1280, 780, storypage); // Story base background


	// Show Level 1 popup animation
	iShowImage(380, levelTextY, 600, 350, level1Image); // popup

	// Forest background show after popup
	if (showForestBackground) {
		iShowImage(350, 230, 550, 350, frameforest); // NO animation
	}

	// Continue text
	if (showContinueText) {
		iShowImage(400, 100, 420, 130, press);
		iSetColor(255, 255, 255);
		iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}

}
void page9()
{
	iShowImage(0, 0, 1280, 780, storypage); // story background

	// Popup image level 2
	iShowImage(460, level2TextY, 300, 200, level2Image);

	//after popup animation of level 2 image
	if (showLevel2Forest)
		iShowImage(350, 210, 570, 350, framedesert);

	//continue text
	if (showLevel2ContinueText)
	{
		iShowImage(400, 100, 420, 130, press);
		iSetColor(255, 255, 255);
		iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
void page10()
{
	iShowImage(0, 0, 1280, 780, desert);
	drawPauseButton();

	iSetColor(0, 0, 0);
	sprintf_s(txt, "HEALTH : %d", health);
	iShowImage(20, 690, 140, 30, uibutton);
	iText(40, 700, txt, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(txt, "COINS : %d", coin);
	iShowImage(20, 640, 140, 30, uibutton);
	iText(40, 650, txt, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(txt, "SCORE : %d", score);
	iShowImage(20, 590, 140, 30, uibutton);
	iText(40, 600, txt, GLUT_BITMAP_HELVETICA_18);

	if (!gamePaused) // Pause check
	{
		showPipes();
		showCoins();
		spawnEnemy();
		showEnemies();
		showCrystals();
		drawShield();
		showFireballs();
		movePipes();
		moveCoins();
		moveEnemies();
		moveCrystals();
		moveFireballs();
		enemyAutoFireball();
		checkPipeCollision();
		charactermove();
		characterjump();
		checkCoinCollision();
		checkMysteryBoxCollision();
		checkEnemyCollision();
		checkCrystalCollision();
		checkFireballCollision();
		updateShieldTimer();
		updateShieldPosition();
	}

	iShowImage(1140, 660, 100, 100, homeButtonImg);

	if (showExitDialog)
		iShowImage(dialogX, dialogY, 580, 500, exitDialogImg);

	if (level2Complete)
	{
		iShowImage(0, 0, 1280, 780, desert);
		int centerX = 180;
		int centerY = 0;
		iShowImage(centerX, centerY, 1000, 750, levelCompleteImage);

		if (showLevel2NextButton)
		{
			int nextBtnX = 5;
			int nextBtnY = 0;
			iShowImage(nextBtnX, nextBtnY, 250, 150, nextButtonImage);
			iSetColor(0, 0, 0);
			iText(80, 70, "NEXT", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (gameOver)
	{
		iShowImage(0, 0, 1280, 780, desert);
		int centerX = 110;
		int centerY = 100;
		iShowImage(centerX, centerY, 1110, 750, gameOverImage);

		if (showTryAgainButton)
		{
			int btnX = 550;
			int btnY = 50;
			iShowImage(btnX, btnY, 150, 150, nextButtonImage);
			iSetColor(0, 0, 0);
			iText(570, 119, "TRY AGAIN", GLUT_BITMAP_HELVETICA_18);
		}
	}
}

void page11()
{
	iShowImage(0, 0, 1280, 780, storypage);
	iShowImage(200, 100, 900, 700, instructionImg);

	iShowImage(400, 100, 420, 130, press);
	iSetColor(255, 255, 255);
	iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
}
void page12()
{

	iShowImage(0, 0, 1280, 780, storypage);
	iShowImage(200, 100, 900, 700, instructionImg);

	iShowImage(400, 100, 420, 130, press);
	iSetColor(255, 255, 255);
	iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
}
void page13()
{
	iShowImage(0, 0, 1280, 780, storypage); // Background
	// Level 1 Image
	iShowImage(150, 280, 760, 430, level1Image);
	// Level 2 Image
	iShowImage(650, 400, 400, 300, level2Image);
	iShowImage(450, 200, 440, 260, level3image);
	iShowImage(400, 550, 420, 130, press);
	iSetColor(255, 255, 255);
	iText(530, 610, "SELECT LEVEL", GLUT_BITMAP_TIMES_ROMAN_24);
}
void page14()
{
	iShowImage(0, 0, 1280, 780, ice);
	drawPauseButton();

	iSetColor(0, 0, 0);
	sprintf_s(txt, "HEALTH : %d", health);
	iShowImage(20, 690, 140, 30, uibutton);
	iText(40, 700, txt, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(txt, "COINS : %d", coin);
	iShowImage(20, 640, 140, 30, uibutton);
	iText(40, 650, txt, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(txt, "SCORE : %d", score);
	iShowImage(20, 590, 140, 30, uibutton);
	iText(40, 600, txt, GLUT_BITMAP_HELVETICA_18);

	if (!gamePaused) // Pause check
	{
		showPipes();
		showCoins();
		showMysteryBox();
		spawnEnemy();
		showEnemies();
		movePipes();
		moveCoins();
		moveEnemies();
		movebullet();
		showbullet();
		moveMysteryBox();
		checkPipeCollision();
		charactermove();
		characterjump();
		checkCoinCollision();
		checkMysteryBoxCollision();
		checkEnemyCollision();
		checkbulletcollision();
		if (cooldown > 0) cooldown--;
	}

	iShowImage(1140, 660, 100, 100, homeButtonImg);

	if (showExitDialog)
		iShowImage(dialogX, dialogY, 580, 500, exitDialogImg);

	if (level3Complete)
	{
		iShowImage(0, 0, 1280, 780, ice);
		int centerX = 180;
		int centerY = 0;
		iShowImage(centerX, centerY, 1000, 750, levelCompleteImage);

		if (showLevel3NextButton)
		{
			int nextBtnX = 5;
			int nextBtnY = 0;
			iShowImage(nextBtnX, nextBtnY, 250, 150, nextButtonImage);
			iSetColor(0, 0, 0);
			iText(80, 70, "NEXT", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (gameOver)
	{
		iShowImage(0, 0, 1280, 780, ice);
		int centerX = 110;
		int centerY = 100;
		iShowImage(centerX, centerY, 1110, 750, gameOverImage);

		if (showTryAgainButton)
		{
			int btnX = 550;
			int btnY = 50;
			iShowImage(btnX, btnY, 150, 150, nextButtonImage);
			iSetColor(0, 0, 0);
			iText(570, 119, "TRY AGAIN", GLUT_BITMAP_HELVETICA_18);
		}
	}
}



void page15()
{
	
	iShowImage(0, 0, 1280, 780, storypage); // story background

	// Popup image level 2
	iShowImage(420, level3TextY, 330, 210, level3image);
	if (!level3PopupDone)
		level3PopupAnimation();

	//after popup animation of level 2 image
	if (showLevel3Forest)
		iShowImage(350, 210, 570, 350, frameice);

	//continue text
	if (showLevel3ContinueText)
	{
		iShowImage(400, 100, 420, 130, press);
		iSetColor(255, 255, 255);
		iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	


}

void page16()
{
	iShowImage(0, 0, 1280, 780, storypage);
		iShowImage(200, 100, 900, 700, instructionImg);

		iShowImage(400, 100, 420, 130, press);
		iSetColor(255, 255, 255);
		iText(480, 160, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);
}














#endif