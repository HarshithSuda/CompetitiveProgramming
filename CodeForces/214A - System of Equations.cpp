#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	int count=0;
	for (int i=0;i<32;i++)
	{
		for (int j=0;j<32;j++)
		{
			if ((i*i + j) == n && (j*j+i==m))
			{
				count++;
			}
		}
	}
	cout<<count<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
}