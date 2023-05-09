#include <bits/stdc++.h>
using namespace std;


void DFS(int source,int parent,vector<int>adj[],int &currtime,vector<int>&intime,vector<int>&outime){
    intime[source]=currtime++;
    for(auto it: adj[source]){
        if(it!=parent){
            DFS(it,source,adj,currtime,intime,outime);
        }
    }
    outime[source]=currtime++;
}
int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,false);
    int currtime=1;
    vector<int>intime(n+1);
    vector<int>outime(n+1);
    DFS(1,-1,adj,currtime,intime,outime);
    for(int i=1;i<=n;i++){
    cout<<i<<" --> "<<intime[i]<<"  "<<outime[i]<<endl;
    }

    return 0;
}
