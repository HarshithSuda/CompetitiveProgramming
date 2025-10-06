#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int sum=0;
	int test;
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>test;
			if (i+j==n+1 || i==j||i==(n+1)/2||j==(n+1)/2)
			{
				sum+=test;
			}
		}
	}
	cout<<sum<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
} 