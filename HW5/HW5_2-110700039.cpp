#include<bits/stdc++.h>
using namespace std;

#define N 100

vector<int> G[N];

void addedge(int a, int b)
{
    G[a].push_back(b);
    G[b].push_back(a);
};

signed main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int f,s;
        cin>>f>>s;
        addedge(f,s);
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        int siz=G[i].size();
        if(ans>siz){
            ans = siz;
        }
    }
    cout<<ans<<endl;
}
