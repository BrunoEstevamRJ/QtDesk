#include "TaskRepository.h"
#include "Database.h"
#include <QSqlQuery>
#include <QSqlRecord>

TaskRepository::TaskRepository()
{
    db = Database::connect();
}

void TaskRepository::createTable()
{
    QSqlQuery query(db);

    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "title TEXT)");
}

void TaskRepository::addTask(const QString& title)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO tasks (title) VALUES (:title)");
    query.bindValue(":title", title);
    query.exec();
}

std::vector<Task> TaskRepository::getTasks()
{
    std::vector<Task> tasks;

    QSqlQuery query("SELECT id, title FROM tasks", db);

    while (query.next()) {
        Task t;
        t.id = query.value("id").toInt();
        t.title = query.value("title").toString();
        tasks.push_back(t);
    }

    return tasks;
}

std::vector<Task> TaskRepository::searchTasksByTitle(const QString& queryText)
{
    std::vector<Task> tasks;
    QSqlQuery query(db);

    query.prepare("SELECT id, title FROM tasks WHERE title LIKE :query ORDER BY id DESC");
    query.bindValue(":query", "%" + queryText + "%");
    query.exec();

    while (query.next()) {
        Task t;
        t.id = query.value("id").toInt();
        t.title = query.value("title").toString();
        tasks.push_back(t);
    }

    return tasks;
}
