#include <string>
#include "BestScore.h"
using namespace std;

#define MAX_SCORE 3

class Podium
{
private :
	BestScore bScores[MAX_SCORE];
	int nbScores;
	void savePodium();
public :
	Podium(void);
	void render(void);
	bool isPodiumScore(int bs);
	void addPodium(BestScore bs);
};

