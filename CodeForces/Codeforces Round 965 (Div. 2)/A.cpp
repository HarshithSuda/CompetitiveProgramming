#include<bits/stdc++.h>
using namespace std;
void print(int x,int y)
{
	cout<<x<<" "<<y<<endl;
}
void solve()
{
	int x,y,k;
	cin>>x>>y>>k;
	if (k==1){
		print(x,y);
	}
	if(k==2){
		print(x-1,y+1);
		print(x+1,y-1);
	}
	if (k==3)
	{
		print(x,y);
		print(x-1,y-1);
		print(x+1,y+1);
	}
	if(k>3){
		if (k%2!=0){
			print(x,y);
			for(int i=1;i<=k/2;i++){
				print(x-1,y-i);
				print(x+1,y+i);
			}
		}
		else
		{
			print(x,y-1);
			print(x,y+1);
			for(int i=1;i<=k/2-1;i++){
				print(x-1,y-i);
				print(x+1,y+i);
			}
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
		solve();
	}
}