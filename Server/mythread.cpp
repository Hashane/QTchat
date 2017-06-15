#include "mythread.h"
#include <QtCore>
#include <QDebug>

/**
 * @brief mythread::mythread
 * @param parent
 * This is the implementation of the
 * constructor belongs to mythread class
 */
mythread::mythread(QObject *parent):QThread(parent)
{


}

/**
 * @brief mythread::run
 * run method is the method which runs or triggers when called Thread.start()
 * When thread starts it identifies the run method and runs the code accordingly
 *BUT IT"S NOT USED HERE . as Threading on client side didn't work properly it was left out.
 */
void mythread::run()
{

     socket = new QTcpSocket(this);
    if( socket->bytesAvailable() ) {

         socket->readBufferSize();
         QByteArray data = socket->readAll();

          emit messageInvoked(data);
         exec();
     }
}




