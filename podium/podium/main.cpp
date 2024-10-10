#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

#include "podium.h"
using namespace std;

void timeNow(std::string* tn);

int main() {
    //Charger et afficher les score du podium
    Podium* p;
    p = new Podium();
    //p->render();

    //Proposer un nouveau score apres GameOver
    string time;
    timeNow(&time);
    BestScore *bs;
    bs = new BestScore("samimco", 12700, time);

    //Si ce score doit figurer ds le podium alors l'ajouter
    if (p->isPodiumScore(12700))
        p->addPodium(*bs);

    //Afficher le podium
    p->render();
}

//Lire l'heure et la adte systeme
void timeNow(std::string* tn) {
    auto start = std::chrono::system_clock::now();
    auto legacyStart = std::chrono::system_clock::to_time_t(start);
    char tmBuff[50];
    ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
    //Enlever retour chario
    int i = 0;
    while (i < 50) {
        if (tmBuff[i] == '\n')
            tmBuff[i] = '\0';
        i++;
    }
    //Fin Enlever retour chario
    std::string s = tmBuff;
    *tn = s;
}