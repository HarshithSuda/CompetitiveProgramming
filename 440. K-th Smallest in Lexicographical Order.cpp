#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int solve(){
    int n,k;
    cin>>n>>k;
    int highestPower=0;

    if(n<10 ||n==k){
        return k;
    }
    vector<int>v(9,0);
    
    for(int i=pow(10,9);i>=10;i/=10){
        if(n/i>0){
            highestPower=i;
            cout<<highestPower<<endl;
            int addition_factor=(highestPower-1)/9;
            fill(v.begin(),v.end(),addition_factor);
            printVector(v);
            for(int j=0;j<(n/highestPower)-1;j++){
                v[j]+=highestPower;
            }
            v[n/highestPower-1]+=n%highestPower+1;
            printVector(v);
            break;
        }
    }
    // printVector(v);
    int digit=0;
    for(int i=0;i<9;i++){
        v[i]+=((i)?v[i-1]:0);
        if(v[i]>k){
            digit=i+1;
            cout<<"digit: "<<digit<<endl;
            k-=((i)?v[i-1]:0);
            cout<<v[i-1]<<endl;
            cout<<"k :"<<k<<endl;
            break;
        }
    }
    if(k==1){
        return digit;
    }
    if(k==2){
        return digit*10;
    }
    else{
        k-=2;
        digit*=10;
        vector<int>digitsK;
        while(k>0){
            int r=k%10;
            digitsK.push_back(r);
            k/=10;
        }
        reverse(digitsK.begin(),digitsK.end());
        for(auto x:digitsK){
            cout<<x<<" ";
        }
        for(int i=0;i<digitsK.size();i++){
            digit*=10;
            digit+=digitsK[i];
        }
    }
    return digit;
    

    

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    cout<<solve()<<endl;

    return 0;
}