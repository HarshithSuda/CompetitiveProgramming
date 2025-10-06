// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
    
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     vector<int>alpha(26,0);
//     int cnt=0,index_count=-1;
//     for(int i=0;i<s.length();i++){
//         // cout<<alpha[s[i]-97]<<endl;
//         // cout<<s[i]<<" "<<alpha[s[i]-97]<<endl;
//         if(alpha[s[i]-97]>=2){
//             cout<<"YES\n";
//             // cout<<"CASE1"<<endl;
//             return;
//         }
//         if(alpha[s[i]-97]==1){
//             cnt++;
//             index_count=s[i]-'a';
//             alpha[s[i]-97]++;
//             if(cnt==2){
//                 cout<<"YES\n";
//                 // cout<<"CASE2"<<endl;
//                 return;
//             }
//         }
//         else{
//             alpha[s[i]-97]++;
//         }
        
        
//     }
//     if(cnt==1 ){
//         if(s[0]==('a'+index_count) && s[n-1]==('a'+index_count)){
//             cout<<"NO\n";
//             return;
//         }
//         else{
//             cout<<"YES\n";
//             return;
//         }
//     }
    
//     cout<<"NO\n";
//     // cout<<"CASE5"<<endl;
//     return;

// }

// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif

//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }

//     return 0;
// }

# include <bits/stdc++.h>
# include <unordered_map>
using namespace std;

void solve(){
    int n;
        cin>>n;
        string s;
        cin>>s;

        unordered_map<char,int> m;

        bool flag = false;
        for(int i=0;i<n;i++){
            if(m.count(s[i]) == 0){
                m[s[i]] = i;
            }
            else{
                if(i!=n-1){
                    cout<<"yes"<<endl;
                    return;
                    flag = true;
                }
                else if(m[s[i]] !=0){
                    cout<<"yes"<<endl;
                    return;
                    flag = true;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            cout<<"no"<<endl;
            return;
        }
        cout<<"no"<<endl;
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
}