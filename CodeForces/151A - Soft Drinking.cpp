#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, k, l, c, d, p, nl, np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	int ans=min(((k*l)/nl),(c*d));
	ans=min(ans,(p/np));
	cout<<ans/n<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
}