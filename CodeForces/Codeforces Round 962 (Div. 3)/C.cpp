#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,q;
	cin>>n>>q;
	string a,b;
	cin>>a>>b;
	for (int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		int aa[l-r+1];
		int bb[l-r+1];
		for (int i=0;i<l-r+1;i++)
		{
			aa[i]=static_cast<int>(a[l+i-1]);
			bb[i]=static_cast<int>(b[l+i-1]);
			cout<<aa[i]<<" "<<bb[i]<<endl;
		}
		int z=0;
		cout<<"hello"<<endl;
		sort(aa,aa+l-r+1);
		sort(bb,bb+l-r+1);
		for (int i=0;i<l-r+1;i++)
		{
			if (aa[i]!=bb[i])
			{
				z++;
			}
		}
		cout<<z<<endl;
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