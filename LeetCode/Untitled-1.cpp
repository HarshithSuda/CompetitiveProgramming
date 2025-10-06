#include<bits/stdc++.h>
using namespace std;

int smallestAbsent(vector<int>& nums) {
    int avg=0;
        vector<bool>store(201,false);
        for(int i=0;i<nums.size();i++){
            avg+=nums[i];
            store[nums[i]+100]=true;
        }
        cout<<avg<<endl;
        avg=avg/(int)nums.size();
        cout<<avg<<endl;
        if(avg<0){
            avg=0;
        }
        cout<<avg<<endl;
        for(int i=avg+1;i<=100;i++){
            if(store[i+100]==false){
                return i;
            }
        }
        return 101;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>nums={-84,28,12};
    cout<<smallestAbsent(nums)<<endl;
    return 0;
}