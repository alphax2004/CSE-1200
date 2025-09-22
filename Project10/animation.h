#ifndef ANIMATION_HPP
#define ANIMATION_HPP


const double popupSpeed = 2.0;
int levelTextY = -200; // popup Y start
bool showContinueText = false;
bool showForestBackground = false;
int levelPopupTimerID;
int continueTextTimerID;

double popupScale = 0.1;
double finalWidth = 850;
double finalHeight = 290;
double centerX = 250;
double centerY = 420;
bool popupDone = false;
int runnerX = 150, runnerY = 100;

//initialize at imain.cpp
extern int level2TextY;
extern int boyPopupX, girlPopupX;
extern int boyPopupY, girlPopupY;
extern bool popupAnimationRunning;
extern const double deltatime;
extern bool level3PopupRunning;

 // same as level1
extern bool showLevel2ContinueText;
extern bool showLevel2Forest;
extern int level2PopupTimerID;
extern const double level2PopupSpeed;


extern int level3TextY;
extern bool showLevel3ContinueText;
extern bool showLevel3Forest;
extern int level3PopupTimerID;
const double level3PopupSpeed = 20.0;

// Level 3 Name Animation
double level3NameScale = 0.04;
const double level3NameFinalWidth = 750;
const double level3NameFinalHeight = 290;
const double level3NameCenterX = 640;
const double level3NameCenterY = 390;
bool level3NameDone = false;
/*
void level3NameAnimation()
{
	if (level3NameScale < 1.0) {
        level3NameScale += 0.05;  // speed of scaling
        if (level3NameScale > 1.0)
            level3NameScale = 1.0;
    }
    else {
        level3NameDone = true;     // animation finished
        showLevel3Forest = true;
        showLevel3ContinueText = true;
    }

    // Draw the image with current scale
    int width = level3NameFinalWidth * level3NameScale;
    int height = level3NameFinalHeight * level3NameScale;
    int posX = level3NameCenterX + (level3NameFinalWidth - width)/2;
    int posY = level3NameCenterY + (level3NameFinalHeight - height)/2;

    iShowImage(posX, posY, width, height, level3image);
}

*/



void level2PopupAnimation()
{
	if (level2TextY < 550) // rise up
		level2TextY += level2PopupSpeed; //koto speed e uthbe
	else
	{
		iPauseTimer(level2PopupTimerID);
		level2PopupTimerID = 0;// stop timer
		showLevel2Forest = true;
		showLevel2ContinueText = true;
	}
}
bool level3PopupDone = false;

void level3PopupAnimation()
{
	
	if (level3TextY < 550) // rise up
		level3TextY += level3PopupSpeed; //koto speed e uthbe
	else
	{
		//level3TextY = 550;
		iPauseTimer(level3PopupTimerID);
		level3PopupTimerID = 0;
		showLevel3Forest = true;
		showLevel3ContinueText = true;
		level3PopupRunning = false;

	}
	
}

void characteranimation()
{
	int currentFrame = (frameCounter / 120) % 6;
	iShowImage(runnerX, runnerY, 250, 300, runSprite[currentFrame]);
	frameCounter++;
}


void level1PopupAnimation() {
	if (levelTextY < 500) //koto upore uthbe
	{
		levelTextY += 20;//koto speed e uthbe
	}
	else
	{
		iPauseTimer(levelPopupTimerID);//popup thamar jonno
		levelPopupTimerID = 0;
		showForestBackground = true;
		showContinueText = true;
	}
}


//game name animation
void popupAnimation()
{
	if (popupScale < 1.0) {
		popupScale += 0.05;
		if (popupScale > 1.0)
			popupScale = 1.0;
	}
	else {
		popupDone = true;
	}
}

//character page er character popup animation
void popupAnimation2()
{
	if (popupAnimationRunning)
	{
		boyPopupY += popupSpeed * deltatime;  //koto speed e uthbe
		girlPopupY += popupSpeed * deltatime;

		if (boyPopupY >= 250)
		{
			boyPopupY = 250;  //last range uthar  er pore stop
			girlPopupY = 250;
			popupAnimationRunning = false;
		}
	}
}

void gamenameanimation()
{
	double currentWidth = (finalWidth * popupScale);
	double currentHeight = (finalHeight * popupScale);
	double posX = centerX + (finalWidth - currentWidth) / 2;
	double posY = centerY + (finalHeight - currentHeight) / 2;

	iShowImage(posX, posY, currentWidth, currentHeight, gameNameImage);



}
// Next button pressed after level 2


	







#endif