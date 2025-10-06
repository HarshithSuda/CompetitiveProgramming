#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void recPermute(int index,string &s,vector<string>&ans){
    if(index==s.size()){
        ans.push_back(s);
        return;
    }

    for(int i=index;i<s.size();i++){
        swap(s[i],s[index]);
        recPermute(index+1,s,ans);
        swap(s[i],s[index]);
    }
}
void mainFunctionForPermute(string s){
    vector<string>ans;
    recPermute(0,s,ans);
    // sort(ans.begin(),ans.end());
    // for(auto x:ans){
    //     cout<<x<<endl;
    // }
    // cout<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto start1=high_resolution_clock::now();

    int N=11;
    int p[11];
    for(int i=0;i<N;i++){
        p[i]=i;
    }
    vector<string>res;
    do{
        string s;

        for(int i=0;i<N;i++){
            s.insert(s.begin()+i,'A'+p[i]);
        }
        res.push_back(s);
    }while(next_permutation(p,p+N));
    
    auto end1=high_resolution_clock::now();

    auto duration1=duration_cast<milliseconds>(end1-start1);
    cout<<"time using next permutation: "<<duration1.count()<<"milliseconds \n";

    auto start2=high_resolution_clock::now();
    mainFunctionForPermute("ABCDEFGHIJK");
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<milliseconds>(end2-start2);
    cout<<"time for recursive solution: "<<duration2.count()<< " milliseconds\n";
    return 0;
}