#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

string addBinary(string a, string b) {
    if(a.length()!=b.length()){
        if(a.length()>b.length()){
            string b_new(a.length()-b.length(),'0');
            // cout<<b_new.length();
            b_new.append(b);
            // cout<<b_new.length();
            b=b_new;
        }
        else{
            string a_new(b.length()-a.length(),'0');
            // cout<<a_new.length();
            a_new.append(a);
            // cout<<a_new.length();
            a=a_new;
        }
    }
    // cout<<"here1"<<endl;
    int n=a.length();
    string ans(n,' ');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    bool borrow=false;
    // cout<<"here2"<<endl;
    for(int i=0;i<n;i++){
        // cout<<"here3"<<endl;
        if(a[i]=='0' && b[i]=='0'){
            ans[i]=(borrow)?'1':'0';
            borrow=false;
        }
        else if(a[i]=='0' && b[i]=='1' ||a[i]=='1' && b[i]=='0'){
            ans[i]=(borrow)?'0':'1';
        }
        else{
            ans[i]=(borrow)?'1':'0';
            borrow=true;
        }
    }
    if(borrow){
        ans.append("1");
    }
    reverse(ans.begin(),ans.end());
    // string s=ans.
    return ans;
}


string addBinaryM2(string a,string b){
    int numA=stoi(a,nullptr,2);
    int numB=stoi(b,nullptr,2);
    int sum=numA+numB;
    if(sum==0){
        return "0";
    }
    auto binary=bitset<32>(sum);
    // cout<<binary<<" "<<typeid(binary).name()<<endl;
    string binaryString=binary.to_string();
    return binaryString.substr(binaryString.find('1'));
}

//bit manipulation method


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<addBinaryM2("1","11")<<endl;
    // cout<<addBinary("1010","1011")<<endl;
    // cout<<addBinary("1111","1111");


    return 0;
}