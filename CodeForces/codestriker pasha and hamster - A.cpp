#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int arr1[a];
    int arr2[b];
    for (int i=0;i<a;i++)
    {
        cin>>arr1[i];
    }
    for (int i=0;i<b;i++)
    {
        cin>>arr2[i];
    }
    int m;
    for (int i=1;i<=n;i++)
    {
        int m=0;
        for (int j=0;j<a;j++)
        {
            if (i==arr1[j])
            {
                cout<<1<<" ";
                m+=1;
                
            }
            
        }
        if (m==1)
        {
            continue;
        }
        
        for (int j=0;j<b;j++)
        {
            if (i==arr2[j])
            {
                cout<<2<<" ";
            }
            
        }
        
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}