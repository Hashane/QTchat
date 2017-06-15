#ifndef DIALOG_H
#define DIALOG_H
#include "mythread.h"  //Including the mythread class which implements threads used in my application
#include <QDialog>


namespace Ui {
/**
 *This is the dialog class which told to
 * inherit from designer DIALOG(ui::Dialog)
 */
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    mythread *mThread;
    QTcpSocket *socket;

private:
    Ui::Dialog *ui;
    int socketDescriptor;

public slots:
    void onMessageInvoked(QByteArray);
private slots:
    void on_bttnSend_clicked();
    void on_bttnCon_clicked();
     void readyRead();


     void on_txtMsg_returnPressed();
};

#endif // DIALOG_H
