#include<bits/stdc++.h>
using namespace std;
int getwater(int arr[],int n)
{
	int res=0;
	int lmax[n],rmax[n];
	lmax[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		lmax[i]=max(arr[i],lmax[i-1]);
	}
	for(int i=n-2;i>=0;i--)
	{
		rmax[i]=max(arr[i],rmax[i+1]);
	}
	for(int i=1;i<n-1;i++)
	{
		res+=min(lmax[i],rmax[i])-arr[i];
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
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<getwater(arr,n)<<"\n";
	}
	return 0;
}