#include<bits/stdc++.h>
using namespace std;
int gcd(int a ,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void solve(){
    int n;
    cin>>n;
    unordered_set<int>s;
    bool consecutive=false;
    bool twoDiffOdd=false;
    bool twoDiffEven=false;
    int count_of_ones=0;
    int count_of_twos=0;
    vector<int>arr(n);
    int count_of_even=0;
    int count_of_odd=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            count_of_ones++;
        }
        if(arr[i]==2){
            count_of_twos++;
        }
        if(arr[i]%2==0){
            count_of_even++;
        }
        else{
            count_of_odd++;
        }
        if(s.find(arr[i]+1)!=s.end() || s.find(arr[i]-1)!=s.end()){
            consecutive=true;
        }
        if(s.find(arr[i]+2)!=s.end() || s.find(arr[i]-2)!=s.end()){
            if(arr[i]%2==0){
                twoDiffEven=true;
            }
            else{
                twoDiffOdd=true;
            }   
            
        }
        s.insert(arr[i]);
    }
    if(count_of_ones!=0){
        cout<<n-count_of_ones<<"\n";
        return;
    }
    if(consecutive || twoDiffOdd || ( twoDiffEven && count_of_odd!=0) ||(count_of_twos!=0 && count_of_odd!=0) ){
        cout<<n<<"\n";
        return;
    }
    if(count_of_twos!=0 && count_of_odd==0){
        cout<<n-count_of_twos<<"\n";
        return;
    }
    int i=n-1;
    sort(arr.begin(),arr.end());
    while(i>0){
        if(gcd(arr[i],arr[0])==arr[0]){
            i--;
        }
        else{
            int x=gcd(arr[i],arr[0]);
            if(x==1){
                cout<<n<<"\n";
                return;
            }
            else if(x==2){
                if(count_of_odd){
                    cout<<n<<"\n";
                    return;
                }
                else{
                    cout<<n<<"\n";
                    return;
                }
            }
        }
    }
    

    

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<gcd(5,4);
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }

    return 0;
}