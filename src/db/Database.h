#pragma once

#include <QSqlDatabase>

class Database {
public:
    static QSqlDatabase connect();
};
