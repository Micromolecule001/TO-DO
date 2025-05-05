#pragma once
#include "task.h"
#include <vector>

class TaskManager {
public:
    void addTask(const Task& task);
    void removeTask(int index);
    void toggleCompleted(int index);
    const std::vector<Task>& getTasks() const;

private:
    std::vector<Task> tasks;
};

