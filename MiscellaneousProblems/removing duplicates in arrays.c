#include<stdio.h>
void duplic(int arr[],int n)
{
    int temp[n];
    temp[0]=arr[0];
    int size=1;
    for (int i=0;i<n;i++)
    {
        int flag=1;
        for (int j=0;j<size;j++)
        {
            if (arr[i]==arr[j])
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            temp[size]=arr[i];
            size++;
        }
    }
    for (int i=0;i<size;i++)
    {
        printf("%d ",temp[i]);
    }
}
int main()
{
    int arr[]={10,20,20,30,30,30,30};
    int n=7;
    printf("hello world");
    duplic(arr,n);
    return 0;
    
}