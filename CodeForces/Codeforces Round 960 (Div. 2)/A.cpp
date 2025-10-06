#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int arr[n];
	int maxi=INT_MIN;
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
		maxi=max(maxi,arr[i]);

	}
	map<int,int> element;
	for (int i=0;i<n;i++)
	{
		element[arr[i]]++;
	}
	int z= sizeof(arr)/sizeof(arr[0]);
	set<int> setele(arr,arr+z);
	int l=setele.size();
	int k=element.size();
	if (element[l]%2!=0)
	{
		cout<<"YES"<<endl;
		return;
	}
	for (int i=l-1;i>=0;i++)
	{
		auto it = element.find(setele[i]);
		if ((it->second)%2!=0)
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	return;

}
int main()
{
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