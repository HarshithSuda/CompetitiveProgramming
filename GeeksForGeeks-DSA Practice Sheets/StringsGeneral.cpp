#include<bits/stdc++.h>
using namespace std;
//LEARNING THE BASICS/SYNTAX
void learningBasics(string s){
    string str(10,s[2]);
    cout<<str<<endl;
}
//https://www.geeksforgeeks.org/find-the-length-of-a-string/
int M1sizeOfString(string s){
    return s.size();
}
int M2sizeOfString(string s){
    int count=0,i=0;
    while(s[i]){
        count++;
        i++;
    }
    return count;
}
int M3sizeOfString(string s){
    return s.length();
}

//https://www.geeksforgeeks.org/program-to-check-if-two-strings-are-same-or-not/
bool M1checkIfStringSame(string s1,string s2){
    int n1=s1.size(),n2=s2.size();
    if(n1!=n2){
        return false;
    }
    for(int i=0;i<n1;i++){
        if(s1[i]!=s2[i]){
            return false;
        }
    }
    return true;
}
bool M2checkIfStringSame(string s1,string s2){
    return (s1==s2);
}
//https://www.geeksforgeeks.org/program-to-search-a-character-in-a-string/
int M1findCharInString(string s,char c){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==c){
            return i;
        }
    }
    return -1;
}
int M2findCharInString(string s,char c){
    int index=s.find(c);
    return index;
}
string M1insertCharInAString(string &s,char c,int pos){
    int n=s.size();
    if(pos>n){
        return s;
    }
    string res;
    for(int i=0;i<n;i++){
        if(pos==i){
            res.push_back(c);
        }
        res.push_back(s[i]);
    }
    
    return res;
}
string M2insertCharInAString(string &s,char c,int pos){
    if(pos>s.size()){
        return s;
    }
    s.insert(s.begin()+pos,c); //s.insert(index in the form of iteration ,char to be inserted)
    return s;
}
//https://www.geeksforgeeks.org/remove-a-character-from-a-given-position/
string AddCharToTheString(string s,int pos){
    if(pos>s.size() || pos<0){
        return s;
    }
    string res;
    for(int i=0;i<s.size();i++){
        if(i==pos){
            continue;
        }
        res.push_back(s[i]);
    }
    return res;
}
string M2RemoveTheCharAtPos(string s,int pos){
    if(pos>s.size() || pos<0){
        return s;
    }
    s.erase(s.begin()+pos);
    cout<<s.size()<<endl;
    return s;
}
string M3RemoveTheCharAtPos(string s,int pos){
    if(pos>s.size() || pos<0){
        return s;
    }
    for(int i=pos;i<s.size()-1;i++){
        s[i]=s[i+1];
    }
    s.resize(s.size()-1);
    cout<<s.size()<<endl;
    return s;
}
//https://www.geeksforgeeks.org/how-to-insert-characters-in-a-string-at-a-certain-position/
string M1AddCharToTheString(string s,vector<int>arr,char c){
    for(int i=0;i<arr.size();i++){
        s.insert(s.begin()+arr[i]+i,c);
    }
    return s;
}
string M2AddCharToTheString(string s,vector<int>arr,char c){
    string z="";
    int j=0;
    for(int i=0;i<s.size();i++){
        
        if(j<arr.size() && arr[j]==i){//checking if there are stil elements left in j && if i equal to arr[j]
            z+=c;
            j++;
        } 
        z+=s[i];
    }
    return z;
}
string M1removeAllOcuurences(string s,char c){
    int i=0;
    while(s[i]){
        if(s[i]==c){
            s.erase(s.begin()+i); //erase functions reduces the size of the entire string
        }
        else{
            i++;
        }
    }
    return s;
}
string M2removeAllOcuurences(string s,char c){
    s.erase(remove(s.begin(),s.end(),c),s.end());
    return s;
}
string M3removeAllOcuurences(string s,char c){
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=c){
            s[j++]=s[i];
        }
    }
    s.resize(j);
    return s;
}
//https://www.geeksforgeeks.org/concatenation-of-two-strings/
string M1concatenation(string s1,string s2){
    return s1+s2;
}
string M2concatenation(string s1,string s2){
    string res;
    for(auto x:s1){
        res+=x;
    }
    for(auto x:s2){
        res+=x;
    }
    return res;
}
string M1reverseString(string s){
    reverse(s.begin(),s.end());
    return s;
}
string M2reverseString(string s){
    string res;
    for(int i=s.size();i>=0;i--){
        res+=s[i];
    }
    return res;
}
string M3reverseString(string s){
    int low=0,high=s.size()-1;
    while(low<=high){
        swap(s[low],s[high]);
        low++;
        high--;
    }
    return s;
}
string M4reverseString(string s){
    int low=0,high=s.size()-1;
    while(low<high){
        swap(s[low],s[high]);
        low++;
        high--;
    }
    return s;
}
string M5reverseString(string s){
    string res;
    stack<char>stack;
    for(int i=0;i<s.size();i++){
        stack.push(s[i]);
    }
    while(!stack.empty()){
        res+=stack.top();
        stack.pop();
    }
    return res;
}
void M6reverseString(string &s,int low,int high){
    if(low>=high){
        return;
    }
    swap(s[low],s[high]);

    return M6reverseString(s,low+1,high-1);
}
//https://www.geeksforgeeks.org/program-print-substrings-given-string/
void generateSubStrings(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<s.substr(i,j-i)<<endl;
        }
    }
    return;
}
//https://www.geeksforgeeks.org/check-for-binary-string/
bool isBinary(string s) {
    for(int i=0;i<s.size();i++){
        if(s[i]!='0' && s[i]!='1'){
            return false;
        }
    }
    return true;
}
//https://www.geeksforgeeks.org/camel-case-given-sentence/
string convertToCamelCase(string s) {
    string res;
    bool flag=false;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            flag=true;
        }
        else{
            if(flag){
                res+=s[i]-32;
                flag=false;
            }
            else{
                res+=s[i];
            }
        }
    }
    return res;
}
//https://www.geeksforgeeks.org/palindrome-string/
bool isPalindrome(string s) {
    stack<char>stack;
    for(int i=0;i<s.length();i++){
        stack.push(s[i]);
    }
    string res;
    while(!stack.empty()){
        res+=stack.top();
        stack.pop();
    }
    return (s==res);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //two strings code
    // string s1,s2;
    // cin>>s1>>s2;
    // cout<<M1checkIfStringSame(s1,s2)<<endl;
    // cout<<M2checkIfStringSame(s1,s2)<<endl;
    string s1="abcdeaaaa";
    string s2="xxxxx";

    cout<<isPalindrome("abba")<<endl;

    
    
    return 0;
}