#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <iostream>
using namespace std;

class TaskList{
public:
TaskList(); //constructor
~TaskList(); //destructor

int GetSize();

void AddTask(string description);
void ShowTasks();
void DeleteTask(int p);
void CompleteTask(int pos);

private:
Task* m_head;
Task* m_tail;
int m_size;
};


#endif