#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int l,r,L,R;
	cin>>l>>r>>L>>R;
	int minn=min(R,r);
	int maxn=max(l,L);
	int count=0;
	if (maxn==1 || minn==100)
	{
		if(maxn==1)
		{
			count++;
			maxn++;
		}
		if(minn==100)
		{
			count++;
			minn--;
		}
	}
	if (count==2)
	{
		cout<<minn-maxn+2<<endl;
		return;
	}
	if(l==L || R==r)
	{
		if (L==l)
		{
			count++;
			maxn++;
			if (count==2){
				cout<<minn-maxn+2<<endl;
				return;
			}
		}
		if(R==r)
		{
			count++;
			minn--;
			if (count==2){
				cout<<minn-maxn+2<<endl;
				return;
			}
		}
	}
	cout<<minn-maxn+2<<endl;
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

	long t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}