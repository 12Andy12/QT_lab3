#ifndef DOCWINDOWIK_H
#define DOCWINDOWIK_H

#include <QTextEdit>
#include <QFileDialog>
#include <QTextStream>
#include <QColorDialog>

class DocWindowIK : public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;

public:

    DocWindowIK(QWidget* pwgt = 0):
        QTextEdit(pwgt)
    {

    }

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor()
    {
        QColor color = QColorDialog::getColor(Qt::red, this);
        setTextColor(color);
    }
};

#endif // DOCWINDOWIK_H
