#include<bits/stdc++.h>
using namespace std;

int min(int a,int b){
	return (a<b) ? a:b;
}

int findoverlappingpair(string str1,string str2,string &str){
	
	int max=INT_MIN;
	int len1=str1.length();
	int len2=str2.length();
	for(int i=1;i<=min(len1,len2);i++){
		if(str1.compare(len1-i,i,str2,0,i)==0){
			if(max<i){
				max=i;
				str=str1+str2.substr(i);
			}
		}
	}
	for(int i=1;i<=min(len1,len2);i++){
		if(str1.compare(0,i,str2,len2-i,i)==0){
			if(max<i){
				max=i;
				str=str2+str1.substr(i);
			}
		}
	}
	return max;
}

string superstring(string arr[],int len)
{
	while(len!=1){
		int max = INT_MIN;
		int l,r;
		string resstr;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				string str;
				int res = findoverlappingpair(arr[i],arr[j],str);
				if(max<res){
					max=res;
					resstr.assign(str);
					l=i;r=j;
				}
			}
		}
		len--;
		if(max==INT_MIN){
			int aa=0;
			for(int i=0;i<arr[0].length();i++){
				if(arr[0][i]>arr[len][i]){
					arr[0]=arr[len]+arr[0];
					aa=1;
					break;
				}
				if(arr[0][i]<arr[len][i]){
					arr[0]=arr[0]+arr[len];
					aa=1;
					break;
				}
			}
			if(aa==0)
				arr[0]=arr[0]+arr[len];
			
			
		}
		else{
			arr[l]=resstr;
			arr[r]=arr[len];
		}
	}
	return arr[0];
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string arr2[n];
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	
	for(int i=0;i<n;i++){
		if(arr2[i]=="nothing") continue;
		for(int j=i+1;j<n;j++){
			if(arr2[j]=="nothing") continue;
			int minn,maxx;
			if(arr2[i].length()>arr2[j].length())
				minn=j;
			else
				minn=i;
			maxx=i+j-minn;
			for(int k=0;k+arr2[minn].length()<=arr2[maxx].length();k++){
				if(arr2[minn]==arr2[maxx].substr(k,arr2[minn].length())){
					arr2[minn]="nothing";
					break;
				}
			}
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		if(arr2[i]!="nothing"){
			count++;
		}
	}
	string arr[count];
	int cc=0;
	for(int i=0;i<n;i++){
		if(arr2[i]!="nothing"){
			arr[cc]=arr2[i];
			cc++;
		}
	}
	
	
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<superstring(arr,len);
	return 0;
	
}
