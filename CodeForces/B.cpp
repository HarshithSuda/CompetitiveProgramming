#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void solve()
{
    int a,b,c,d,x,y,z,t;
    cin>>a>>b>>c>>d;
    int flag=0;
    x=min(a,b);
    y=max(a,b);
    z=min(c,d);
    t=max(c,d);
    for (int i=x;i<=y;i++)
    {
        if ((z==i)||(t==i))
        {
            flag+=1;
            break;
        }
    }
    for (int i=z;i<=t;i++)
    {
        if ((x==i)||(y==i))
        {
            flag+=1;
            break;
        }
    }
    if (flag>=1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for( int i=1;i<=n;i++)
    {
        solve();
    }
}