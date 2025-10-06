#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	int p=n*n;
	vector<int>v;;
	for (int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for (auto x:s)
		{
			int z= x -'0';
			v.push_back(z);
		}
	}
	for (int i=0;i<p;i+=(k*n))
	{
		for (int j=0;j<n;j+=k)
		{
			cout<<v[i+j];	
		}
	cout<<"\n";
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

	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}