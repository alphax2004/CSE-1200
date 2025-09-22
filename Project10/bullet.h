#ifndef BULLET_HPP
#define BULLET_HPP




//BULLET 
#define MAX_BULLET 12
float bulletX[MAX_BULLET], bulletY[MAX_BULLET];


bool bulletvisible[MAX_BULLET];
float bulletspeed = 1.0;
int bulletwidth = 80, bulletheight = 50;

const int player_w = 90;
const int player_h = 120;
int cooldown = 0;


void inibullet(){

	for (int i = 0; i < MAX_BULLET; i++){
		bulletvisible[i] = false;
	}
}
void spawnbullet(){
	for (int i = 0; i < MAX_BULLET; i++){
		if (!bulletvisible[i]){
			bulletX[i] = playX + player_w;
			bulletY[i] = playY + (player_h / 2) - (bulletheight / 2);
			bulletvisible[i] = true;
			break;
		}

	}

}
void movebullet(){
	if (levelCompleted)return;
	for (int i = 0; i < MAX_BULLET; i++){
		if (!bulletvisible[i])continue;

		bulletX[i] += bulletspeed;
		if (bulletX[i]>1280)
			bulletvisible[i] = false;
	}
}




void showbullet(){
	for (int i = 0; i < MAX_BULLET; i++){
		if (!bulletvisible[i])continue;

		if (beam) {
			iShowImage(bulletX[i], bulletY[i], bulletwidth, bulletheight, beam);
		}
		else {
			iSetColor(255, 255, 0);
			iFilledRectangle((int)bulletX[i], (int)bulletY[i], bulletwidth, bulletheight);
		}
	}
}




void checkbulletcollision(){
	if (levelCompleted)return;

	for (int b = 0; b < MAX_BULLET; b++){
		if (!bulletvisible[b])continue;

		float bx1 = bulletX[b], by1 = bulletY[b];
		float bx2 = bx1 + bulletwidth, by2 = by1 + bulletheight;

		for (int e = 0; e < MAX_ENEMIES; e++){
			if (!enemyVisible[e])continue;


			float ex1 = enemyX[e], ey1 = enemyY[e];
			float ex2 = ex1 + enemyWidth, ey2 = ey1 + enemyHeight;


			bool hit = (bx1 <= ex2 && bx2 >= ex1 && by1 <= ey2 && by2 >= ey1);

			if (hit){
				enemyVisible[e] = false;
				bulletvisible[b] = false;
				score++;
				break;
			}
		}
	}



}

#endif