#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int>ans(n);
    ans[n-1]=0;
    stack<int>st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=0;
        }
        else{
            ans[i]=st.top()-i;
        }
        st.push(i);
    }
    return ans;
}

vector<int> dailyTemperaturesMethod2(vector<int>&temperatures){
    int n=temperatures.size();
    vector<int>ans(n,0);
    stack<int>s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && temperatures[i]>temperatures[s.top()]){
            ans[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

vector<int> dailyTemperaturesMethod3(vector<int>&temperatures){
    int n=temperatures.size();
    vector<int>ans(n,0);
    ans[n-1]=0;
    int hottest=temperatures[n-1];
    for(int i=n-2;i>=0;i--){
        if(temperatures[i]>hottest){
            ans[i]=0;
            hottest=temperatures[i];
        }
        else{
            int curr=i+1;
            if(temperatures[i]<temperatures[curr]){
                cout<<temperatures[i]<<endl;
                ans[i]=1;
            }
            else{
                while(temperatures[i]>=temperatures[curr+ans[curr]]){
                    curr=curr+ans[curr];
                }
                ans[i]=curr-i+1;
            }
        }
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>temperatures={73, 74, 75, 71, 69, 72, 76, 73};
    vector<int>ans=dailyTemperaturesMethod3(temperatures);
    printVector(ans);
    return 0;
}