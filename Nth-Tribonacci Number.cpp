#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
    // vector<int>memo(n+1);
    int a=0,b=1,c=1;
    int t;
    for(int i=3;i<=n;i++){
        t=a+b+c;
        a=b;
        b=c;
        c=t;
    }
    return t;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout<<tribonacci(25)<<endl;

    return 0;
}