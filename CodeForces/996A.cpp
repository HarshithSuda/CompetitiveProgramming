	#include<bits/stdc++.h>
	using namespace std;


	void solve(){
		long long n;
		cin>>n;
		vector<long long>value={0,1,5,10,20,100};
		long long dp[6][n+1];
		for(long long i=0;i<=n;i++){
			dp[0][i]=INT_MAX;
		}
		for(long long i=0;i<6;i++){
			dp[i][0]=0;
		}
		for(long long i=1;i<6;i++){
			for(long long j=1;j<=n;j++){
				if(j-value[i]<0){
					dp[i][j]=dp[i-1][j];
				}
				else{
					dp[i][j]=min(dp[i-1][j],dp[i][j-value[i]]+1);
				}
				
			}
		}
		cout<<dp[5][n]<<"\n";
		return;
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
		solve();
		return 0;	
	}