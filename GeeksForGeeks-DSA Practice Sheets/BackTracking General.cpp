#include<bits/stdc++.h>
using namespace std;

void recPermute(int index,vector<int>&arr,vector<vector<int>>&ans){
	if(index==arr.size()){
		ans.push_back(arr);
		return;
	}

	for(int i=index;i<arr.size();i++){
		swap(arr[i],arr[index]);
		recPermute(index+1,arr,ans);
		swap(s[i],s[index]);
	}
}

vector<vector<int>> AllPermutationsOfString(vector<int>&arr){
	vector<vector<int>>ans;

	recPermute(0,arr,ans);
	sort(ans.begin(),ans.end());
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	// int t;
	// cin>>t;
	// while(t--){
	// 	solve();
	// }
	vector<string>ans;
	ans=AllPermutationsOfString("harshith");
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}