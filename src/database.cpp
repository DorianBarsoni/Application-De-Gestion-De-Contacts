#include "database.h"
#include <QDebug>
#include <QSqlError>

DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/dbars/Desktop/Cours/L3/CDAA/Projet/database.sqlite");
    if(!db.open()) qDebug() <<"Impossible d'ouvrir la BDD";
    else
    {
        query = QSqlQuery(db);
        //query.prepare();
        if(!query.exec("select * from Contact")) qDebug() << query.lastError().text();
        else
        {
            while(query.next())
            {
                qDebug() << query.value(1).toString();
            }
        }
    }
}
