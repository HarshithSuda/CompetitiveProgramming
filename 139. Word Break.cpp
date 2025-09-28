#include<bits/stdc++.h>
using namespace std;

void printVectorOfVector(const vector<vector<int>>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (!v[i].empty()) {
            cout << (char)('a' + i) << ": ";
            for (int x : v[i]) cout << x << " ";
            cout << "\n";
        }
    }
}

struct comp{
    bool operator()(const string&a,const string&b){
        return a.size()>b.size();
    }
};
// bool dp(int i,string &s,vector<string>&wordDict,vector<vector<int>>&alpha,vector<bool>&memo){
//     if(i==s.size()){
//         return true;
//     }
//     bool flag=false;
//     // cout<<"i"<<i<<endl;
//     // cout<<"alpha[s[i]-'a'].size()  "<<s[i]<<endl;
//     for(int j=0;j<alpha[s[i]-'a'].size();j++){
//         // cout<<"j;"<<j<<endl;
//         string temp=wordDict[alpha[s[i]-'a'][j]];
//         if(temp.size()>s.size()-i){continue;}
//         string s1(s.begin()+i,s.begin()+i+temp.size());
//         // cout<<s1<<endl; 
//         if(s1==temp){
//             // cout<<"here";
//             memo[i+temp.size()-1]=true;
//             flag=dp(i+temp.size(),s,wordDict,alpha,memo);
//             if(flag==true){
//                 break;
//             }
//         }
//     }
//     return flag;
// }

bool wordBreak(string s, vector<string>& wordDict) {
    vector<vector<int>>alpha(26);
    // sort(wordDict.begin(),wordDict.end(),comp());
    for(int i=0;i<wordDict.size();i++){
        // cout<<wordDict[i][0]-'a'<<endl;
        alpha[wordDict[i][0]-'a'].push_back(i);
    }
    vector<bool>memo(s.size(),false);
    // cout<<alpha[11].size()<<endl;
    printVectorOfVector(alpha);
    // cout<<alpha[11]<<endl;
    // vector<int>dp(s.size()-1);
    for(int i=0;i<s.size();i++){
        // cout<<indexArray.size()<<endl;
        // cout<<indexArray[0]<<endl;
        for(int j=0;j<wordDict.size();j++){
            string temp=wordDict[j];
            // cout<<temp<<endl;
            if(i>=temp.size()-1 && (i==temp.size()-1 ||memo[i-temp.size()])){
                string a=s.substr(i-temp.size()+1,temp.size());
                // cout<<temp<<endl;
                // cout<<a<<endl;
                if(temp==a){
                    // cout<<"here"<<endl;
                    // cout<<temp<<endl;
                    // cout<<a<<endl;
                    memo[i]=true;
                    break;
                };
            }
        }
    }
    return memo[s.size()-1];
}

bool dp(int i,string s,vector<string>&wordDict,vector<bool>&memo){
    if(i==0){
        return true;
    }
    if(memo[i]){
        return true;
    }

    for(string word:wordDict){
        if(i-word.size()+1<0){
            continue;
        }
        if(i>=word.size()-1 && (i==word.size()-1||dp(i-word.size(),s,wordDict,memo))){
            string z(s.begin()+i-word.size()+1,s.begin()+i+1);
            // cout<<z<<endl;
            if(z==word){
                // cout<<word<<endl;
                memo[i]=true;
                break;
            }

        }
    }
    return memo[i];
}


bool wordBreakTopDown(string s,vector<string>&wordDict){
    vector<bool>memo(s.size(),false);
    return dp(s.size()-1,s,wordDict,memo);
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string>wordDict={"apple","pen"};
    string s="applepenapple";
    cout<<wordBreakTopDown(s,wordDict)<<endl;


    return 0;
}