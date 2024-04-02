#include<bits/stdc++.h>
using namespace std;

pair<long long, pair<int,int> > bridge[1000000]; 
int root[1000000];

struct cityweight{
	int name;
	long long weight;
};

bool cmp1(cityweight v1,cityweight v2){
	return v1.weight<v2.weight;
}

int parent(int a){
	while(root[a]!=a){
		root[a]=root[root[a]];
		a=root[a];
	}
	return a;
}

void union_find(int a, int b){
	int d=parent(a);
	int e=parent(b);
	root[d]=root[e];
}

long long kruskal(int howmanyedges){
	int a,b;
	long long cost, minc=0;
	for(int i=0;i<howmanyedges;i++){
		a=bridge[i].second.first;
		b=bridge[i].second.second;
		cost=bridge[i].first;
		if(parent(a)!=parent(b)){
			minc+=cost;
			union_find(a,b);
		}
	}
	return minc;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int Q;
    cin>>Q;
    while(Q--){
        int n,m;
        cin>>n>>m;
        cityweight city[n];
        int cw[n+1];
        for(int i=0;i<n;i++){
        	city[i].name=i+1;
        	cin>>city[i].weight;
        	cw[i+1]=city[i].weight;
        	root[i+1]=i+1;
		}
		sort(city,city+n,cmp1);
		cityweight minofcity = city[0];
		
		int count=0;
		for(int i=0;i<n;i++){
			int mcn=minofcity.name;
			if((i+1)!=mcn){
				long long cost=minofcity.weight+cw[i+1];
				bridge[count]=make_pair(cost,make_pair(mcn,i+1));
				count++;
			}	
		}
		
		for(int i=0;i<m;i++){
			int u,v;
			long long w;
			cin>>u>>v>>w;
			bridge[count]=make_pair(w,make_pair(u,v));
			count++;
		}
		
		int edges=n-1+m;
		sort(bridge,bridge+edges);

		long long mincost;
		mincost=kruskal(edges);
		cout<<mincost<<endl;
    }
}
