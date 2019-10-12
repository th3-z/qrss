#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name, QWidget *parent = nullptr);
    ~Task();

    void setName(const QString& name);
    QString getName() const;
    bool isCompleted() const;

public slots:
    void rename();

private slots:
    void checked(bool checked);

signals:
    void removed(Task* task);
    void statusChanged(Task* task);

private:
    Ui::Task *ui;
    // The fields are stored in the UI
};

#endif // TASK_H
