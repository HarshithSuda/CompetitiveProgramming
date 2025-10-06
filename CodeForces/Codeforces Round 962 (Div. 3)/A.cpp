#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	cout<<n/4+(n%4)/2<<"\n";
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