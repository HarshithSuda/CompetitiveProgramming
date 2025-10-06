#include<bits/stdc++.h>
using namespace std;
//method 1(own efficient sol)

// int solve(){
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 	}
// 	if(n==1) return 1;
// 	int res=1,count=1;
// 	for(int i=0;i<n-1;i++){
// 		if((arr[i]%2==0 && arr[i+1]%2!=0)||((arr[i]%2)!=0) && (arr[i+1]%2==0)){
// 			count++;
// 		}
// 		else{
// 			res=max(res,count);
// 			count=1;
// 		}
// 	}	
// 	res=max(res,count);
// 	return res;
// }

//method 2 (sir efficient sol)-kadanes algorithm
int solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==1) return 1;
	int res=1,count=1;
	for(int i=0;i<n-1;i++){
		if((arr[i]%2==0 && arr[i+1]%2!=0)||((arr[i]%2)!=0) && (arr[i+1]%2==0)){
			count++;
			res=max(res,count);
		}
		else
		{
			count=1;
		}
	}
	return res;
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
		cout<<solve()<<endl;
	}
	return 0;
}