#include <iostream>
#include <vector>

using namespace std;

class heap{
public:
    heap(){
        arr.push_back(0);
    }
    int size(){
        return (int)arr.size()-1;
    }
    bool empty(){
        return size()==0;
    }
    void insert(int e){
        arr.push_back(e);
        upheap(size());
    }
    int top(){
        if(empty()) return -1;
        else return arr[1];
    }
    void pop(){
        if(empty()) return ;
        swap(1,size());
        arr.pop_back();
        downheap(1);
    }
    void print(){
        if(empty()){
            cout<<-1<<endl;
            return ;
        }
        else {
            for(int i=1;i<=size();i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
    }
private:
    vector<int>arr;
    
    bool compare(int idx1, int idx2){
        if( arr[idx1] >= arr[idx2] )return true;
        else return false;
    }
    void swap(int idx1,int idx2){
        arr[0] = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = arr[0];
    }
    void upheap(int idx){
        if(idx == 1) return;
        int par = idx/2;
        if(compare(idx,par)){
            swap(par,idx);
            upheap(par);//par은 이전 idx
        }
    }
    void downheap(int idx){
        int left = 2*idx;
        int right = 2*idx+1;
        int child;
        if(left>size()) return;
        else if(left==size())child=left;
        else{
            if(compare(left,right))child = left;
            else child = right;
        }
        
        if(compare(child,idx)){
            swap(child,idx);
            downheap(child);
        }
    }
};
int main(){
    int t;
    cin>>t;
    heap H;
    string cmd;
    while(t--){
        cin>>cmd;
        if(cmd == "insert"){
            int i;
            cin>>i;
            H.insert(i);
        }else if(cmd == "size"){
            cout << H.size() << endl;
        }else if(cmd == "isEmpty"){
            if(H.empty()){
                cout<<1<<endl;
            }else cout<<0<<endl;
        }else if(cmd == "pop"){
            cout<<H.top()<<endl;
            H.pop();
        }else if(cmd == "top"){
            cout<<H.top()<<endl;
        }else if(cmd == "print"){
            H.print();
        }
    }
    return 0;
}
