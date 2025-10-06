#include<bits/stdc++.h>
using namespace std;

template <typename Container>
void printContainer(const Container& c) {
    for (const auto& elem : c) {
        cout << elem << " ";
    }
    cout << endl;
}
void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void PrintVectorOfVector(vector<vector<int>>v){
    for(int i=0;i<v.size();i++){
        vector<int>temp=v[0];
        for(int j=0;j<temp.size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}
//https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
//METHOD-1
int findMaximumNote(vector<int>currency,int s){
    int n=currency.size();
    for(int i=n-1;i>=0;i--){
        if(s>=currency[i]){
            return currency[i];
        }
    }
    return -1;
}
vector<int> minPartition(vector<int>currency,int N){
    vector<int>ans;
    int s=0;
    while(s<N){
        int x=findMaximumNote(currency,N-s);
        if(x==-1){
            break;
        }
        int t=(N-s)/x;
        s+=x*t;
        for(int i=0;i<t;i++){
            ans.push_back(x);
        }
    }
    return ans;
}
//METHOD-2
vector<int> M2minCoins(vector<int>currency,int N){
    int amount=N;
    vector<int>ans;
    for(int i=currency.size()-1;i>=0;i--){
        int res=amount/currency[i];
        for(int j=0;j<res;j++){
            ans.push_back(currency[i]);
        }
        amount=amount%currency[i];
    }
    return ans;
}
bool customcomparator(pair<double,double>p1,pair<double,double>p2){
    return p1.first/p1.second<p2.first/p2.second;
}
//items-->(p.first=price and p.second=weight)
double fractionalKnapsack(vector<pair<double,double>>items,double weight){
    double w=weight;
    double profit=0;
    sort(items.begin(),items.end(),customcomparator);
    int i=0;
    while(i<items.size() && w>0){
        if(w>=items[i].second){
            profit+=items[i].first;
            w-=items[i].second;
            i++;
        }
        else{
            profit+=(items[i].first*w)/items[i].second;
            w=0;
            i++;
            break;
        }
    }
    profit=(profit*1e6)/1e6;
    return profit;
}
//https://www.geeksforgeeks.org/fractional-knapsack-queries/
int indexSearch(vector<pair<double,double>>p,int x){
    int low=0,high=p.size()-1;
    while(low<=high){
        int mid=(high-low)/2+low;
        if(p[mid].first==x){
            return mid;
        }
        else if(p[mid].first<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high; //returning weight value in the array just less than the given weight(x)
}
int customComparatorTest(pair<int,int>p1,pair<int,int>p2){
    return p1.first<p2.first;
}
vector<double> knapsackFractionalQueries(vector<pair<double,double>>p,vector<int>q){
    sort(p.begin(),p.end(),customcomparator);
    
    for(int i=1;i<p.size();i++){
        p[i].first+=p[i-1].first;
        p[i].second+=p[i-1].second;
    }
    for(int i=0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<" ";
    }
    cout<<endl;
    vector<double>ans;
    for(auto x:q){
        double wt=x;
        double profit=0;
        pair<double,double>X={wt,INT_MIN};
        int index1=lower_bound(p.begin(),p.end(),X)-p.begin();
        // cout<<p[index1].first<<" "<<p[index1].second<<" ";
        // cout<<endl;
        int index=indexSearch(p,wt);
        if(index1==0){
            ans.push_back((wt*p[index1].second)/p[index1].first);
        }
        else{
            // cout<<p[index1-1].second<<endl;
            profit=p[index1-1].second + ((wt-p[index1-1].first)*(p[index1].second-p[index1-1].second)/(p[index1].first-p[index1-1].first));
            ans.push_back(profit);
        }
    }
    return ans;
}
double UnboundedFractionalKnapsack(vector<pair<double,double>>p,int W){
    pair<double,double>maxValuePerWt=p[0];
    for(int i=1;i<p.size();i++){
        if((maxValuePerWt.second/maxValuePerWt.first)<(p[i].second/p[i].first)){
            maxValuePerWt=p[i];
        }
    }
    return (maxValuePerWt.second/maxValuePerWt.first)*W;

}

int main(){

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    vector<int>currency={1,2,5,10,20,50,100,200,500,52000};
    // vector<int>ans=minPartition(currency,1000);
    // printVector(ans);
    vector<pair<double,double>>v={{1, 2}, {1, 3}, {3, 7}};
    vector<int>q={1, 2, 3, 4, 5};
    vector<double>ans=knapsackFractionalQueries(v,q);
    printContainer(ans);
    // printVector(ans);;
    // pair<double,double>x={1,INT_MIN};
    // pair<double,double>p=*lower_bound(v.begin(),v.end(),x,customComparatorTest);
    // cout<<p.first<<" "<<p.second<<" ";

    return 0;
}