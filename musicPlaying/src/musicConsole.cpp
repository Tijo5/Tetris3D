#include "musicConsole.h"


void MusicConsole::musicBox(LPCWSTR s)
{   
    PlaySound(s, 0, SND_FILENAME);
}
