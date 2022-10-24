#ifndef INPUTDIALOG_SHEMENKOV_VADIM_H
#define INPUTDIALOG_SHEMENKOV_VADIM_H

#include "QDialog"
#include "QLineEdit"

class QlineEdit;
QString firstName();
QString lastName();
class InputDialog_Shemenkov_Vadim: public QDialog
{
    Q_OBJECT
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    InputDialog_Shemenkov_Vadim(QWidget* pwgt=0);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_SHEMENKOV_VADIM_H
