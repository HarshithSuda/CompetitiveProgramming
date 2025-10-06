#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
    long n;
    cin>>n;
    long arr[n];
    long count=0;
    for (long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (long long i=0;i<n;i++)
    {
        sort(arr,arr+i+1);
        long long sum=0;
        for (long long j=0;j<i;j++)
        {
            sum+=arr[j];
        }

        if (sum==arr[i])
        {
            count+=1;
        }
        
    }
    cout<<count<<endl;
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