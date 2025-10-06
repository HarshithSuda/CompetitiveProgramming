#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int n=s.length();
	if(s[0]=='1' && s[1]=='0'){
		if(s[2]=='0'){
			cout<<"NO"<<endl;
			return;
		}
		if (n==3 && s[2]=='1'){
			cout<<"NO"<<endl;
			return;
		}
		else{
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	return;
	

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