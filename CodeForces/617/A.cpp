#include <iostream>
using namespace std;
void solve(int n)
{
    if (n%5==0)
    {
        cout<<n/5;
    }
    else
    {
        cout<<n/5+1;
    }
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
    
}