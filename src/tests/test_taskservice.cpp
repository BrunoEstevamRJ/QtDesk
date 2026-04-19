#include <QCoreApplication>
#include <QSqlDatabase>
#include <cassert>
#include <iostream>

#include "core/TaskService.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 🔥 garante conexão antes de tudo
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    db.open();

    TaskService service;

    service.addTask("Estudar Qt");

    auto tasks = service.getTasks();

    assert(tasks.size() == 1);

    std::cout << "Teste passou!\n";
    std::cout << "POGGERS!\n";
    return 0;
}
