#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int temp,max,min=0;
	int count=0;
	for (int i=0;i<n;i++)
	{
		cin>>temp;
		if (i==0)
		{
			max=temp;
			continue;
		}	
		if (temp!=max && count<1)
		{
			if (temp>max)
			{
				count++;
				min=max;
				max=temp;
			}
			if (temp<max)
			{
				count++;
				min=temp;
			}
		}
		if (temp>max)
		{
			count++;
			max=temp;
		}
		if (temp<min)
		{
			count++;
			min=temp;
		}
	}
	cout<<count<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif

	solve();
}