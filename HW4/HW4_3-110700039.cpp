#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 1010
#define INF 65535

struct edge{
	int to;
	int cap;
	int rev;
};

vector<edge>G[MAXVEX];
bool used[MAXVEX];

void addEdge(int from, int to ,int cap){
	edge e;
	e.cap = cap;
	e.to=to;
	e.rev=G[to].size();
	G[from].push_back(e);
	e.to=from;
	e.cap=0;
	e.rev=G[from].size()-1;
	G[to].push_back(e);
}

int dfs(int v, int t, int f){
	if(v==t)
		return f;
	used[v]=true;
	for(int i=0;i<G[v].size();++i){
		edge &e = G[v][i];
		if(!used[e.to] && e.cap >0){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow = 0;
	for(;;){
		memset(used,0,sizeof(used));
		int f = dfs(s,t,INF);
		if(f==0)
			return flow;
		flow+=f;
	}
}

int main(){
	int n,m,k;
    cin>>n>>m>>k;
    
    addEdge(0,1,n);
    addEdge(0,2,k);

    for(int i=3;i<=2+n;i++){
        addEdge(1,i,1);
        addEdge(2,i,1);
    }

    for(int i=1;i<=n;i++){
        int ti;
        cin>>ti;
        for(int j=0;j<ti;j++){
        	int Mij;
        	cin>>Mij; 
			addEdge(2+i,2+n+Mij,1);
		}
    }

    for(int i=1;i<=m;i++){
        addEdge(2+n+i,2+n+m+1,1);
    }
    
    cout<<max_flow(0, 2+n+m+1)<<endl;

    
    return 0;
}
