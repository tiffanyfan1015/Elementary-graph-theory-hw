#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Q;
	cin>>Q;
	while(Q--){
		int n,m;
		cin>>n>>m;
		
		vector<int>se(n+1);
		int x,sum=0;
		
		for(int i=1;i<=n;i++){
			cin>>x;
			sum=sum+x;
			se[i]=x;
		}
		while(m--){
			int u,v;
			cin>>u>>v;
			se[u]--;
			se[v]--;
		}
		
		sort(se.begin()+1,se.end(),greater<int>());
		
		if(sum%2!=0||se[1]>=n||se[n]<0){
			cout<<"No"<<endl;
			continue;
		}
		
		bool check=1;
		
		int sumse[n+1];
		sumse[0]=se[0];
		sumse[1]=se[1];
		for(int i=2;i<=n;i++){
			sumse[i]=sumse[i-1]+se[i];
		}
		
		int leftsum[n+2];
		leftsum[n+1]=0;
		for(int i=n;i>=1;i--){
			leftsum[i]=leftsum[i+1]+se[i];
		}
		
		for(int k=1;k<n;k++){
			int prok = k*(k-1);
			int L=k+1,R=n;
			int rs=L-1;
			while(L<=R){
				int mid = (L+R)/2;
				if(se[mid]>=k){
					rs=mid;
					L=mid+1;
				}
				else{
					R=mid-1;
				}
			}
			int summin=k*(rs-1)+leftsum[rs+1];

			if(sumse[k]>summin){
				check=0;
				break;
			}
		}
		
		if(check){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

		
	}
}
