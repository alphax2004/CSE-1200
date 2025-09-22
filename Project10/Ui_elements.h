#ifndef UI_ELEMENTS_HPP
#define UI_ELEMENTS_HPP

#include "pages.h"
#include "player.h"
void showstory()
{
	//story
	glLineWidth(5);
	iSetColor(20, 51, 10);

	iText(191, 623, "Long ago in a colorful land a prince and a princess set out on an epic journey.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(190, 559, "Suddenly some evil enemies atack the land.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(188, 500, "They must defeat the enemies and collect coins in all worlds to save the land.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(191, 440, "Will you help them succeed?", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(191, 375, "Get ready for the adventure!", GLUT_BITMAP_TIMES_ROMAN_24);

}
void showbuttons()
{
	iSetColor(20, 51, 10);
	iText(600, 575, "START", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(568, 475, "INSTRUCTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(598, 375, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(596, 275, "CREDITS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(570, 175, "CHARACTER", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(605, 75, "QUIT", GLUT_BITMAP_TIMES_ROMAN_24);
}

void showinstructions()
{
	iSetColor(20, 51, 10);
	iText(250, 610, "Use right key to move forward.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250, 560, "Use left key to move backward.", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250, 500, "Press UP key to jump and kill enemies", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250, 440, "Collect coins and kill enemies by jumping on them to unlock next level", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250, 380, "Avoid colliding with enemies so that you dont loose health", GLUT_BITMAP_TIMES_ROMAN_24);
//back button
	iShowImage(50, 20, 150, 120, backbutton);
	iText(90, 80, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);

}

void showscorepage()
{
	//back button
	iShowImage(50, 20, 150, 120, backbutton);
	iText(90, 80, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}

void showcredits()
{
	//back button
	iShowImage(50, 20, 150, 120, backbutton);
	iText(90, 80, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(20, 51, 10);
	iText(500, 560, "Sanjida Islam Alfa", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 500, "Fariha Chowdhury", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 440, "Jawad Ibn Masum", GLUT_BITMAP_TIMES_ROMAN_24);
}
void showstart()
{
	iShowImage(50, 20, 150, 120, backbutton);
	iText(90, 80, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}


#endif