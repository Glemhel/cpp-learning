//
// Created by mikhail on 25.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) const {
        return tasksBook.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person) {
        tasksBook[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string &person, int task_count) {
        TasksInfo updated_tasks;
        TasksInfo untouched_tasks;
        for (const auto &x: tasksBook[person]) {
            // enum ID of this task type and amount
            auto current_task = x.first;
            auto amount = x.second;
            // if DONE tasks - do not need to update
            if (current_task == TaskStatus::DONE)
                break;
            else {
                // if not DONE - we will do some of them, assign to next_task
                auto next_task = static_cast<TaskStatus>(static_cast<int>(current_task) + 1);
                // not to flood map with empty values, check for 0
                if (min(amount, task_count) != 0)
                    updated_tasks[next_task] += min(amount, task_count);
            }
            // decrease amount of tasks to do
            if (task_count >= amount) {
                task_count -= amount;
            } else {
                // if tasks_count will be zero, transfer untouched tasks to respective map
                untouched_tasks[current_task] += amount - task_count;
                task_count = 0;
            }
        }
        // fill tasksBook for the given person, given updated and untouched tasks
        for (auto &x: tasksBook[person])
            x.second = 0;
        for (const auto &x: updated_tasks)
            tasksBook[person][x.first] += x.second;
        for (const auto &x: untouched_tasks)
            tasksBook[person][x.first] += x.second;
        return tie(updated_tasks, untouched_tasks);
    }

private:
    map<string, TasksInfo> tasksBook;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 3);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);


    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 3);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}

