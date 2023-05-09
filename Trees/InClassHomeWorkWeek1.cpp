#include <bits/stdc++.h>
using namespace std;


void DFS(int source,int parent,vector<int>adj[],int &currtime,vector<int>&intime,vector<int>&outime,vector<int>&par,vector<int>&sub){
    par[source]=parent;
    sub[source]=1;
    intime[source]=currtime++;
    for(auto it: adj[source]){
        if(it!=parent){
            DFS(it,source,adj,currtime,intime,outime,par,sub);
            sub[source]+=sub[it];
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
    // vector<int>vis(n,false);
    int currtime=1;
    vector<int>intime(n+1);
    vector<int>outime(n+1);
    vector<int>parent(n+1);
    vector<int>sub(n+1);
    DFS(1,-1,adj,currtime,intime,outime,parent,sub);
    // for(int i=1;i<=n;i++){
    // cout<<i<<" --> "<<intime[i]<<"  "<<outime[i]<<endl;
    // }
    // for(int i=1;i<=parent.size()-1;i++){
    //     cout<<i<<" --> "<<parent[i]<<endl;
    // }
    //Finding the path for 9
    // int node=9;
    // cout<<node<<" ";
    // while(parent[node]!=-1){
    //     cout<<parent[node]<<" ";
    //     node=parent[node];
    // }
    
    //Finding number of children of each node
    //Or finding number of nodes in subtree
    for(int i=1;i<=sub.size()-1;i++){
        cout<<i<<" --> "<<sub[i]<<endl;
    }
    return 0;
}
