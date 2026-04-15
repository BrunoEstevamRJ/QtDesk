#pragma once

#include "Task.h"
#include "../db/TaskRepository.h"
#include <vector>

class TaskService {
private:
    TaskRepository repo;

public:
    TaskService();

    void addTask(const QString& title);
    std::vector<Task> getTasks();
};
