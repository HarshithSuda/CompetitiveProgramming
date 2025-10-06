#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	char max='a';
	unordered_map<char,int>q;
	for (auto x:s)
	{
		if (x>max)
		{
			max=x;
		}
		q[x]++;
	}
	auto it=q.find(max);
	int z=(it->second);
	while(z--)
	{
		cout<<(it->first);
	}
	cout<<endl;
	

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
}