#include "podium.h"

#include <iostream>
#include <fstream>

using namespace std;

Podium::Podium(void)
{
    string name, time, sscore;
    ifstream myfile("podium.txt");
    if (myfile.is_open())
    {
        int i = 0;
        while (getline(myfile, name) && i<MAX_SCORE)
        {
            getline(myfile, sscore);
            getline(myfile, time);
           
            BestScore* bs;
            bs = new BestScore(name, stoi(sscore), time);
            bScores[i] = *bs;
            
            i++;
        }
        nbScores = i;
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Podium::savePodium()
{
    ofstream myfile("podium.txt");
    if (myfile.is_open()) {
        for (int i = 0; i < nbScores; i++) {
            myfile << bScores[i].name() << endl;
            myfile << bScores[i].score() << endl;
            myfile << bScores[i].time() << endl;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Podium::render(void)
{
    for (int i = 0; i < nbScores; i++) {
        cout << "best " << i+1 << " score " << endl;
        cout << "name " << bScores[i].name() << endl 
            << "score " << bScores[i].score()  << endl 
            << "date " << bScores[i].time() << endl;
    }
}

bool Podium::isPodiumScore(int s)
{
    if (nbScores < MAX_SCORE) return true;
    for (int i = 0; i < nbScores; i++)
        if (bScores[i].score() < s)
            return true;
    return false;
}

void Podium::addPodium(BestScore bs)
{
    int i = 0;
    bool trouve = false;
    while (i < nbScores && !trouve) {
        if (bScores[i].score() < bs.score())
            trouve = true;
        else
            i++;
    }
    if (!trouve) {
        bScores[nbScores] = bs;
        nbScores++;
    }
    else {
        int j;
        if (nbScores < MAX_SCORE) {
            for (j = nbScores; j > i; j--) {
                bScores[j] = bScores[j - 1];
            }
            nbScores++;
        }
        else
            for (j = nbScores - 1; j > i; j--)
                bScores[j] = bScores[j - 1];

        bScores[i] = bs;
    }
    savePodium();
}





