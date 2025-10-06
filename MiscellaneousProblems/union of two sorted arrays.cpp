#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	int arr1[n];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	int arr2[m];
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	int i=0,j=0;
	int prev=INT_MIN;
	while(i<n && j<n){
		if(arr1[i]>arr2[j]){
			
			if(arr2[j]!=prev){
				cout<<arr2[j]<<" ";
				prev=arr2[j];
				
			}
			j++;
			
		}
		else if(arr1[i]<arr2[j]){
			if(arr1[i]!=prev){
				prev=arr1[i];
				cout<<arr1[i]<<" ";
				
			}
			i++;	
		}
		else{
			if(arr1[i]!=prev){
				prev=arr1[i];
				cout<<arr1[i]<<" ";
					
			}
			i++;
			j++;
			
		}
	}
	if(j<m){
		for(int i=j;j<m;j++){
			if(arr2[j]!=prev){
				cout<<arr2[j]<<" ";
				prev=arr2[j];
			}
		}
	}
	else{
		for(int k=i;k<n;k++){
			if(arr1[k]!=prev){
				cout<<arr1[k]<<" ";
				prev=arr1[k];	
			}
			
		}
	}
	cout<<endl;
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		solve();	
	}
	return 0; 
}