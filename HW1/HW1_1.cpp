#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int u,v,w;
    int a[n+1][n+1]={0};
    while(m--){
        cin>>u>>v>>w;
        a[u][v]=w;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
			cout<<a[i][j];
            if(j!=n){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    int count[n+1][2]={0};
    
    for(int j=1;j<=n;j++){
    	for(int i=1;i<=n;i++){
    		if(a[i][j]!=0){
    			count[j][0]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(a[i][j]!=0){
    			count[i][1]++; 
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<count[i][0]<<" "<<count[i][1]<<endl;
	}
}
