#include "StartDialog_Shemenkov_Vadim.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Shemenkov_Vadim startDialog_SV;
    startDialog_SV.show();

    return a.exec();
}
