#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

struct Task{
Task(string description){
    m_description = description;
    m_status = false;
    m_next = nullptr;
}
string m_description;
bool m_status;
Task* m_next;
};

#endif 