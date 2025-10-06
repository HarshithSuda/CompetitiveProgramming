#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int x,y;
        cin>>x>>y;
        if (x>=y)
        {
            cout<<y<<" "<<x<<endl;
        }
        else
        {
            cout<<x<<" "<<y<<endl;
        }
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        solve();
    }
}