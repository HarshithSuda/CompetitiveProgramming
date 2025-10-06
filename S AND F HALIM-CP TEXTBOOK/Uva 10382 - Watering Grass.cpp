#include<bits/stdc++.h>
using namespace std;

void solve(int n,double l,double w){
    vector<pair<int,int>>p(n);
    vector<pair<double,double>>range;
    // int cn=0;
    for(int i=0;i<n;i++){
        double first,second;
        scanf("%ld %ld",&first,&second);
        p[i].first=first;
        p[i].second=second;
        // cout<<cn++<<endl;
        if(second>w/2.0){
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
   
//    while(right<l){
//         if(left>=range[i].first){
//             if(right<range[i].second){
//                 ans_index=i;
//                 if(range[ans_index].second>=l){
//                     return ans.size()+1;
//                 }
//             }
//             i++;
//         }
//         else{
//             if(ans_index==-1 || range[ans_index].second<range[i].first){
//                 return -1;
//             }
//             if(range[ans_index].second>=l){
//                 return ans.size()+1;
//             }
//             ans.push_back(ans_index);
//             left=right=range[ans_index].second; 
//             continue;
//         }
        
//     }
    double covered = 0;
        int idx = 0, used = 0;
        bool possible = true;
    while (covered < l) {
            double farthest = covered;
            while (idx < range.size() && range[idx].first <= covered) {
                farthest = max(farthest, range[idx].second);
                ++idx;
            }
            if (farthest == covered) {
                possible = false;
                break;
            }
            covered = farthest;
            ++used;
        }

        if (possible){
            cout << used << endl;
            return;
        }
        else{
            cout << -1 << endl;
            return;
        }

        cout << -1 << endl;
            return;
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
        solve(n,l,w);
    }

    return 0;
}