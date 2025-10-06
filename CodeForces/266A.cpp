#include <iostream>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string f;
    cin>>f;
    int count=0;
    for (int i=0;i<n;i++)
    {
        if (f[i+1]==f[i])
        {
            count+=1;
        }
    }
    cout<<count<<endl;

}
int main()
{
    solve();
    return 0;
}