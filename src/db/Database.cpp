#include "Database.h"
#include <QSqlDatabase>

QSqlDatabase Database::connect()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        return QSqlDatabase::database("qt_sql_default_connection");
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("qtdesk.db");

    if (!db.open()) {
        // log futuramente
    }

    return db;
}
