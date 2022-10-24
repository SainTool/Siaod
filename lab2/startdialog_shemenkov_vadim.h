#ifndef STARTDIALOG_SHEMENKOV_VADIM_H
#define STARTDIALOG_SHEMENKOV_VADIM_H

#include "QWidget"
#include "QPushButton"
#include "QMessageBox"
#include "InputDialog_Shemenkov_Vadim.h"

class StartDialog_Shemenkov_Vadim : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Shemenkov_Vadim(QWidget* pwgt = 0) : QPushButton("Press",pwgt){
        connect(this, SIGNAL(clicked()),SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked(){
        InputDialog_Shemenkov_Vadim* pInputDialog = new InputDialog_Shemenkov_Vadim;
        if(pInputDialog -> exec() == QDialog::Accepted){
            QMessageBox::information(0,
                                     "Ваша Информация",
                                     "Имя: "
                                     + pInputDialog->firstName() + "\nФамилия" + pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_SHEMENKOV_VADIM_H
