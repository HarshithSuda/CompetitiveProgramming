#include<bits/stdc++.h>
using namespace std;

void push(vector<int>&arr,int x){
    arr.push_back(x);
    return;
}

void pop(vector<int>&arr){
    if(arr.empty()){
        return;
    }
    arr.pop_back();
    return;
}

int peek(vector<int>&arr){
    if(!arr.empty()){
        return arr[arr.size()-1];
    }
    return -1;
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<int>arr;
    push(arr,10);
    push(arr,20);
    push(arr,30);
    push(arr,40);
    push(arr,50);
    cout<<peek(arr)<<endl;
    pop(arr);
    pop(arr);
    pop(arr);
    pop(arr);
    pop(arr);
    cout<<peek(arr)<<endl;

    return 0;
}