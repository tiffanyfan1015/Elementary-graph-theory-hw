#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define MAXN 100000

vector<int> G[MAXN];
bool vis[MAXN]={0}, cv[MAXN]={0}; //cv=cut vertex

int parent[MAXN]={-1};
int dfn[MAXN]={0};
int low[MAXN]={0};


void addedge(int a, int b)
{
    G[a].push_back(b);
    G[b].push_back(a);
}

void dfs(int u){ 
    static int count = 0;
    int children = 0;

    dfn[u]=++count;
    low[u]=dfn[u];
    vis[u]=true;

    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v]){ 
            children++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);

            if(((parent[u]==-1||parent[u]==0) && children >=2) || ((parent[u]!=-1 && parent[u]!=0) && low[v]>=dfn[u]))
                cv[u]=1;
        }
        else if(v != parent[u])
            low[u]=min(low[u],dfn[v]);
    }
}

signed main(){
    int n,m;
    cin>>n>>m;
    int v1,v2;
    while(m--){
        cin>>v1>>v2;
        addedge(v1,v2);
    }
    dfs(1);

    int sum=0;
    for(int i=1;i<=n;i++){
        if(cv[i]!=0){
            sum++;
        }
    }
    cout<<sum<<endl;
    for(int i=1;i<=n;i++){
        if(cv[i]!=0){
            cout<<i<<" ";
        }
    }
    cout<<endl;



}

