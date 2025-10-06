#include<bits/stdc++.h>
using namespace std;
int solve()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int max_diff=INT_MIN;
	for (int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			max_diff=max(max_diff,arr[j]-arr[i]);
		}
	}
	return max_diff;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}