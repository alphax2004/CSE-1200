#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")





bool Music = true; // Background music ON by default

// Button for toggling music
int musicBtnX = 1150;
int musicBtnY = 20;
int musicBtnW = 120;
int musicBtnH = 120;

// Button images


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// MUSIC CONTROL FUNCTIONS
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// Play background music in loop
void playBackgroundMusic()
{
	if (Music)
	{
		mciSendString("open \"music/Game_BGmusic.wav\" type mpegvideo alias bgm", NULL, 0, NULL);
		mciSendString("play bgm repeat", NULL, 0, NULL);
	}
}

// Stop background music completely
void stopBackgroundMusic()
{
	mciSendString("stop bgm", NULL, 0, NULL);
	mciSendString("close bgm", NULL, 0, NULL);
}

// Toggle ON/OFF
void toggleMusic()
{
	if (Music)
	{
		Music = false;
		stopBackgroundMusic();
	}
	else
	{
		Music = true;
		playBackgroundMusic();
	}
}

// Draw music toggle button
void drawMusicButton()
{
	if (Music)
		iShowImage(musicBtnX, musicBtnY, musicBtnW, musicBtnH, musicOnImg);
	else
		iShowImage(musicBtnX, musicBtnY, musicBtnW, musicBtnH, musicOffImg);
}

// Handle click on music button


#endif
