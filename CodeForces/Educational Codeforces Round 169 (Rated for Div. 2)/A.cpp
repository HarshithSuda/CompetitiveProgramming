#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int arr[n];
	int maxn=INT_MIN;
	int minn=INT_MAX;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		maxn=max(arr[i],maxn);
		minn=min(arr[i],minn);
	}
	int arr_diff[n];
	for(int i=0;i<n-1;i++)
	{
		arr_diff[i]=arr[i+1]-arr[i];
	}
	for(int i=minn+1;i<maxn;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{

			if(arr[j]==i)
			{
				count++;
				break;
			}
		}
		if(count==1)
		{
			continue;
		}
		int arr_new[n];
		bool flag=true;
		for(int j=0;j<n-1;j++) //handle j==n-1 explicitly
		{
			
			if (arr_diff[j]<(abs(arr[j]-i)))
			{
				flag=false;
				break;
			}
		}
		if((arr[n-1]-i)>(arr_diff[n-2]))
		{
			flag=false;
		}
		if(flag==true)
		{
			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
	return;

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
		solve();
	}
}