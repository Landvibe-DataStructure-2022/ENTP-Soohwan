#include <iostream>
#include <string>
using namespace std;

class node{
public:
    int data;
    node* next = nullptr;
};
class listQueue{
public:
    listQueue();
    bool empty();
    int size();
    int front();
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
int listQueue::front(){
    if(empty()){
        return -1;
    }
    else{
        return frontNode->data;
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
        return;
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
    int T;
    int N;
    int x;
    int y;
    
    cin>>T;
    while(T--){
        cin >> N;
        listQueue A ;
        listQueue B ;
        int Apoint = 0;
        int Bpoint = 0;
        int A_temp = 0;
        int B_temp = 0;
        for(int i=0;i<N;i++){
            cin>>x;
            A.enqueue(x);
        }
        for(int i=0;i<N;i++){
            cin>>y;
            B.enqueue(y);
        }
        for(int i=0;i<N;i++){
            x = A.front()+A_temp;
            y = B.front()+B_temp;
            if(A.front()>B.front()){
                Apoint++;
                B_temp=A.front()-B.front();
                A_temp=0;
                A.dequeue();
                B.dequeue();
            }
            else if(A.front()<B.front()){
                Bpoint++;
                A_temp=B.front()-A.front();
                B_temp=0;
                A.dequeue();
                B.dequeue();
            }
            else{
                A_temp=B_temp=0;
                A.dequeue();
                B.dequeue();
            }
        }
        if(Apoint>Bpoint){
            cout<<Apoint<<endl;
        }
        else{
            cout<<Bpoint<<endl;
        }
    }
}
