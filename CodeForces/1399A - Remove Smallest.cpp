#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for (int i=1;i<n;i++)
	{
		if (abs(arr[i]-arr[i-1])!=1 && (abs(arr[i]-arr[i-1])!=0))
		{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}