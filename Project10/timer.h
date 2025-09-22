#ifndef TIMER_HPP
#define TIMER_HPP


void leveltimer1()
{
	updateTimerID = iSetTimer(20, update);
	movePipeTimerID = iSetTimer(10, movePipes);
	moveCoinTimerID = iSetTimer(10, moveCoins);
	enemyTimerID = iSetTimer(16, spawnEnemy);
	mysteryboxtimer = iSetTimer(1000, spawnMysteryBox);
	mysteryboxcollision = iSetTimer(1000, updateTimers);
}

void leveltimer2()
{
	updateTimerID = iSetTimer(20, update);
	movePipeTimerID = iSetTimer(16, movePipes);
	moveCoinTimerID = iSetTimer(16, moveCoins);
	enemyTimerID = iSetTimer(16, spawnEnemy);

	moveCrystalsTimerID = iSetTimer(10, moveCrystals);
	crystalcollision = iSetTimer(50, checkCrystalCollision);
	moveFireballsTimerID = iSetTimer(16, moveFireballs);
	enemyAutoFireballID = iSetTimer(10, enemyAutoFireball);
	fireballcollisiontimer = iSetTimer(16, checkFireballCollision);
	sheildtimerid = iSetTimer(16, updateShieldTimer);
}
void leveltimer3()
{
	updateTimerID = iSetTimer(20, update);
	movePipeTimerID = iSetTimer(16, movePipes);
	moveCoinTimerID = iSetTimer(16, moveCoins);
	enemyTimerID = iSetTimer(16, spawnEnemy);
	mysteryboxtimer = iSetTimer(1000, spawnMysteryBox);
	mysteryboxcollision = iSetTimer(1000, updateTimers);
}
















#endif