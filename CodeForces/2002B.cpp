#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if (n%2==0)
	{
		cout<<"Bob"<<endl;
		return;
	}
	vector<int>b;
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		b.push_back(t);
	}
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if (a[i]!=b[n-i-1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<"Bob"<<endl;
	}
	else
	{
		cout<<"Alice"<<endl;
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