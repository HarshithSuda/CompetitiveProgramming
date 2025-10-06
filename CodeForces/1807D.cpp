#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,q;
    cin>>n>>q;
    const int s1=2e5+10;
    int arr[s1];
    long long sum[s1];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        if (i==0)
        {
            sum[0]=arr[0];
        }
        else
        {
            sum[i]=sum[i-1]+arr[i];
        }
    }
    
    while(q--)
    {
        
        int l,r,k;
        cin>>l>>r>>k;
        if ((sum[n]-(sum[r]-sum[l-1])+(k*(r-l+1)))%2==1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

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