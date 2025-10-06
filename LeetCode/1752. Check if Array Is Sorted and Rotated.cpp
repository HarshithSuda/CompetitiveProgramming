#include<bits/stdc++.h>
using namespace std;
void print(vector<int> nums)
{
	int n=nums.size();
	for(int i=0;i<n;i++)
	{
		cout<<nums[i]<< " ";
	}
	cout<<endl;

}
bool solve(vector<int> nums)
{
	vector<int> v = nums;
       
       for(int i=0;i<nums.size();i++){

            reverse(v.begin(),v.end());
            print(v);
            reverse(v.begin(),v.begin()+i);
            print(v);
            reverse(v.begin()+i,v.end());
            print(v);
            if(is_sorted(v.begin(),v.end())==true)
            {
            	cout<<i<<endl;
            	return true;
            } 
            v=nums;
       }
       
        
        return false;
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
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<((solve(arr))?"YES":"NO")<<endl;
	}
}