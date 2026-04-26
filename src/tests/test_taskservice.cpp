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
    service.addTask("Ler documentação");

    auto tasks = service.getTasks();
    auto searchResult = service.searchTasksByTitle("Qt");

    assert(tasks.size() == 2);
    assert(searchResult.size() == 1);
    assert(searchResult[0].title == "Estudar Qt");

    std::cout << "Teste passou!\n";
    std::cout << "POGGERS!\n";
    return 0;
}
