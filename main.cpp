#include "erpsystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ERPsystem w;
    w.show();
    return a.exec();
}
