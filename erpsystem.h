#ifndef ERPSYSTEM_H
#define ERPSYSTEM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ERPsystem; }
QT_END_NAMESPACE

class ERPsystem : public QMainWindow
{
    Q_OBJECT

public:
    ERPsystem(QWidget *parent = nullptr);
    ~ERPsystem();

private:
    Ui::ERPsystem *ui;
};
#endif // ERPSYSTEM_H
