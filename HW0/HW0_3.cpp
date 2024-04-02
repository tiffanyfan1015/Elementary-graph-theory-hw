#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int game[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>game[i][j];
		}
	}
	int points[n]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				points[i]+=0;
			}
			else if(game[i][j]==0){
				points[i]+=b;
			}
			else if(game[i][j]==1){
				points[i]+=a;
			}
			else if(game[i][j]==2){
				points[i]+=c;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<points[i]<<" ";
	}
}
