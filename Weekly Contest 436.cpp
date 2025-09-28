    #include<bits/stdc++.h>
    using namespace std;
    
    vector<int> assignElements(vector<int>groups, vector<int>elements) {
        unordered_map<int,int>m;
        // for(int i=0;i<groups.size();i++){
        //     cout<<groups[i]<<endl;
        // }
        for(int i=0;i<groups.size();i++){
            // cout<<groups[i]<<" ";
            m.insert({groups[i],-1});
        }
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second<<" ";
        // }
        // cout<<endl;
        // cout<<m.size()<<endl;
        // vector<int>res=groups;
        unordered_map<int,int>m_ans;
        for(int i=0;i<elements.size();i++){
            for(auto it=m.begin();it!=m.end();){
                if(it->first%elements[i]==0){
                    m_ans[it->first]=i;
                    // cout<<it->first<<" "<<i<<" \n";
                    it=m.erase(it);
                }
                else{
                    ++it;
                }
            }
            // for(auto x: m){
            //     if(x.second==-1 && x.first%elements[i]==0 ){
            //         m[x.first]=i;
            //         // cout<<x.first<<endl;
            //         m_ans[x.first]=-1;
            //     }
            // }
            
        }
        if(!m.empty()){
            for(auto x:m){
                m_ans.insert({x.first,x.second});
            }
        }
        vector<int>res=groups;
        for(int i=0;i<res.size();i++){
            res[i]=m_ans[res[i]];
        }
        // cout<<endl;
        return res;
        
    }
    
    int main(){
    
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // unordered_map<int,int>m;
        // for(int i=0;i<=2;i++){
        //     m[i]=i*2;
        // }
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second;
        // }
        // cout<<endl;
        // m.erase(2);
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second;
        // }
        
        vector<int>groups={2,3,5,7};
        vector<int>elements={5,3,3};
        vector<int>ans=assignElements(groups,elements);
    
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        // int t;
        // cin>>t;
        // while(t--){
        //     solve();
        // }
    
        return 0;
    }