#include<bits/stdc++.h>
using namespace std;
int N, target;
 // but it is OK for competitive programming
 double dist[20][20], memo[1 << 16];

double computeDistance(pair<long long,long long>&a,pair<long long,long long>&b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double GreedySolution(vector<pair<long long,long long>>&v){ //picking pairs whose distance is minimum with respect to other
    vector<pair<long long,long long>>p=v;
    vector<pair<pair<pair<long long,long long>,pair<long long,long long>>,double>>proper;
    long long i=0;
    while(p.size()>0){
        long long j=1;
        double distance=INT_MAX;
        long long max_distance_index=0;
        while(j<p.size()){
            double new_distance=computeDistance(p[i],p[j]);
            if(new_distance<distance){
                
                distance=new_distance;
                max_distance_index=j;
                // cout<<"j:"<<j<<endl;
                // cout<<"max_distance_index:"<<max_distance_index<<endl;
                // cout<<"distance:"<<distance<<endl;
                // cout<<p[i].first<<" "<<p[i].second<<"\n";
                // cout<<p[j].first<<" "<<p[j].second<<"\n";
            }
            j++;
        }
        proper.push_back(make_pair(make_pair(p[i],p[j]),distance));
        p.erase(p.begin()+max_distance_index);
        p.erase(p.begin());
    }
    double ans=0;
    for(auto x: proper){
        ans+=x.second;
    }
    return ans;
}


//BACKTRACKING +DP,MEMOIZATION
double recDistance(vector<pair<long long,long long>>&v,long long index){
    if(index==v.size()-2){
        return computeDistance(v[v.size()-1],v[v.size()-2]);
    }
    double ans=INT_MAX;
    for(int i=index+1;i<v.size();i++){
        swap(v[index],v[i]);
        ans=min(ans,computeDistance(v[index],v[index+1])+recDistance(v,index+2));
        swap(v[index],v[i]);
    }
    return ans;
}
double NaiveBackTrackingSolution(vector<pair<long long,long long>>&v){
    double ans;
    ans=recDistance(v,0);
    return ans;
}

double matching(int bitmask) {
    // DP state = bitmask
    // we initialize ‘memo’ with-1 in the main function
    if (memo[bitmask] >-0.5)
    // this state has been computed before
        return memo[bitmask];
    if (bitmask == target)
        return memo[bitmask] = 0;
    double ans = 2000000000.0;
    int p1, p2;
    for (p1 = 0; p1 < 2 * N; p1++)
        if (!(bitmask & (1 << p1)))
            break;
    for (p2 = p1 + 1; p2 < 2 * N; p2++){
        if (!(bitmask & (1 << p2))){
            cout<<"p1 "<<p1<<" p2 "<<p2<<endl;
            cout<<"bitmask "<<bitmask<<endl;
            ans = min(ans,dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));
            
        }
    }
        
        
        
    // simply lookup the memo table
    // all students are already matched
    // the cost is 0
    // initialize with a large value
    // find the first bit that is off
    // then, try to match p1
    // with another bit p2 that is also off
    // pick the minimum
    
    return memo[bitmask] = ans;
 }
 int main() {
    // store result in a memo table and return
    int i, j, caseNo = 1, x[20], y[20];
    // freopen("10911.txt", "r", stdin);
    while (scanf("%d", &N), N) {
    for (i = 0; i < 2 * N; i++)
    scanf("%*s %d %d", &x[i], &y[i]);
    for (i = 0; i < 2 * N- 1; i++)
    for (j = i + 1; j < 2 * N; j++)
    // redirect input file to stdin
    // yes, we can do this :)
    // ’%*s’ skips names
    // build pairwise distance table
    // have you used ‘hypot’ before?
    dist[i][j] = dist[j][i] = hypot(x[i]- x[j], y[i]- y[j]);
    // use DP to solve min weighted perfect matching on small general graph
    for (i = 0; i < (1 << 16); i++) memo[i] =-1.0; // set-1 to all cells
    target = (1 << (2 * N))- 1;
    printf("Case %d: %.2lf\n", caseNo++, matching(0));
 } }// return 0;
// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int N;
//     int caseNo=1;
//     while(scanf("%d", &N), N){
//         vector<pair<long long,long long>>v;
//         for(int i=0;i<2*N;i++){
//             pair<long long,long long>t;
//             scanf("%*s %d %d",&t.first,&t.second);
//             v.push_back(t);
//         }
//         printf("Case %d: %.2lf\n", caseNo++, NaiveBackTrackingSolution(v));
//     }


//     return 0;
// }