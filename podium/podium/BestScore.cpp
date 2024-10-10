#include "BestScore.h"


void BestScore::doParty(void)
{
	//Play music
	//make animation
}

BestScore::BestScore(void)
{
}

BestScore::BestScore(string wname, int score, string timeDate)
{
	WName = wname;
	WScore = score;
	WDateTime = timeDate;
}

string BestScore::name(void)
{
	return string(WName);
}

int BestScore::score(void)
{
	return WScore;
}

string BestScore::time(void)
{
	return string(WDateTime);
}
