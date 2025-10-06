#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int>first,second,third;
        int l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        first.push_back(l1);
        first.push_back(b1);
        first.push_back(l1*b1);
        second.push_back(l2);
        second.push_back(b2);
        second.push_back(l2*b2);
        third.push_back(l3);
        third.push_back(b3);
        third.push_back(l3*b3);
        if(first[0]==second[0] && second[0]==third[0]){
            if(first[1]+second[1]+third[1]==first[0]){
                cout<<"YES\n";
                return;
            }
        }
        else if(first[1]==second[1] && second[1]==third[1]){
            if(first[0]+second[0]+third[0]==first[1]){
                cout<<"YES\n";
                return;
            }
        }
        int maxxfirst=max(first[0],first[1]);
        int maxxsecond=max(second[0],second[1]);
        int maxxthird=max(third[0],third[1]);
        if(maxxfirst<maxxsecond){
            swap(first,second);
        }
        if(maxxfirst<maxxthird){
            swap(first,third);
        }
        // cout<<first[2]<<endl;
        if(first[0]>first[1]){
            if(second[0]+third[0]==first[0] && first[0]==first[1]+second[1] && second[1]==third[1] ){
                cout<<"YES\n";
                return;
            }
        }
        else{
            if(second[1]+third[1]==first[1] && first[1]==first[0]+second[0] && second[0]==third[0]){
                cout<<"YES\n";
                return;
            }
        }
        cout<<"NO\n";
        return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}