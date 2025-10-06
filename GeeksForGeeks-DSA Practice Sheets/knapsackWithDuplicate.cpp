#include<bits/stdc++.h>
using namespace std;


int knapSack(vector<int>& val, vector<int>& wt, int capacity){
	map<int,int>m;
	for(int i=0;i<wt.size();i++){
		m[wt[i]]=val[i];
	}
	for(int i=0;i<val.size();i++){
		cout<<wt[i]<< " "<<val[i]<<" ";
	}
	cout<<endl;
	int p=0;
	for(auto x:m){
		int weight=x.first;
		int value=x.second;
		val[p]=value;
		wt[p]=weight;
		p++;
	}
	for(int i=0;i<val.size();i++){
		cout<<wt[i]<< " "<<val[i]<<" ";
	}
	cout<<endl;
	int dp[val.size()][capacity+1];
	for(int i=0;i<val.size();i++){
		for(int j=0;j<=capacity;j++){
			if(j<wt[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i]]+val[i]);
			}
		}
	}
	for(int i=0;i<val.size();i++){
		for(int j=0;j<=capacity;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return dp[val.size()][capacity];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

// 	int t;
// 	cin>>t;
// 	while(t--){
// 		solve();
// 	}
	vector<int>val={6, 1, 7, 7};
	vector<int>wt={1, 3, 4, 5};
	int capacity=8;
	cout<<knapSack(val,wt,capacity)<<endl;
	return 0;	
}