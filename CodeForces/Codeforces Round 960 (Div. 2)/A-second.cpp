#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int target;
	cin>>target;
	long long n;
	cin>>n;
	long long arr[n];
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int i=0,j=n-1;
	while(j>i)
	{
		if (arr[i]+arr[j]==target)
		{
			cout<<i<<" "<<j<<endl;
			return;
		}
		else if (arr[i]+arr[j]>target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
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