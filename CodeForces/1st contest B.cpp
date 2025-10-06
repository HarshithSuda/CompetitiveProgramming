#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,f,k;
    cin>>n>>f>>k;
    int arr_fwd[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr_fwd[i];
    }
    int value = arr_fwd[f-1];
    int z=sizeof(arr_fwd)/sizeof(arr_fwd[0]);
    sort(arr_fwd,arr_fwd+z);
    int arr_rev[n];
    for (int i=0;i<n;i++)
    {
        arr_rev[i]=arr_fwd[n-i-1];
    }
    int a=0;
    for (int i=0;i<k;i++)
    {
        if (arr_rev[i]==value)
        {
            a+=1;
            if (arr_rev[k]==value)
            {
                cout<<"MAYBE";
                break;
            }
            else
            {
                cout<<"YES";
                break;
            }
        }
    }
    if (a==0)
    {
        cout<<"NO";
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}