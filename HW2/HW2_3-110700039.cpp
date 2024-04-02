#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
vector<int> graph[MAXN];
int degree[MAXN][2];
queue <int> leaf;
bool joint[MAXN]={0};
bool visited[MAXN]={0};
vector<int> len[MAXN];
int endpoint[2];
vector<int> mainroad;

void addedge(int a,int b)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
	degree[a][0]=degree[a][0]+1;
	degree[b][0]=degree[b][0]+1;
}

void checkleafjoint(int n){
	for(int i=0;i<n;i++){
		if(degree[i][0]==1){
			leaf.push(i);
		}
		else if(degree[i][0]==3)
			joint[i]=1;
	}
}

void leaflen(){
	int endpointnum=0;
	while(leaf.empty()==0){
		int x = leaf.front();
		visited[x]=1;
		leaf.pop();
		int now=x;
		int length=0;
		int index=0;

		while(degree[now][0]!=3){
			if(visited[graph[now][index]]==0){
				visited[graph[now][index]]=1;
				if(degree[graph[now][index]][0]==3)
					visited[graph[now][index]]=0;
				length++;
				now=graph[now][index];
				index=0;
			}
			else{
				index++;
			}
		};
		
		
		
		len[now].push_back(length);
		if(len[now].size()==2){
			endpoint[endpointnum]=now;
			endpointnum++;
		}
	}
}

void findmainroad(){
	mainroad.push_back(endpoint[0]);
	int nowpoint=endpoint[0];
	while(nowpoint!=endpoint[1]){
		visited[nowpoint]=1;
		for(int i=0;i<graph[nowpoint].size();i++){
			if(visited[graph[nowpoint][i]]==0){
				if(degree[graph[nowpoint][i]][0]==3){
					mainroad.push_back(graph[nowpoint][i]);
				}
				nowpoint=graph[nowpoint][i];
				break;
			}
		} 
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		degree[i][0]=0;
	}
	
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		addedge(aa,bb);
	}
	

	
	checkleafjoint(n);

	leaflen();

	findmainroad();
	
	int m;
	cin>>m;
	int cinkey[m];
	for(int i=0;i<m;i++){
		cin>>cinkey[i];
	}
	if(m!=mainroad.size()){
		cout<<"NO";
	}
	else{
		int flag=1;
		if((cinkey[0]==len[endpoint[0]][0])||(cinkey[0]==len[endpoint[0]][1])){
			flag=0;
			for(int i=1;i<m-1;i++){
				if(cinkey[i]!=len[mainroad[i]][0]){
					flag=1;
					break;
				}
			}
			if((cinkey[m-1]!=len[endpoint[1]][0])&&(cinkey[m-1]!=len[endpoint[1]][1]))
				flag=1;
		}
		if((flag==1)&&((cinkey[0]==len[endpoint[1]][0])||(cinkey[0]==len[endpoint[1]][1]))){
			flag=0;
			for(int i=m-2;i>=1;i--){
				if(cinkey[m-i-1]!=len[mainroad[i]][0]){
					flag=1;
					break;
				}
			}
			if((cinkey[m-1]!=len[endpoint[0]][0])&&(cinkey[m-1]!=len[endpoint[0]][1]))
				flag=1;
		}

		
		if(flag==1){
			cout<<"NO";
		}
		else{
			cout<<"YES";
		}
		
	}
	
}


