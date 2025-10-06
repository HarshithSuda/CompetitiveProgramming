#include <iostream>
using namespace std;
void solve(int n,int m,int a)
{
    
    if(isdigit(((n*m)/(a*a))))
    {
        cout<<(n*m)/a;
    }
    else
    {
        cout<<((n*m)/(a*a))+1;
    }
}
int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    solve(n,m,a);
    return 0;
}