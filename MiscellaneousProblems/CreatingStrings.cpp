#include<bits/stdc++.h>
using namespace std;

void recPermute(string s,int index,set<string>&store){
    if(index==s.length()-1){
        store.insert(s);
    }
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        recPermute(s,index+1,store);
        swap(s[index],s[i]);
    }
    return;
}
void BackTrackingString(string s){
    vector<string>res;
    set<string>store;
    recPermute(s,0,store);
    cout<<store.size()<<"\n";
    for(auto x: store){
        cout<<x<<"\n";
    }
    cout<<"\n";
    return;
    
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string s;
    cin>>s;
    BackTrackingString(s);


    return 0;
}