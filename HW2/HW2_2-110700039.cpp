#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
vector<int> graph[MAXN];

void addedge(int a,int b)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
}

int findlength(int u, int v,int nn){
	int distance[nn+1];
	int travel[nn+1]={0};
	if(u==v){
		return 0;
	}
	stack<int> stk;
	stk.push(u);
	distance[u]=0;
	travel[u]=1;
	while(stk.empty()==0){
		int x=stk.top();
		stk.pop();
		for(int i=0;i<graph[x].size();i++){
			if(travel[graph[x][i]]==0){
				stk.push(graph[x][i]);
				travel[graph[x][i]]=1;
				distance[graph[x][i]]=distance[x]+1;
			}
			if(graph[x][i]==v){
				return distance[graph[x][i]];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		addedge(aa,bb);
	}


	int Q;
	cin>>Q;
	while(Q--){
		int uu,vv;
		cin>>uu>>vv;
		cout<<findlength(uu,vv,n)<<endl;
	}
	return 0;
}
