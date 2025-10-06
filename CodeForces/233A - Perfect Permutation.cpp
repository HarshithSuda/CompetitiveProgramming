#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	if (n&1!=0) 
	{
		cout<<-1<<endl;
		return;
	}
	int count=1;
	while(count<n)
	{
		cout<<count+1<<" "<<count<<" ";
		count+=2;
	}


}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
		solve();
		return 0;
}