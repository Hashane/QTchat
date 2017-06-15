#include "mythread.h"

mythread::mythread(int ID,QObject *parent) : QThread(parent)
{
this->socketDescriptor = ID;

}

/**
 * @brief mythread::run
 * run method is the method which runs or triggers when called Thread.start()
 * When thread starts it identifies the run method and runs the code accordingly
 */
void mythread::run()
{//QTcpSocket *soc = new QTcpSocket;

    //thread starts here
    qDebug() << socketDescriptor << "Starting thread";
   socket = new QTcpSocket();


   if(!socket->setSocketDescriptor(this->socketDescriptor))  //Error signal will be emitted when if the socket
   {                                                         //hasn't been set a socketdescriptor
       emit error(socket->error());
       return;
   }

   // client.append(socket);
   connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
   connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);


   qDebug() << socketDescriptor << "Client connected";


   exec();
}

void mythread::readyRead() //This signal is to indicate that new data is avalable to be read from the socket
{

    QByteArray data = socket->readAll();
    qDebug() << socketDescriptor << "says" << data;


//getting the input from the Console and append input to Qbytearray because socket.write() function's argument should be in
//in Qbytearray format
    QTextStream in(stdin);
    QString line = in.readLine();
    QByteArray array;
           array.append(line);


   socket->write(array);
//flushing the data wrote to the socket to make sure it got sent
   socket->flush();
   socket->waitForBytesWritten(1000);

//    if(!client.empty()){
//foreach(QTcpSocket *soc, client) {
//            soc->write(data);
//            soc->flush();
//            soc->waitForBytesWritten(1000);
//            qDebug() << client << soc;


//    }
//    }
//    else
//        qDebug () << "crash";

}

//Signal to indicate when a client disconnects from server
void mythread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected ";
    socket->deleteLater();
    exit(0);
}

