#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int arr[3];
    int avg=0;
    for (int i=0;i<3;i++)
    {
        cin>>arr[i];
        avg+=arr[i];
    }
    avg=avg/3;
    int z=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+z);
    int ans=0;
    if  (avg<=arr[1])
    {
        ans=abs(arr[0]-arr[1])+abs(arr[1]-arr[2]);
    }
    else
    {
         ans=abs(arr[2]-arr[1])+abs(arr[0]-arr[2]);      
    }
    cout<<ans<<endl;

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

