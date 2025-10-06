#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long mx=-1;//elements of array are >0;
    long long c=0;
    long long s=0;
    for (int i=0;i<n;i++)
    {
        mx = max(mx,arr[i]);
        s+=arr[i];
        if ((s-mx)==mx)
        {
            c++;
        }
    }
    cout<<c<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}