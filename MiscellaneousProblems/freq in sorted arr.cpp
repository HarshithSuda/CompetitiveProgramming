#include<bits/stdc++.h>
using namespace std;
void count_freq(int arr[],int n)
{
	int count=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==arr[i+1])
		{
			count++;
		}
		else
		{
			if(i==n-1)
			{
				continue;
			}
			else
			{
				cout<<arr[i]<<" "<<count<<endl;
				count=1;
			}
			
		}
		

	}
	if(n==1||arr[n-1]==arr[n-2])
		{
			if(n==1)
			{
				cout<<arr[n-1]<<" "<<count<<endl;
		
			}
			else if(arr[n-1]==arr[n-2])
			{
				cout<<arr[n-1]<<" "<<count<<endl;
			}
		}

	return;
}
int main()
{
	int arr[]={10,10,10,10};
	count_freq(arr,4);
	return 0;
}