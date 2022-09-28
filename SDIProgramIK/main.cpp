#include "sdiprogramik.h"
#include <QApplication>
#include <QSplashScreen>
#include <QtWidgets>
#include <QTimer>

void loadModules(QSplashScreen *psplash)
{
    QTime time;
    time.start();

    for(int i=0;i<100;)
    {
        if(time.elapsed()>40)
        {
            time.start();
            ++i;
        }

        psplash->showMessage("Loading..." + QString::number(i)+"%",
                             Qt::AlignCenter|Qt::AlignCenter,
                             Qt::black);
        qDebug()<<i << " ";
        qApp->processEvents();
    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QPixmap(":/PNG.png");
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/Andrey/source/repos/SDIProgramIK/PNG.png"));
    splash->show();
   // a.processEvents();
    loadModules(splash);
    SDIProgramIK w;
    splash->finish(&w);
    w.show();

    return a.exec();
}
