#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


/**
 * @brief Dialog::Dialog
 * @param parent
 * This is the contructor of the dialog class.This connectes readyread method.
 */
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     socket = new QTcpSocket(this);
mThread = new mythread(this);

  connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));


}


Dialog::~Dialog()
{
    delete ui;
}


/**
 * @brief Dialog::onMessageInvoked
 * @param msg
 * This the method i was going to use when using threading in client side to show the message incoming.
 */
void Dialog::onMessageInvoked(QByteArray msg)
{
   ui->txtchatBox->append(msg);

}

void Dialog::on_bttnSend_clicked()
{


   // mThread->start();

    QString msg = ui->txtMsg->text().trimmed();

    QByteArray array;
           array.append(msg);
           socket->write(array);
           socket->waitForBytesWritten(1000);

    ui->txtchatBox->append("You: "+array);



}





void Dialog::on_bttnCon_clicked()
{

   qint16 port = ui->txtPort->text().toInt();
     socket->connectToHost(ui->txtIp->text(),port);

}


/**
 * @brief Dialog::readyRead
 * This signal is emitted once every time new data is available for reading from the device.
 * It will only be emitted again once new data is available,
 * such as when a new payload of network data has arrived on your network socket,
 *  or when a new block of data has been appended to your device.
 * When a new message from server comes this triggers and shows the message incoming.
 */
void Dialog::readyRead()
{
    if( socket->bytesAvailable() ) {

         socket->readBufferSize();
         QByteArray data = socket->readAll();
         ui->txtchatBox->append("Server:"+data);
                                      }
}



\




void Dialog::on_txtMsg_returnPressed()
{
    mThread->start();

    QString msg = ui->txtMsg->text().trimmed();

    QByteArray array;
           array.append(msg);
           socket->write(array);
           socket->waitForBytesWritten(1000);

    ui->txtchatBox->append("You: "+array);

}
