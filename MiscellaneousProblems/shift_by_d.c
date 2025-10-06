#include<stdio.h>
void shift_by_d(int arr[],int n,int d)
{
    int temp[d];
    for (int i=0;i<d;i++)
    {
        temp[i]=arr[i];
    }
    for (int i=d;i<n;i++)
    {
        arr[i-d]=arr[i];
    }
    for (int i=0;i<d;i++)
    {
        arr[n-d+i]=temp[i];
    }
}
int main()
{
    int arr[]={10,5,30,15};
    int n=4;
    int d=3;
    shift_by_d(arr,n,d);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}