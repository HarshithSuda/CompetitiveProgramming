#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long arr_a[n];
    long long arr_b[n];
    long long sum_a=0;
    long long sum_b=0;
    for (long long i=0;i<n;i++)
    {
        cin>>arr_a[i];
    }
    for (long long i=0;i<n;i++)
    {
        cin>>arr_b[i];
    }
    long long ans=0;
    int z=sizeof(arr_a)/sizeof(arr_a[0]);
    long long &min_a= *min_element(arr_a,arr_a+z);
    long long &min_b= *min_element(arr_b,arr_b+z);
    for (int i=0;i<n;i++)
    {
        int res1=0,res2=0;
        res1+=(arr_a[i]-min_a);
        res2+=(arr_b[i]-min_b);
        ans+=max(res1,res2);
    }
    cout<<ans<<endl;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}