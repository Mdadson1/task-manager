#include "Task.h"
#include "TaskList.h"
#include <iostream>
using namespace std;


int main(){

    //creates List
    TaskList myTasks;

    //test 
    cout << "Size before populating: " << myTasks.GetSize() << endl;
    myTasks.ShowTasks();
    myTasks.AddTask("Read Bible");
    myTasks.AddTask("Iron shirt");
    myTasks.AddTask("Call brother");
    cout << "Size after populating: " << myTasks.GetSize() << endl;
    myTasks.ShowTasks();
    myTasks.CompleteTask(1);
    myTasks.ShowTasks();
    myTasks.DeleteTask(1);
    myTasks.ShowTasks();


    return 0;
}