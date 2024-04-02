#include<bits/stdc++.h>
using namespace std;

#define int long long
#define N 200005

struct node{
    int nxt,u,v,w;
};

bool bi[N];

struct Graph{
    struct Node{
        int v;
        int dis;
        Node(int a, int b):dis(a),v(b){};
        bool operator<(const Node &a)const{
            return dis>a.dis;
        }
    };
    node edge[N];
    int tot=0;
    int head[N],id[N];
    bool vis[N];
    int d[N];
    Graph(){
        memset(head,-1,sizeof(head));
    }
    void add(int u,int v,int w){
        edge[tot]={head[u],u,v,w};
        head[u]=tot++;
    }
    void add(int u, int v,int w,int _id){
        edge[tot]={head[u],u,v,w};
        id[tot]=_id;head[u]=tot++;
    }
    void dijkstra(int S){
        priority_queue<Node>Q;
        memset(d,0x3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        d[S]=0;
        Q.push(Node(d[S],S));
        while(!Q.empty()){
            Node t=Q.top();
            Q.pop();
            int v=t.v;
            if(vis[v])
                continue;
            vis[v]=1;
            for(int i=head[v];~i;i=edge[i].nxt){
                if(d[edge[i].v]>d[v]+edge[i].w){
                    d[edge[i].v]=d[v]+edge[i].w;
                    Q.push(Node(d[edge[i].v],edge[i].v));
                }
            }
        }
    }
    int vistime=0;
    int dfn[N], low[N];
    void tarjan(int v, int u){
        dfn[v]=low[v]=++vistime;
        for(int i=head[v];~i;i=edge[i].nxt){
            if(!dfn[edge[i].v]){
                tarjan(edge[i].v,v);
                low[v]=min(low[v],low[edge[i].v]);
                if(low[edge[i].v]>dfn[v]){
                    bi[id[i]]=1;
                }
                    
            }
            else{
                if(edge[i].v!=u)
                    low[v]=min(low[v],dfn[edge[i].v]);
            }
        }
    }
}G1,G2,G3;
int n,m,u,v,w;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        G1.add(u,v,w);
        G2.add(v,u,w);
    }
    G1.dijkstra(1);
    G2.dijkstra(2);
    int s = G1.d[2];
    for(int i=0;i<G1.tot;i++){
        u=G1.edge[i].u;
        v=G1.edge[i].v;
        w=G1.edge[i].w;
        if(G1.d[u]+G2.d[v]+w==s){
            G3.add(u,v,w,i);
            G3.add(v,u,w,i);
        }
    }
    G3.tarjan(1,0);

    for(int i=0;i<G1.tot;i++){
        u=G1.edge[i].u;
        v=G1.edge[i].v;
        w=G1.edge[i].w;
        if(G1.d[v]+G2.d[u]+w<s){
            cout<<"HAPPY"<<endl;
        }
        else if(bi[i])
            cout<<"SAD"<<endl;
        else
            cout<<"SOSO"<<endl;
    }
    return 0;
}
