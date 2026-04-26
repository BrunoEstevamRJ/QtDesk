#pragma once

#include <QSqlDatabase>
#include <QString>
#include <vector>
#include "../core/Task.h"

class TaskRepository {
private:
    QSqlDatabase db;

public:
    TaskRepository();

    void createTable();
    void addTask(const QString& title);
    std::vector<Task> getTasks();
    std::vector<Task> searchTasksByTitle(const QString& queryText);
};
