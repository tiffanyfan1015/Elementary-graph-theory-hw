#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

vector<pair<int,int> >G[MAXN];
int infected_time[MAXN];
int protected_time[MAXN];

bool infectedornot[MAXN]={0};

void virusspread(int s){
    infectedornot[s]=1;
    for(int i=0;i<G[s].size();i++){
        if(infected_time[G[s][i].first]==-1 || infected_time[G[s][i].first]>infected_time[s]+G[s][i].second){
            infected_time[G[s][i].first]=infected_time[s]+G[s][i].second;
            virusspread(G[s][i].first);
        }
    }
    return;
}

void antivirusspread(int s){
    if(protected_time[s]<=infected_time[s]){
        infectedornot[s]=0;
        for(int i=0;i<G[s].size();i++){
            if(protected_time[G[s][i].first]==-1 || protected_time[G[s][i].first]>protected_time[s]+1){
                protected_time[G[s][i].first]=protected_time[s]+1;
                antivirusspread(G[s][i].first);
            }
        }
    }
    return;
}


signed main(){

    int n,m,p,q,t,T;
    cin>>n>>m>>p>>q>>t>>T;

	for(int i=0;i<=n;i++){
		infected_time[i]=-1;
		protected_time[i]=-1;
	}
	
    int a,b,w;
    while(m--){
        cin>>a>>b>>w;
        G[a].push_back(make_pair(b,w));
    }

    int t0[p],tta[q];
    for(int i=0;i<p;i++){
        cin>>t0[i];
    }
    for(int i=0;i<q;i++){
        cin>>tta[i];
    }

    for(int i=0;i<p;i++){
        infected_time[t0[i]]=0;
        virusspread(t0[i]);
    }
    for(int i=0;i<q;i++){
        protected_time[tta[i]]=t;
        antivirusspread(tta[i]);
    }

    int sum=0;
    for(int i=1;i<=n;i++){
        if(infectedornot[i]==1 && infected_time[i]<=T){
            sum++;
        }
    }
    cout<<sum<<endl;
}

