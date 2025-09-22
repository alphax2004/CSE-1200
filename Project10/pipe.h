#ifndef PIPE_HPP
#define PIPE_HPP

//value in imain.cpp
extern bool levelCompleted;



void initPipes() {
	int screenH = 780;
	int bottom = groundY + 120;
	int topBuffer = 150;
	int usable = screenH - bottom - topBuffer;
	int verticalGap = usable / MAX_PIPES;
	int baseY = bottom;

	for (int i = 0; i < MAX_PIPES; i++)
	{
		pipeX[i] = (i * (1280 / MAX_PIPES)) + rand() % 100;
		pipeY[i] = baseY + i * verticalGap + rand() % 20;
		if (rand() % 2 == 0)
			pipeMoveDir[i] = 0.07;
		else
			pipeMoveDir[i] = -0.07;

	}
}
void movePipes() {
	if (levelCompleted) return;
	for (int i = 0; i < MAX_PIPES; i++) {
		pipeX[i] += pipeMoveDir[i];

		if (pipeX[i] < 0 || pipeX[i] > 1280 - pipeWidth) {
			pipeMoveDir[i] *= -1;
		}
	}


}
void showPipes() {
	for (int i = 0; i < MAX_PIPES; i++) {
		iShowImage(pipeX[i], pipeY[i], pipeWidth, pipeHeight, pipeImg);
	}
}















#endif