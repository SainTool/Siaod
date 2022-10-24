#include "sdiprogram_sv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SDIProgram_SV w;
    w.show();

    return a.exec();
}
