#ifndef SDIPROGRAM_SV_H
#define SDIPROGRAM_SV_H

#include <QMainWindow>
#include <QtWidgets>
#include "docwindow_sv.h"
#include "sdiprogram_sv.h"

class SDIProgram_SV : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram_SV(QWidget *pwgt = 0): QMainWindow(pwgt){
        QMenu* pmnuFile = new QMenu ("&File");
        QMenu* pmnuHelp = new QMenu ("&Help");
        DocWindow_SV* pdoc = new DocWindow_SV;
        pmnuFile->addAction("&Open...",pdoc,SLOT(slotLoad()), QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save",pdoc,SLOT(slotSave()),QKeySequence("CTRL+S"));
        pmnuFile->addAction("&SaveAs...",pdoc,SLOT(slotSaveAs()), QKeySequence("CTRL+W"));
        pmnuFile->addAction("&Quit",qApp,SLOT(quit()),QKeySequence("ALT+F4"));
        //help
        pmnuHelp->addAction("&About",this,SLOT(slotAbout()),Qt::Key_F1);
        //
        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        setCentralWidget(pdoc);
        connect(pdoc,SIGNAL(slotChangeWindowTitle(const QSting&)),SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready",2000);
    }
    ~SDIProgram_SV();
public slots:
    void slotAbout(){
        QMessageBox::about(this,"Application","SDI Example");
    }

    void slotChangeWindowTitle(const QString& str){
        setWindowTitle(str);
    }
//private:
};

#endif // SDIPROGRAM_SV_H
