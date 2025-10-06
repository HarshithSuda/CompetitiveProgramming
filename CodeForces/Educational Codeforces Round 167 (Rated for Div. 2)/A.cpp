#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y;
	cin>>x>>y;
	int i=1;
	while(i<=50)
	{
		
			if((i*sqrt(2))>=(sqrt(x*x+(y-i+1)*(y-i+1))))
			{
				if(i>abs(x))
				{
					cout<<"NO\n";
					return;
				}
			cout<<"YES\n";
			return;
			}
		i++;
		

		
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