#include <iostream>
#include <string>

using namespace  std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    bool graphs[2000][2000];
    int t, n;
    cin >> t >> n;
    int I[2000];
    for(int j=0;j<n;j++){
        cin>> I[j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graphs[I[i]][I[j]] = false;
        }
    }
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd == "insertEdge"){
            int s,d;
            cin>>s>>d;
            if(graphs[s-1][d-1]){
                cout << "Exist"<<endl;
            }else{
                graphs[s-1][d-1] = true;
                graphs[d-1][s-1] = true;
            }
        }else if(cmd == "eraseEdge"){
            int s,d;
            cin>>s>>d;
            if(!graphs[s-1][d-1]){
                cout<<"None"<<endl;
            }else{
                graphs[s-1][d-1] = false;
                graphs[d-1][s-1] = false;
            }
        }else if(cmd == "isAdjacentTO"){
            int s,d;
            cin>>s>>d;
            if(graphs[s-1][d-1]){
                cout<<"True"<<endl;
            }else{
                cout<<"False"<<endl;
            }
        }
    }
    return 0;
}

