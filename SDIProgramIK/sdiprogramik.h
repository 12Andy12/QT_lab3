#ifndef SDIPROGRAMIK_H
#define SDIPROGRAMIK_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextEdit>
#include <QColorDialog>
#include "docwindowik.h"
#include "ui_sdiprogramik.h"

namespace Ui {
class SDIProgramIK;
}

class SDIProgramIK : public QMainWindow
{
    Q_OBJECT

private:
    Ui::SDIProgramIK *ui;

public:
    SDIProgramIK(QWidget *pwgt = 0):
        QMainWindow(pwgt),
        ui(new Ui::SDIProgramIK)
    {
        ui->setupUi(this);


        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindowIK* pdoc = new DocWindowIK();

        pmnuFile->addAction("&Open...",
                            pdoc,
                            SLOT(slotLoad()),
                            QKeySequence("CTRL+O")
                            );
        pmnuFile->addAction("&Save...",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S")
                            );
        pmnuFile->addAction("&SaveASS...",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+A")
                            );
        pmnuHelp->addAction("&About...",
                            this,
                            SLOT(slotAbout()),
                            QKeySequence("Qt::Key_F1")
                            );
        pmnuFile->addAction("&Color...",
                            pdoc,
                            SLOT(slotColor()),
                            QKeySequence("Qt::Key_F2")
                            );

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);
        connect(pdoc,
                SIGNAL(changeWindowTitle(const QString&)),
                SLOT(slotChangeWindowTitle(const QString&))
                );

        statusBar()->showMessage("Ready",4000);
        //ui->centralWidget->setT
    }

    ~SDIProgramIK();

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "IP-017\nKostin ANdrey and Izvekov Ivan");
    }
    void slotChangeWindowTitle(const QString& str){
        setWindowTitle(str);
    }

};

#endif // SDIPROGRAMIK_H
