#include "welscr.h"
#include "sound.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welScr w;
    w.showFullScreen();
    Sound s;
    s.play();
    return a.exec();
}
