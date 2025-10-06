#include<bits/stdc++.h>
using namespace std;
void solve(int v[],int n)
{
	int v_distinct[n];
	int count=1;
	v_distinct[0]=v[0];
	int index_to_change=1;
	for(int i=1;i<n;i++)
	{
		if(v[i]>v_distinct[count-1])
		{
			v_distinct[count]=v[i];
			count++;
			v[index_to_change]=v[i];
			index_to_change++;
		}
	}
	
	return count;

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
		int n;
		cin>>n;
		int v[n];
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		solve(v,n);
	}
}