#include "taskmanager.h"

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::removeTask(int index) {
    if (index >= 0 && index < tasks.size())
        tasks.erase(tasks.begin() + index);
}

void TaskManager::toggleCompleted(int index) {
    if (index >= 0 && index < tasks.size())
        tasks[index].completed = !tasks[index].completed;
}

const std::vector<Task>& TaskManager::getTasks() const {
    return tasks;
}

