#include<bits/stdc++.h>
using namespace std;

class UnionFind{
    private : vector<int>parent,size,rank;
                int noDisjoint;
    public:
        UnionFind(int n){
            rank.assign(n,0);
            size.assign(n,0);
            parent.assign(n,0);
            noDisjoint=n;
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
            int findset(int a){
                if(a==parent[a]){
                    return a;
                }
                return parent[a]=findset(parent[a]);
            }
            bool isSameSet(int a,int b){
                return findset(a)==findset(b);
            }
            void unionJoin(int a ,int b){
                if(!isSameSet(a,b)){
                    if(rank[a]>rank[b]){
                        parent[b]=a;
                        
                    }
                    else{
                        parent[a]=b;
                        if(rank[a]==rank[b]){
                            rank[b]++;
                        }
                    }
                    
                    size[a]+=size[b];
                    size[b]=size[a];
                    noDisjoint--;//when we are adding joining two sets
                }
            }
            int numDisjointSets(){
                return noDisjoint;
            }
            int sizeOfSet(int i){
                return size[i];
            }
        };

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
    int n;
    cin>>n;
    UnionFind *u=new UnionFind(n);
    u->unionJoin(0,1);
    cout<<u->numDisjointSets()<<endl;
    cout<<u->sizeOfSet(4)<<endl;
    u->unionJoin(2,3);
    cout<<u->numDisjointSets()<<endl;
    cout<<u->sizeOfSet(0)<<endl;
    u->unionJoin(3,4);
    cout<<u->numDisjointSets()<<endl;
    cout<<u->sizeOfSet(0)<<endl;
    u->unionJoin(0,4);
    cout<<u->numDisjointSets()<<endl;
    cout<<u->sizeOfSet(0)<<endl;
    


    return 0;
}