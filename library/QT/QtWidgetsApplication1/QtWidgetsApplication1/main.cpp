#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>






int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QtWidgetsApplication1 mainwindow;

    mainwindow.showMaximized();
   
    return app.exec();
}
