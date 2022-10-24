#ifndef DOCWINDOW_SV_H
#define DOCWINDOW_SV_H

#include "QTextEdit"

class DocWindow_SV: public QTextEdit{
    Q_OBJECT
private:
        QString m_strFileName;
public:
    DocWindow_SV(QWidget* pwgt=0);
signals:
    void changeWindowTitle(const QString&);

public slots:
void slotLoad();
void slotSave();
void slotSaveAs();
};


#endif // DOCWINDOW_SV_H
