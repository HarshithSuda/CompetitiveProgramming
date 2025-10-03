#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    char ch;
    while(infile.get(ch)){
        if(ch=='['){
            ch='{';
        }
        else if(ch==']'){
            ch='}';
        }
        outfile.put(ch);
    }
    infile.close();
    outfile.close();

    return 0;
}