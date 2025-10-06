#include<bits/stdc++.h>
using namespace std;
int maxpiece(int n,int a,int b,int c)
{
	if (n==0) return 0;
	if (n<0) return -1;
	int res=maxpiece(n-a,a,b,c);
	res=max(res,maxpiece(n-b,a,b,c));
	res=max(res,maxpiece(n-c,a,b,c));
	if (res==-1)
	{
		return -1;
	}
	return res+1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	cout<<maxpiece(n,a,b,c);
	return 0;
}