#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
class singlyLInkedList{
public:
    singlyLInkedList();
    bool empty();
    void append(int data);
    void insertion(int idx, int data);
    void deletion(int idx);
    void print();
    
private:
    node* head;
    node* tail;
    int listSize;
};
singlyLInkedList::singlyLInkedList(){
    head = NULL;//비어 있으므로 초기화
    tail = NULL;//비어 있으므로 초기화
    listSize=0;
}
bool singlyLInkedList::empty(){//Linked List가 비어있는지 여부
    if(listSize == 0){
        return true;
    }
    else{
        return false;
    }
}
void singlyLInkedList::append(int data){
    node* newNode = new node; //새로운 Node 동적할당
    newNode->data = data; //새로운 Node에 data넣고
    newNode->next = NULL; //새로운 Node의 next ptr은 NULL
    
    if (empty()){
        head = tail = newNode;
    }//tail이 NULL인 경우에 대한 예외 처리
    else {
        tail -> next = newNode;
        tail = newNode;
    }
    listSize++;
}
void singlyLInkedList:: insertion(int idx, int data){
    if (idx <0 || idx > listSize){
        return;
    }
    else if(idx == listSize){
        append(data);//list size랑 index가 같으면 걍 추가랑 다름없음
    }
    else if(idx == 0){ //새로운 Node가 Linked List맨 앞에 추가되는 경우
        node* newNode =new node; //새로운 Node를 동적할당 해주고
        newNode->data = data;// 새로운 Node에 Data넣고
        newNode->next = head;// 새로운 Node의 next ptr은 기존의 head
        head = newNode;// 지금 부터 head는 새로운 Node
        listSize++; //listSize 하나 커졌자나
    }
    else{
        node* newNode = new node;
        newNode->data = data;
        node* curNode = head;//0번째 index를 가리킴
        for (int i = 1; i < idx; i++){
            curNode = curNode-> next;
        }
        newNode -> next = curNode -> next; // 새로운 Node의 next ptr은 curNode의 next ptr
        curNode -> next = newNode; // curNode의 next ptr은 이제 newNode를 가리킨다.
        listSize++;
        
    }
}
void singlyLInkedList::deletion(int idx){
    if(empty()|| idx <0 || idx>= listSize){
        return;
    }
    
    node* curNode = head;//삭제할 Node
    if (idx == 0){//삭제할 Node가 Head인 경우
        if (listSize == 1){
            head = tail = NULL;
        }
        else{
            head = head -> next;
        }
    }
    else{
        node*preNode = head;//
        for(int i = 0; i < idx; i++){
            preNode = curNode;
            curNode = curNode->next;
        }
        preNode->next = curNode->next;
        if(curNode == tail){
            tail = preNode;
        }
        
    }
    delete curNode;
    listSize--;
}
void singlyLInkedList::print(){
    if(empty()){
        cout<< "empty";
    }
    node* curNode = head;
    while (curNode != NULL){
        cout<< curNode->data<<" ";
        curNode = curNode->next;
    }
    cout << endl;
}
int main() {
}

