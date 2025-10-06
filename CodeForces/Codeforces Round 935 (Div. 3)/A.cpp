#include <iostream>
using namespace std;
int solve(int a,int b,int c)
{
    int tent_sum=a;
    tent_sum+=(b/3);
    int z=b%3;
    if(z!=0)
    {
        int sum=0;
        for (int i=1;i<=c;i++)
            {
                sum+=1;
                if ((z+i)==3)
                {
                    tent_sum+=1;
                    b=0;
                    break;
                }
            }
        c=c-sum;
    }
    else
    {
        b=0;
    }
    if (b!=0)
    {
        return -1;
    }
    tent_sum+=c/3;
    c=c%3;
    if (c==1||c==2)
    {
        tent_sum+=1;
    }
    return tent_sum;    
}

int main()
{
    
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<solve(a,b,c)<<endl;
    }
   return 0; 
}