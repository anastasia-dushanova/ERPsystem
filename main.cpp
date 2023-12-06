#include "erpsystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ERPsystem w;
    w.show();
//    DataBaseConnector d;

    return a.exec();
}
