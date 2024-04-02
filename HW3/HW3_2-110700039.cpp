#include<bits/stdc++.h>
using namespace std;

#define N 200005
#define pi pair<int,long long>

struct cmp{
	bool operator()(const pi &a, const pi&b){
		return a.second>b.second;
	}
};

priority_queue<pi, vector<pi>,cmp> pq;
vector<pi> G[N];

long long D[N];
long long D2[N];
long long D3[N];
long long D33[N];

void dijsktra(long long n, long long start){
	
	for(int i=1;i<=n;i++){
		D[i]=LONG_MAX;
	}
	D[start]=0;
	pq.push(pi(start,0));
	
	while(!pq.empty()){
		long long uu;
		uu=pq.top().first;
		pq.pop();
		long long sz=G[uu].size();
		for(long long i=0;i<sz;i++){
			long long vv=G[uu][i].first;
			long long ww=G[uu][i].second;
			if(D[uu]+ww<D[vv]){
				D[vv]=D[uu]+ww;
				pq.push(pi(vv,D[vv]));
			}
		}
	}	
}

void dijsktra2(long long n, long long start){
	
	for(int i=1;i<=n;i++){
			D2[i]=LONG_MAX;
	}
	D2[start]=0;
	pq.push(pi(start,0));
	
	while(!pq.empty()){
		long long uu;
		uu=pq.top().first;
		pq.pop();
		long long sz=G[uu].size();
		for(long long i=0;i<sz;i++){
			long long vv=G[uu][i].first;
			long long ww=G[uu][i].second;
			if(D2[uu]+ww<D2[vv]){
				D2[vv]=D2[uu]+ww;
				pq.push(pi(vv,D2[vv]));
			}
		}
	}	
}

void dijsktra3(long long n, long long start){
	
	for(int i=1;i<=n+1;i++){
			D3[i]=LONG_MAX;
	}
	D3[start]=0;
	pq.push(pi(start,0));
	
	while(!pq.empty()){
		long long uu;
		uu=pq.top().first;
		pq.pop();
		long long sz=G[uu].size();
		for(long long i=0;i<sz;i++){
			long long vv=G[uu][i].first;
			long long ww=G[uu][i].second;
			if(D3[uu]+ww<D3[vv]){
				D3[vv]=D3[uu]+ww;
				pq.push(pi(vv,D3[vv]));
			}
		}
	}	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long T,sub,n,m,k;
	cin>>T>>sub;
	while(T--){

		for(long long i=0;i<N;i++){
			G[i].clear();
		}
		
		cin>>n>>m>>k;
		while(m--){
			long long u,v,w;
			cin>>u>>v>>w;
			G[v].push_back(pi(u,w));
		}
		
		dijsktra(n,1);
		
		
		if(k==1){
			for(long long i=1;i<=n;i++){
				if(D[i]==LONG_MAX)
					cout<<-1<<" ";
				else{
					cout<<D[i]<<" ";
				}	
			}
		}
		else if(k==2){
			dijsktra2(n,n);
			for(long long i=1;i<=n;i++){
				D33[i]=0;
				if(D[i]!=LONG_MAX&&D2[i]!=LONG_MAX)
					G[n+1].push_back(pi(i,D[i]+D2[i]));
			} 
			dijsktra3(n+1,n+1);
			for(long long i=1;i<=n;i++){
				if(D3[i]==LONG_MAX){
					cout<<-1<<" ";
				}
				else
					cout<<D3[i]<<" ";
			}
		}
		cout<<endl;
	}

}

