#include "produse.h"
#include <QtWidgets/QApplication>
#include"Repo.h"
#include"Service.h"
#include"GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo;
    Service srv{ repo };
    GUI gui(srv);
    gui.run();
    return a.exec();
}
