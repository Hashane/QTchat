#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QTcpSocket>
#include <QDebug>
#include<QObject>
#include <stdio.h>
#include<cstdio>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(int ID,QObject *parent = 0);
  void run();
signals:
  void error(QTcpSocket::SocketError socketerror);


public slots:
  void readyRead();
  void disconnected();


private:
  QTcpSocket *socket;
  int socketDescriptor;
 //QList<QTcpSocket*>client;

};

#endif // MYTHREAD_H
