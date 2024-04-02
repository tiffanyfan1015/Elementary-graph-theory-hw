#include<bits/stdc++.h>
using namespace std;

void mostfrequentnum(int arr[],int size){
	sort(arr,arr+size);
	int maxnum=arr[0],maxti=1;
	int temmaxti=1;
	for(int i=1;i<size;i++){
		if(arr[i]==arr[i-1]){
			temmaxti++;
			if(temmaxti>=maxti){
				maxti=temmaxti;
				maxnum=arr[i];
			}
		}
		else{
			temmaxti=1;
		}
	}
	cout<<maxnum<<" "<<maxti<<endl;
} 

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mostfrequentnum(a,n);
	return 0;
}
