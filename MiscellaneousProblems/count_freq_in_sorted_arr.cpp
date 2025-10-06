#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int count=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i-1]==arr[i])
		{
			count++;
		}
		else
		{
			cout<<arr[i-1]<<" "<<count<<"\n";
			count=1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
}