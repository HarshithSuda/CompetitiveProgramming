#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string f;
    cin>>f;
    string arr;
    for (char c:f)
    {
        if (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U'&&c!='Y'&&c!='y')
        {
            arr.push_back(c);
        }
    }
    int n=arr.size();
    for (int i=0;i<n;i++)
    {
        if(arr[i]>='A'&&arr[i]<='Z')
        {
            arr[i]=arr[i]-'A'+97;
        }
    }
    cout<<".";
    for (int i=0;i<n-1;i++)
    {
        cout<<arr[i]<<".";
    }
    cout<<arr[n-1];
    return 0;

}