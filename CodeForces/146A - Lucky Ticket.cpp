#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int z=0;
	string s;
	cin>>s;
	int sum=0;
	cout<<"HELLO";
	while(z<n-1)
	{
		char c=s.at(z);
		int r=c -'0';
		if (r==7 || r==4)
		{
			if (z>n/2)
			{
				sum+=r;
			}
			else
			{
				sum-=r;
			}
		}
		else
		{
			cout<<"NO\n";
		}		
	}
	if (sum==0)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
}