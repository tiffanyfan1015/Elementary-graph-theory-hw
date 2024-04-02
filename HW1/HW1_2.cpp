#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m,k,t;
	cin>>n>>m>>k>>t;
	int a,b;
	bool device[n+1]={0};
	vector<int> graph[n+1];
	int count=k;
	while(m--){
		cin>>a>>b;
		graph[a].push_back(b);
	}
	int kk;
	vector<int> v1,v2; 
	while(k--){
		cin>>kk;
		v1.push_back(kk);
		device[kk]=1;
	}
	for(int tt=1;tt<t;tt++){
		int check=0;
		
		if(tt%2==1){
			for(int i=0;i<v1.size();i++){
				int find=v1[i];
				for(int j=0;j<graph[find].size();j++){
					if(device[graph[find][j]]==0){
						device[graph[find][j]]=1;
						count++;
						v2.push_back(graph[find][j]);
					}
				}
			}
			if(v1.empty()&&v2.empty()){
				check=1;
				break;
			}
			while(!v1.empty()){
				v1.pop_back();
			}
		}
		else{
			for(int i=0;i<v2.size();i++){
				int find=v2[i];
				for(int j=0;j<graph[find].size();j++){
					if(device[graph[find][j]]==0){
						device[graph[find][j]]=1;
						count++;
						v1.push_back(graph[find][j]);
					}
				}
			}
			if(v1.empty()&&v2.empty()){
				check=1;
				break;
			}
			while(!v2.empty()){
				v2.pop_back();
			}
		}
		if(check==1){
			break;
		}
	}
	cout<<count<<endl;
}
