#include <iostream>
using namespace std;
void solve()
{
    int n,m;
    int A=0,B=0,C=0,D=0,E=0,F=0,G=0;
    cin>>n>>m;
    string a;
    cin>>a;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]=='A')
        {
            A+=1;
        }
        else if (a[i]=='B')
        {
            B+=1;
        }
        else if (a[i]=='C')
        {
            C+=1;
        }
        else if (a[i]=='D')
        {
            D+=1;
        }
        else if (a[i]=='E')
        {
            E+=1;
        }
        else if (a[i]=='F')
        {
            F+=1;
        }
        else if (a[i]=='G')
        {
            G+=1;
        }
    }
    cout<<A<<B<<C<<"aafa"<<D<<E<<F<<G<<endl;
    if (m>A)
    {
        sum+=(m-A);
    }
    if (m>B)
    {
        sum+=(m-B);
    }
    if (m>C)
    {
        sum+=(m-C);
    }
    if (m>D)
    {
        sum+=(m-D);
    }
    if (m>E)
    {
        sum+=(m-E);
    }
    if (m>F)
    {
        sum+=(m-F);
    }
    if (m>G)
    {
        sum+=(m-G);
    }
    cout<<sum<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}