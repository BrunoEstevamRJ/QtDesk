#include "TaskService.h"
#include <QString>

TaskService::TaskService()
{
    repo.createTable();
}

void TaskService::addTask(const QString& title)
{
    if (title.isEmpty()) {
        return; // validação simples
    }

    repo.addTask(title);
}

std::vector<Task> TaskService::getTasks()
{
    return repo.getTasks();
}

std::vector<Task> TaskService::searchTasksByTitle(const QString& queryText)
{
    return repo.searchTasksByTitle(queryText.trimmed());
}
