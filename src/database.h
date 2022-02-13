#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class DataBase
{
public:
    DataBase();

    QSqlDatabase db;
    QSqlQuery query;
};

#endif // DATABASE_H
