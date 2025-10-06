#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum=0;
    while(b>=a)
    {
        a=a*3;
        b=b*2;
        sum+=1;
    }
    cout<<sum<<endl;
    return 0;
}