#include "txtJeu.h"
#include "Terrain.h"



#include <cassert>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>

#if _WIN32
#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#endif
using namespace std;

void txtClear()
{
    system("clear");
}

void affiche(Terrain terr)
{
    int dimx = terr.getDimX();
    int dimy = terr.getDimY();
    cout << dimx << " " << dimy << endl;
    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            cout << terr.getXY(x, y);
            // cout << "[" << x << "," << y << "]";

        }
        cout << endl;
    }
}


#if not defined _WIN32
int kbhit() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
#endif

char getCh() { // lire un caractere si une touche a ete pressee
    char touche=0;
#ifdef _WIN32
    if (kbhit())
    {
        DWORD mode;
        DWORD n;
        HANDLE consoleI = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(consoleI, &mode);
        SetConsoleMode(consoleI, mode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);
        ReadConsole(consoleI, &touche, 1, &n, NULL);
    }
#else
    if (kbhit())
        touche = fgetc(stdin);
#endif
    return touche;
}

void boucle(Terrain terr)
{
    affiche(terr);
    
    bool ok = true;
    char c;
    do
    {
        affiche(terr);
        
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
        
        


        c = getCh();
        cout << c << endl;
        if(c == 'a') 
        {
            ok = false;
            usleep(100000);
        }
        else cout << c << endl;
        
        txtClear();

    } while (ok);
}