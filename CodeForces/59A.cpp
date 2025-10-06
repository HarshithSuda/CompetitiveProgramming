#include <iostream>
using namespace std;
void solve()
{
    string a;
    cin>>a;
    int count=0;
    int lower=0;
    int upper=0;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]>=65 && a[i]<=90)
        {
            upper+=1;
        }
        else if (a[i]>=97 && a[i]<=122)
        {
            lower+=1;
        }
    }
    if (lower>=upper)
    {
        for (int i=0;i<a.size();i++)
        {
            if (a[i]>=65 && a[i]<=90)
            {
                a[i]=a[i]-'A'+97;
            }
        }
        cout<<a<<endl;
    }
    else
    {
        for (int i=0;i<a.size();i++)
        {
            if (a[i]>=97 && a[i]<=122)
            {
                a[i]=a[i]-'a'+65;
            }
        }
        cout<<a<<endl;
    }
}
int main()
{
    solve();
    return 0;
}
