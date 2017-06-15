#include "myserver.h"

myserver::myserver(QObject *parent) : QTcpServer(parent)
{

}

/**
 * @brief myserver::startServer
 *
 * start server  is the method which runs first from the console
 * it's where the server listen's for incoming connections.
 * In here the connections among clients are established.
 */

void myserver::startServer()
{
    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Couldn't start Server";
    }
    else
    {
        qDebug() << "Listening.....";
    }
}

/**
 * @brief myserver::incomingConnection
 * always when a new client is connected incoming connection method it triggered and runs.
 * It shows the status of the server saying connecting.And start the main thread here so that
 * multiple clients can connect. And also deletion of the thread after it's finished is set here
 * in order to remove the excess unwanted dump data.
 * @param socketDescriptor
 *
 *
 * socket descriptor parameter is used to identify specific client
 * When a new client is connected socketdescriptor is assigns to that client and it's
 * unique identifier for a client connecting through tcp connection to the server.
 */
void myserver::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << "connecting....";
    mythread *thread = new mythread(socketDescriptor,this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
   thread->start();
}
