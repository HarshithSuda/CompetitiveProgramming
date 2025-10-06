#include<bits/stdc++.h>
using namespace std;

int solve(int n,double l,double w){
    vector<pair<int,int>>p(n);
    vector<pair<double,double>>range;
    // int cn=0;
    for(int i=0;i<n;i++){
        int first,second;
        scanf("%d %d",&first,&second);
        p[i].first=first;
        p[i].second=second;
        // cout<<cn++<<endl;
        if(2*second>=w){
        double dx=sqrt(abs((double)(p[i].second*p[i].second)-(w*w)/4.0));
        // cout<<dx<<endl;
        range.push_back(make_pair((double)p[i].first-dx,(double)p[i].first+dx));
        }
        
   }
   
    sort(range.begin(),range.end(),[](pair<double,double>&a,pair<double,double>&b){if(a.first==b.first){
    return a.second<b.second;} return a.first<b.first;});
    // for(auto x: range){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
   vector<int>ans;
   int i=0,ans_index=-1;
   double left=0,right=0;
   while(i<range.size()){
    // cout<<"here"<<endl;
        if(left>=range[i].first){
            if(right<range[i].second){
                ans_index=i;
                if(range[ans_index].second>=l){
                    return ans.size()+1;
                }
            }
            i++;
        }
        else{
            if(ans_index==-1 || range[ans_index].second<range[i].first){
                return -1;
            }
            // cout<<range[ans_index].second<<endl;
            // cout<<l<<endl;
            // cout<<(range[ans_index].second>=l)<<endl;
            if(range[ans_index].second>=l){
                // cout<<"here1\n";
                return ans.size()+1;
            }
            ans.push_back(ans_index);
            left=right=range[ans_index].second; 
            continue;
        }
        
    }
    if (ans_index != -1) {
        ans.push_back(ans_index);
        if (range[ans_index].second >= l) return ans.size();
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
    int n;
    double l,w;
    int caseNo=0;
    while(scanf("%d%lf%lf",&n,&l,&w)==3){
        cout<<solve(n,l,w)<<"\n";
    }

    return 0;
}