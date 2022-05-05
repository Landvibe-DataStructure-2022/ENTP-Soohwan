#include<iostream>
#include<vector>
#include<string>

using namespace std;

class heap{
private:
    vector<int>arr;
    bool compare(int idx1, int idx2);
    void swap(int idx1,int idx2);
    void upheap(int idx);
    void downheap(int idx);
public:
    heap();
    int size();
    bool empty();
    void insert(int e);
    int top();
    void pop();
    void print();
};
heap::heap(){
    arr.push_back(0);
}
int heap::size(){
    return (int)arr.size()-1;
}
bool heap::empty(){
    return size()==0;
}
void heap::insert(int e){
    arr.push_back(e);
    upheap(size());
}
int heap::top(){
    if(empty()) return -1;
    else return arr[1];
}
void heap::pop(){
    if(empty()) return ;
    swap(1,size());
    arr.pop_back();
    downheap(1);
}
void heap::print(){
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
bool heap::compare(int idx1, int idx2){
    if( arr[idx1] <= arr[idx2] )return true;
    else return false;
}
void heap::swap(int idx1,int idx2){
    arr[0] = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = arr[0];
}
void heap::upheap(int idx){
    if(idx == 1) return;
    int par = idx/2;
    if(compare(idx,par)){
        swap(par,idx);
        upheap(par);//par은 이전 idx
    }
}
void heap::downheap(int idx){
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
int main(){
    int t;
    cin >> t;
    while(t--){
        heap H;
        int n,p;
        cin >> n>>p;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            H.insert(a);
        }
        int i=0;
        while(i<n){
            if(H.top()>p)break;
            int b = H.top();
            H.pop();
            b = (b+H.top())/2;
            H.pop();
            H.insert(b);
            i++;
        }
        if(i==n){
            cout<<"False"<<endl;
        }
        else{
            cout<<i<<endl;
            H.print();
        }
        
    }
    return 0;
}
