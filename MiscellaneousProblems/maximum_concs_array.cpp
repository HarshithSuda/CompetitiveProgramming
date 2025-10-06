#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>arr)
{
	int n=arr.size();
	int res=0,copy=0;
	bool flag=true;
	for(int i=1;i<n-1;i++)
	{
		if (arr[res]==arr[n-1])
		{
			if (n==1)
			{
				return n;
			}
			else
			{
				arr[copy]==arr[n-1];
				return copy;
			}
		}
		if ((arr[i]==arr[res] && arr[copy]<arr[i]) && flag==true)
		{
			copy=i;
			flag=false;

		}
		else if (arr[i]>arr[res] && arr[copy]<arr[i])
		{
			arr[copy]=arr[i];
			copy++;
			arr[res]=arr[i];
			flag=true;
		}
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
		vector<int>arr;
		for(int i=0;i<arr.size();i++)
		{
			int t;
			cin>>t;
			arr.push_back(t);
		}
		solve(arr);
	}
	return 0;
}
