    #include<bits/stdc++.h>
    using namespace std;
    vector<int> construct(vector<int>nums){
        vector<int>results;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int c=i,z=abs(nums[i]);
            if(nums[i]>0){
                while(z>0){
                    c++;
                    c%n;
                    z--;
                }
                results.push_back(nums[c]);
            }
            else if(nums[i]<0){
                while(z>0){
                    c--;
                    if(c==-1){
                        c=n-1;
                    }
                    z--;
                }
                results.push_back(nums[c]);
            }
            else{
                results.push_back(nums[c]);
            }
        }
        return results;
    }
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        vector<int>v;
        for(int i=0;i<t;i++){
            int z;
            cin>>z;
            v.push_back(z);
        }
        vector<int>ans=construct(v);
        for(int i=0;i<t;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
        
    }