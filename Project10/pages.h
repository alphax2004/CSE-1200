#ifndef PAGES_HPP
#define PAGES_HPP


int gamename, storypage, startpage, startpagebutton, backbutton, introbutton, storybutton, level1, forest, uibutton, pipeImg,press,coinImage;
int homeButtonImg, exitDialogImg, frameforest, charname, mysteryImg,level2Image,framedesert,desert;
double bgX = 0;
int page = 0;
int timer = 0;
int mysteryBoxImg;
//game name show
int gameNameImage;
int levelCompleteImage;
int nextButtonImage;
int gameOverImage;
int enemyleft[6];
int fireballImg;
int crystalImg;
int beam;
//character running image
int runSprite[6];         

int instructionImg;

int frameCounter = 0;
int runr8[1];
int runleft[6];


int characterBoyImage;
int characterGirlImage;



int ice, frameice, level3image;

int girlRun[6];
int girlLeft[6];


int level1Image;
int resumeIcon, pauseIcon;
int musicOnImg;
int musicOffImg;


void loadimage()
{
	gamename = iLoadImage("images/background.bmp");
	storypage = iLoadImage("images/storypage.bmp");
	startpage = iLoadImage("images/storypage.bmp");
	press = iLoadImage("images/5.bmp");
	startpagebutton = iLoadImage("images/8.bmp");
	backbutton = iLoadImage("images/8.bmp");
	storybutton = iLoadImage("images/12.bmp");
	introbutton = iLoadImage("images/12.bmp");
	level1 = iLoadImage("images/level1.bmp");

//character running image animation
	runSprite[0] = iLoadImage("images/rightstand.png");
	runSprite[1] = iLoadImage("images/2.png");
	runSprite[2] = iLoadImage("images/3.png");
	runSprite[3] = iLoadImage("images/4.png");
	runSprite[4] = iLoadImage("images/5.png");
	runSprite[5] = iLoadImage("images/6.png");

	// start button click game start page
	forest = iLoadImage("images/forest1.bmp");
	uibutton = iLoadImage("images/130.bmp");
	desert = iLoadImage("images/desert.bmp");
	ice = iLoadImage("images/ice.bmp");
	frameforest = iLoadImage("images/forest3.bmp");
	framedesert = iLoadImage("images/desert2.bmp");
	frameice = iLoadImage("images/ice2.bmp");
	//player right side move
	runr8[0] = iLoadImage("images/rightstand.png");
	
	//player left side move
	runleft[0] = iLoadImage("images/leftstand.png");
	runleft[1] = iLoadImage("images/leftmove1.png");
	runleft[2] = iLoadImage("images/leftmove2.png");
	runleft[3] = iLoadImage("images/leftmove3.png");
	runleft[4] = iLoadImage("images/leftmove4.png");
	runleft[5] = iLoadImage("images/leftmove5.png");

	exitDialogImg = iLoadImage("images/exitDialog.png");
	homeButtonImg = iLoadImage("images/homeButton.png");

	pipeImg = iLoadImage("images/Tiles.png");

	coinImage = iLoadImage("images/11.png");
	
	girlRun[0] = iLoadImage("images/right.png");
	girlRun[1] = iLoadImage("images/222.png");
	girlRun[2] = iLoadImage("images/333.png");
	girlRun[3] = iLoadImage("images/444.png");
	girlRun[4] = iLoadImage("images/555.png");
	girlRun[5] = iLoadImage("images/666.png");
	//girlRun[6] = iLoadImage("images/right.png");

	beam = iLoadImage("images/beam.png");

	// girl running left
	girlLeft[0] = iLoadImage("images/left.png");
	girlLeft[1] = iLoadImage("images/102.png");
	girlLeft[2] = iLoadImage("images/103.png");
	girlLeft[3] = iLoadImage("images/104.png");
	girlLeft[4] = iLoadImage("images/105.png");
	girlLeft[5] = iLoadImage("images/106.png");
	//girlLeft[6] = iLoadImage("images/left.png");
	

	characterBoyImage = iLoadImage("images/male.png");
	characterGirlImage = iLoadImage("images/girl.png");

	level1Image = iLoadImage("images/levelname.png");

	charname = iLoadImage("images/charname.png");

	
	nextButtonImage = iLoadImage("images/8.bmp");
	levelCompleteImage = iLoadImage("images/levelcomplete.png");

	mysteryBoxImg = iLoadImage("images/mysteryboxRed.png");

	gameOverImage = iLoadImage("images/gameover.png");

	level2Image = iLoadImage("images/level2image.png");
	level3image = iLoadImage("images/level3image.png");
	//enemy left move


	instructionImg = iLoadImage("images/instruct.png");

	fireballImg = iLoadImage("images/fireball.png");
	crystalImg = iLoadImage("images/crystal.png");
	resumeIcon = iLoadImage("images/resume.png");
	pauseIcon = iLoadImage("images/pauseIcon.png");
	musicOnImg = iLoadImage("images/soundon.png");
	musicOffImg = iLoadImage("images/soundoff.png");


	
}
void enemyimage()
{
	enemyleft[0] = iLoadImage("images/cat1.png");
	enemyleft[1] = iLoadImage("images/cat2.png");
	enemyleft[2] = iLoadImage("images/cat3.png");
	enemyleft[3] = iLoadImage("images/cat4.png");
	enemyleft[4] = iLoadImage("images/cat5.png");
	//enemyleft[5] = iLoadImage("images/cat1.png");
}
//game page start
void showstartpage()
{
	page = 2;
	iPauseTimer(timer);
}

//story page
void showstorypage()
{
	page = 1;
	iPauseTimer(timer);
	
}





#endif