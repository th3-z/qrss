#include "task.h"
#include "ui_task.h"

#include <QInputDialog>

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked,
            this, &Task::rename);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString &name)
{
    ui->checkBox->setText(name);

    connect(ui->removeButton, &QPushButton::clicked, [this] {
        emit removed(this);
    });
}

QString Task::getName() const
{
    return ui->checkBox->text();
}

bool Task::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(
        this, tr("Edit task"),
        tr("Task name"),
        QLineEdit::Normal,
        this->getName(), &ok
    );

    if (ok && !value.isEmpty()) {
        setName(value);
    }
}


