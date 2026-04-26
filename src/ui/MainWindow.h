#pragma once

#include <QMainWindow>
#include "../core/TaskService.h"

class QLineEdit;
class QPushButton;
class QListWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddTaskClicked();
    void onSearchTextChanged(const QString& text);

private:
    void refreshTaskList();
    void renderTasks(const std::vector<Task>& tasks);

    TaskService taskService;
    QLineEdit* titleInput;
    QLineEdit* searchInput;
    QPushButton* addButton;
    QListWidget* taskList;
};
