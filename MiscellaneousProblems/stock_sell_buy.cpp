#include<bits/stdc++.h>
using namespace std;
int maxProfit(int prices[],int start,int end)
{
    if(start>=end)
    {
        return 0;
    }
    int profit=0;
    for(int i=start;i<end;i++)
    {
        for(int j=i+1;j<=end;j++)
        {
            if(prices[j]>prices[i])
            {
                int curr_profit=prices[j]-prices[i]+maxProfit(prices,start,i-1)+maxProfit(prices,j+1,end);
                profit=max(profit,curr_profit);
            }
        }
    }
    return profit;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    int start=0;
    int end=n-1;
    cout<<maxProfit(prices,0,n-1)<<endl;
    return 0;

}