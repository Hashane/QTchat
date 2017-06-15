#include <QCoreApplication>
#include<myserver.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
qDebug() <<"Hey I'm the Server"<< endl;

    myserver server;

    server.startServer();
    return a.exec();
}
