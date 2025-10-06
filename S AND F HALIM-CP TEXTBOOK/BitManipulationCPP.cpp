#include<bits/stdc++.h>
using namespace std;

// bool powerOfTwoOrNot(int n){
    


// }

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // cout<<powerOfTwoOrNot(12)<<endl;
    // cout<<powerOfTwoOrNot(24)<<endl;
    // cout<<powerOfTwoOrNot(36)<<endl;
    // cout<<powerOfTwoOrNot(2)<<endl;
    // cout<<powerOfTwoOrNot(64)<<endl;
    // cout<<powerOfTwoOrNot(4)<<endl;
    // cout<<powerOfTwoOrNot(128)<<endl;
    int n;
    cin>>n;
    cout<<~n+1<<endl;
    cout<<log2(n & -n)<<endl;



    return 0;
}