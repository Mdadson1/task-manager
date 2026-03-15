#include "TaskList.h"
using namespace std;

TaskList::TaskList(){
    cout << "Task Manager created!." << endl;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

TaskList::~TaskList(){
    if(m_head == nullptr){
        return;
    } else if(m_head->m_next == nullptr){//only one node
        delete m_head;
        delete m_tail;
    } else {
        Task* cur = m_head;
        while(cur != nullptr){
            //save node , move , delete saved node
            m_head = cur; //will save the node just before current
            cur = cur->m_next; //moves to node after saved one
            delete m_head;
        }
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    cout << "Task Manager closed!" << endl;
}

int TaskList::GetSize(){
    return m_size;
}

void TaskList::AddTask(string description){
    //make new node
    Task* temp = new Task(description);
    //no nodes
    if(m_head == nullptr){
        m_head = temp;
        m_tail = temp;
        temp = nullptr;
        m_size++;
    } else {
        m_tail->m_next = temp;
        m_tail = temp;
        temp = nullptr;   
        m_size++; 
    }
}

void TaskList::ShowTasks(){
    Task* cur = m_head;

    if(m_head == nullptr){ //no nodes
        cout << "No Tasks to do." << endl;
    } else { //nodes
    int num = 1;
        while(cur != nullptr && num <= GetSize()){

            cout << num << 
            ". " << cur->m_description <<
            "\nStatus: " << ( (cur->m_status)? "Completed":"Not Completed" ) << endl;
            cur = cur->m_next;
            num++;
        }
    }
}

void TaskList::DeleteTask(int p){
    //takes an index, goes to that index, removes node
    int nodeNumber = 1;

    //validate if index exists
    if(p < 1 || p > GetSize() ){
        cout << "Task does not exist." << endl;
        return;
    } else {
        Task* cur = m_head;
        Task* prev = nullptr;

        while(nodeNumber < p && cur != nullptr){ //traverse until at position
            prev = cur;
            cur = cur->m_next;
            nodeNumber++;
        }//we are at the position, cur is at the position to delete
        if(cur == m_head){ //node to delete is the head
            m_head = cur->m_next; //shift head
            delete cur; //deleted
            cur = nullptr;
        } else {//surrounding nodes
            prev->m_next = cur->m_next; //link to node after node to be deleted
            delete cur;
            cur = nullptr;
        }
    }
}


void TaskList::CompleteTask(int pos){
    //takes an index, go to index if it exists, changes status
    int nodeNum = 1;
    //validate if position exists
    if(pos < 1 && pos > GetSize()){
        cout << "Task does not exist." << endl;
    } else {
        Task* cur = m_head;
        while(nodeNum < pos && cur != nullptr){
            cur = cur->m_next;
            nodeNum++;
        }
        cur->m_status = true;
       // cout << nodeNum  << " " << cur->m_description << "\nStatus: completed" << endl;
    }
}