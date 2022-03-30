#include <iostream>
#include <string>
using namespace std;
class node{
public:
    int data;
    node* next;
};
node *top = nullptr;

int s_size = 0;


bool Empty(){
    if(!s_size){
        return true;
    }
    else {
        return false;
    }
}
int Top(){
    if(Empty()){
        return -1 ;
    }
    else return top->data;
}
void Push(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    
    if (Empty()){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    s_size++;
}
void Pop(){
    if (Empty()){
        cout << -1 <<endl;
    }
    else {
        cout<< top->data << endl;
        top = top->next;
    }
    s_size--;
}
int main() {
    int cmdN;
    cout<<"명령어 수를 입력하세요 "<<endl;
    cin>>cmdN;
    while(cmdN--){
        string cmd;
        int _data;
        cin>>cmd;
        if(cmd=="empty"){
            if(Empty()){
                cout<<1<<endl;
            }
            else
                cout<<0<<endl;
        }
        else if(cmd=="top"){
            cout<<Top();
        }
        else if(cmd=="push"){
            cin>>_data;
            Push(_data);
        }
        else if(cmd=="pop"){
            Pop();
        }
    }
}

