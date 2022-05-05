#include <iostream>
#include <string>
using namespace std;

class node{
public:
    int data;
    node* next;
};
class listQueue{
public:
    listQueue();
    bool empty();
    int size();
    void front();
    void rear();
    void enqueue(int);
    void dequeue();
private:
    node* frontNode;
    node* rearNode;
    int n;
};
listQueue::listQueue(){
    frontNode=NULL;
    rearNode=NULL;
    n=0;
}
bool listQueue::empty(){
    return (n==0);
}
int listQueue::size(){
    return n;
}
void listQueue::front(){
    if(empty()){
        cout << "Empty" << endl;    }
    else{
        cout << frontNode->data << endl;
    }
}
void listQueue::rear() {
    if (empty()) {
        cout << "Empty" << endl;
    } else {
        cout << rearNode->data << endl;
    }
}
void listQueue::enqueue(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (empty()){
        frontNode = rearNode = newNode;
    }
    else {
        rearNode -> next = newNode;
        rearNode = newNode;
    }
    n++;
}
void listQueue::dequeue(){
    if(empty()){
        cout << "Empty" << endl;
    }
    node* curNode = frontNode;
    if(size() == 1){
        frontNode = rearNode = NULL;
    }
    else{
        frontNode = frontNode -> next;
    }
    delete curNode;
    n--;
}
int main() {
    int t;
        cin >> t;
        listQueue q;

        while (t--) {
            string cmd;
            cin >> cmd;

            if (cmd == "enqueue") {
                int value;
                cin >> value;
                q.enqueue(value);
            }
            else if (cmd == "dequeue") {
                q.dequeue();
            }
            else if (cmd == "isEmpty") {
                if (q.empty()) {
                    cout << "True" <<endl;
                } else {
                    cout << "False" <<endl;
                }
            }
            else if (cmd == "size") {
                cout << q.size() << endl;
            }
            else if (cmd == "front") {
                q.front();
            }
            else if (cmd == "rear") {
                q.rear();
            }
        }

        return 0;
}
