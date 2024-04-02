#include<bits/stdc++.h>
using namespace std;
#define N 100005
int height[N]={0};
int parent[N]={0};
int leaf[N]={0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b,c,d;
	parent[1]=-1;
	cin>>n;
	for(int i=1;i<=n-1;i++){
		cin>>a>>b;
		if(parent[a]==0){
			parent[a]=b;
			leaf[a]=1;
			leaf[b]=0;
		}
		else{
			parent[b]=a;
			leaf[b]=1;
			leaf[a]=0;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(leaf[i]==1){
			int h2=0;
			int chi=i;
			while(parent[chi]!=-1){
				h2++;
				chi=parent[chi];
				if(height[chi]<h2)
					height[chi]=h2;
				else
					break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<height[i]<<" "<<parent[i]<<endl;
	}
	return 0;
}
