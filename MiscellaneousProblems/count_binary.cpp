#include<bits/stdc++.h>
using namespace std;
int solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int c=0;
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			res=max(res,c);
			c=0;
		}
		else
		{
			c++;

		}
	}
	if(arr[n-1]==1)
	{
		res=max(res,c);
	}
	return res;
}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		cout<<solve()<<endl;
	}
	
	return 0;
}