#include "database.h"
#include "settings.h"
#include "mainwindow.h"
#include "gamewindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QtSql>

int random( int max, int min = 0 );

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    srand( time(NULL) );
    //set looks
    QFile File(":/res/css/style.css");
    if( !File.open( QFile::ReadOnly | QFile::Text ) ){
        qDebug() << "Could not read file";
    }
    QTextStream in( &File );
    QString style = in.readAll();
    app.setStyle( "plastique" );
    app.setStyleSheet( style );
    File.close();
    MainWindow w;
//    GameWindow w( 0, 0xff );
    w.show();

    return app.exec();
    //*/
}
