#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QtDesk - Task Manager");
    resize(800, 600);

    auto *central = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(central);
    auto *addLayout = new QHBoxLayout();

    auto *titleLabel = new QLabel("Nova tarefa:", this);
    titleInput = new QLineEdit(this);
    titleInput->setPlaceholderText("Digite o título da tarefa");
    addButton = new QPushButton("Adicionar", this);

    addLayout->addWidget(titleLabel);
    addLayout->addWidget(titleInput);
    addLayout->addWidget(addButton);

    auto *searchLabel = new QLabel("Buscar por título:", this);
    searchInput = new QLineEdit(this);
    searchInput->setPlaceholderText("Ex.: reunião");

    taskList = new QListWidget(this);

    mainLayout->addLayout(addLayout);
    mainLayout->addWidget(searchLabel);
    mainLayout->addWidget(searchInput);
    mainLayout->addWidget(taskList);

    setCentralWidget(central);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddTaskClicked);
    connect(titleInput, &QLineEdit::returnPressed, this, &MainWindow::onAddTaskClicked);
    connect(searchInput, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);

    refreshTaskList();
}

void MainWindow::onAddTaskClicked()
{
    taskService.addTask(titleInput->text().trimmed());
    titleInput->clear();
    refreshTaskList();
}

void MainWindow::onSearchTextChanged(const QString& text)
{
    renderTasks(taskService.searchTasksByTitle(text));
}

void MainWindow::refreshTaskList()
{
    const QString currentSearch = searchInput->text().trimmed();
    if (currentSearch.isEmpty()) {
        renderTasks(taskService.getTasks());
        return;
    }

    renderTasks(taskService.searchTasksByTitle(currentSearch));
}

void MainWindow::renderTasks(const std::vector<Task>& tasks)
{
    taskList->clear();

    for (const Task& task : tasks) {
        taskList->addItem(QString("#%1 - %2").arg(task.id).arg(task.title));
    }
}
