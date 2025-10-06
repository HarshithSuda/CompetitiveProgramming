#include<bits/stdc++.h>
using namespace std;
//Q)print alternates element of array
//M1-Iterative(simple for loop with i=i+2)
vector<int> getAlternatesIterative(vector<int> &arr) {
    int n=arr.size();
    vector<int>v;
    for(int i=0;i<n;i=i+2){
        v.push_back(arr[i]);
    }
    return v;
}
void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void printHeap(priority_queue<int,vector<int>,greater<int>>q){
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return;
}
//M2-Recursive(seperate function- org arr,index+2,output arr)
void Recursive(vector<int> &arr, int s, vector<int> &res){
    //My method
    if(s==arr.size()){
        return;
    }
    if(s==arr.size()-1){
        res.push_back(arr[s]);
        return;
    }
    res.push_back(arr[s]);
    Recursive(arr,s+2,res);
    /*gfg article method
        if(s<arr.size()){
            res.push_back(arr[s];
            Recursive(arr,s+2,res);
        }
    */
    
}
vector<int> getAlternatesRecursive(vector<int> &arr) {
    vector<int>res;
    Recursive(arr,0,res);
    return res;
}
//Simple Array Linear Search
int linearSearch(vector<int> &arr,int x){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
//Largest Element in an Array(Iterative)
int largestElement(vector<int> &arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxi=max(arr[i],maxi);
    }
    return maxi;
}
//Largest Element in an Array(Recursive)
int largestElementRecursive(vector<int> &arr,int index,int maxi){
    if(index==arr.size()){
        return maxi;
    }
    maxi=max(maxi,arr[index]);
    return largestElementRecursive(arr,index+1,maxi);
}
//Largest Element in an Array(Recursive-part2)
int M2largestElementRecursive(vector<int>&arr,int i){
    if(i==arr.size()-1){
        return arr[i];
    }
    int recMax=M2largestElementRecursive(arr,i+1);
    return max(recMax,arr[i]);
}
int M3largestELementInArray(vector<int> &arr){
    return *max_element(arr.begin(),arr.end());
}
//print second largest element
int secondLargestElement(vector<int> &arr){
    int largest=max(arr[0],arr[1]);
    int res=min(arr[0],arr[1]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]>largest){
            res=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>res){
            res=arr[i];
        }
    }
    return (largest==res)?-1:res;
}
//print third largest element
vector<int> getThreeLargest(vector<int>& arr) {
    int fst=INT_MIN,sec=INT_MIN,res=INT_MIN; //we start with INT_MIN because we need to compare every element(copies also are not allowed)
    for(auto x :arr){
        if(x>fst){
            res=sec;
            sec=fst;
            fst=x;
        }
        else if(x!=fst && x>sec){ //x!=fst and X!=sec -prevent copies 
            res=sec;
            sec=x;
        }
        else if(x!=fst && x!=sec && x>res){
            res=x;
        }
    }
    vector<int>ans;
    if(fst==INT_MIN){ //n=0
        return ans;
    }
    ans.push_back(fst);
    if(sec==INT_MIN){ //n=1
        return ans;
    }
    ans.push_back(sec);
    if(res==INT_MIN){//n=2
        return ans;
    }
    ans.push_back(res);//n>=3
    return ans;
}
vector<int> leaderInArray(vector<int> &arr){
    int n=arr.size();
    vector<int>ans;
    int a=arr[n-1]; // element to compare elements from right to left
    ans.push_back(arr[n-1]); //reverse the array at end
    if(n==1){
        return ans;
    }
    for(int i=n-2;i>=0;i--){
        if(a>arr[i]){
            continue;
        }
        else{
            ans.push_back(arr[i]);
            a=arr[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
bool checkSorted(vector<int> &arr){
    int n=arr.size();
    if(n==1){
        return true;
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
bool checksorted(vector<int> &arr,int index){
    if(index==1 ||index ==0){
        return true;
    }
    return arr[index-1]>=arr[index-2] && checksorted(arr,index-1);
}
int removeDuplicatesWithHashSet(vector<int> &arr){ //using hash set
    unordered_set<int>s;
    int index=0;
    for(int i=0;i<arr.size();i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            arr[index++]=arr[i];
        }
    }
    return s.size();
}
int removeDuplicates(vector<int> &arr){
    int index=1;
    if(arr.size()<=1){
        return arr.size();
    }
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){
            arr[index++]=arr[i];
        }
    }
    return index;
}
void reverseIterative(vector<int> &arr,int low,int high){
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
void reverseRecursive(vector<int> &arr,int low,int high){
    if(low>=high){
        return;
    }
    swap(arr[low],arr[high]);
    reverseRecursive(arr,low+1,high-1);
}
void reverseArray(vector<int> &arr){
    int low=0,high=arr.size()-1;
    reverseIterative(arr,low,high);
}
void rotateAnArray(vector<int> &arr,int d){
    int n=arr.size();
    d=d%(arr.size());
    reverseIterative(arr,0,n-1);
    reverseIterative(arr,0,d-1);
    reverseIterative(arr,d,n-1);
    return;
}
void printSubArrays(vector<int> &arr,int start,int end){
    if(end==arr.size()){
        return;
    }
    else if(start>end){
        printSubArrays(arr,0,end+1); //extending the array length and starting from beginning
    }
    else{
        for(int i=start;i<=end;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        printSubArrays(arr,start+1,end);
    }
}
int minimumIncrementByK(vector<int> &arr,int k){
    int ele=*max_element(arr.begin(),arr.end());
    int count=0;
    for(int i=0;i<arr.size();i++){
        if((ele-arr[i])%k!=0){
            return -1;
        }
        else{
            count+=((ele-arr[i])/k);
        }
    }
    return count;
}
int minimumCostToMakeSize1(vector<int> &arr){
    int ele=*min_element(arr.begin(),arr.end());
    return (arr.size()-1)*ele;
}
bool twoSumInSortedArray(vector<int> &arr,int target){
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==target){
            return true;
        }
        else if(arr[i]+arr[j]>target){
            j--;
        }
        else{
            i++;
        
    }
    return false;
}
int countSum(vector<int>& arr, int target) {
        int count=0;//count of quadruplets
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int sum_first=target-arr[i];
            for(int j=i+1;j<n-1;j++){
                int sum_second=sum_first-arr[j];
                int z=j+1,m=n-1;
                while(z<m){
                    if(arr[z]+arr[m]==sum_second){
                        count++;
                        z++;
                    }
                    else if(arr[z]+arr[m]>sum_second){
                        m--;
                    }
                    else{
                        z++;
                    }
                }
            }
        }
        return count;
    }

    int M1trapping_rain_water(vector<int> &arr){ // Naive -O(n^2)
    int count=0,n=arr.size();
    for(int i=1;i<n-1;i++){
        int right=arr[i],left=arr[i];
        for(int j=i-1;j>=0;j--){
            left=max(left,arr[j]);
        }
        for(int j=i+1;j<n;j++){
            right=max(right,arr[j]);
        }
        if(min(right,left)>arr[i]){
            count+=(min(right,left)-arr[i]);
        }
    }
    return count;
}
int M2trapping_rain_water(vector<int> &arr){
    int n=arr.size(),count=0;
    vector<int>left(n);
    vector<int>right(n);
    left[0]=arr[0]; //pre computing maximum on left and right side for every index(no need to do for every ith iteration)
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(int j=n-2;j>=0;j--){
        right[j]=max(right[j+1],arr[j]);
    }
    for(int i=1;i<n-1;i++){
        int value=min(left[i-1],right[i+1]);
        if(value>arr[i]){
            count+=(value-arr[i]);
        }
    }
    return count;
}
int M3trappingRainWater(vector<int> &arr){
    int n=arr.size();
    int count=0;
    int lmax=arr[0],rmax=arr[n-1];
    int left=1,right =n-2;
    while(left<=right){
        if(lmax<rmax){ //WKT right side of arr[left], we have greater values than lmax(so we wont use them as min(lmax,rmax) is used)
            if(lmax>arr[left]){
                count+=(lmax-arr[left]);
            }
            lmax=max(arr[left],lmax);
            left++;
        }
        else{
            if(rmax>arr[right]){
                count+=(rmax-arr[right]);
            }
            rmax=max(arr[right],rmax);
            right--;
        }
    }
    return count;
}
void mergeForPrintClosest(int a[],int b[],int n,int m,int merged[],bool check[]){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]>=b[j]){
            merged[k]=b[j];
            check[k]=false;
            k++;
            j++;
        }
        else if(a[i]<b[j]){
            merged[k]=a[i];
            check[k]=true;
            i++;
            k++;
        }
    }
    if(i<n){
        while(i<n){
            merged[k]=a[i];
            check[k]=true;
            i++;
            k++;
        }
    }
    if(j<m){
        while(j<m){
            merged[k]=b[j];
            check[k]=false;
            k++;
            j++;
        }
    }
    return;
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void printBoolArray(bool a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
vector<int> M1printClosest(int arr[], int brr[], int n, int m, int x){
    vector<int>v(2,-1);
    bool check[n+m];
    int merged[n+m];
    mergeForPrintClosest(arr,brr,n,m,merged,check);
    // printArray(merged,n+m);
    // printBoolArray(check,n+m);
    int i=0,j=m+n-1,min_val=INT_MAX;
    while(i<j){
        if(abs(merged[i]+merged[j]-x)<min_val && check[i]^check[j]){
            min_val=abs(merged[i]+merged[j]-x);
                v[0]=merged[i];
                v[1]=merged[j];
        }
        if(merged[i]+merged[j]>x){
            j--;
        }
        else{
            i++;
        }
    }
    return v;
}
vector<int> M2printClosest(int arr[], int brr[], int n, int m, int x){
    vector<int>v(2,-1);
    int i=0,j=m-1,min_val=INT_MAX;
    while(i<n && j>=0){
        if(abs(arr[i]+brr[j]-x)<abs(min_val)){
            min_val=arr[i]+brr[j]-x;
            v[0]=i;
            v[1]=j;
        }
        if(arr[i]+brr[j]>x){
            j--;
        }
        else if(arr[i]+brr[j]<x){
            i++;
        }
        else{ 
            v[0]=i;
            v[1]=j;
            return v;
        }
    }
    if(i<n){
        while(i<n){
            if(abs(arr[i]+brr[j]-x)<abs(min_val)){
            min_val=arr[i]+arr[j]-x;
            v[0]=i;
            v[1]=j;
            }
            i++;
        }
    }
    if(j>0){
        while(j>0){
            if(abs(arr[i]+brr[j]-x)<abs(min_val)){
            min_val=arr[i]+arr[j]-x;
            v[0]=i;
            v[1]=j;
        }
        j--;
    } 
}
return v;
}
vector<vector<int>> M1findTriplets(vector<int> &arr,int target) {
    int n=arr.size();
    set<vector<int>>s; //unordered_set wont work - they use hash tables for searching- no hash function for vector<int>
    unordered_map<int,vector<pair<int,int>>>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m[arr[i]+arr[j]].push_back({i,j}); //generally m<int,int> - m[a]++; but here m<int,vector<int>> so m[a].push_back(i);
            int diff_sum=target-arr[i];
            if(m.find(diff_sum)!=m.end()){
                vector<pair<int,int>>p=m[diff_sum];
                for(auto x : p){
                    if(x.first!=i && x.second!=i){
                        vector<int>c={i,x.first,x.second};
                        sort(c.begin(),c.end()); //if not sorted - {1,2,3},{2,1,3}, {3,2,1} etc -will be treated diff even when same
                        s.insert(c);
                    }
                }
            }
        }
    }
    vector<vector<int>>v(s.begin(),s.end());
    return v;
}
//https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/
vector<vector<int>> M2findTriplet(vector<int> &arr){
    unordered_map<int,vector<int>>m;
    vector<vector<int>>res;
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            if(m.find(-sum)!=m.end()){
                vector<int>temp=m[-sum];
                for(auto x:temp){
                    res.push_back({x,i,j});
                }
            }
        }
        m[arr[i]].push_back(i);
    }
    return res;
}
bool M1tripletFamily(vector<int> &arr){ //with preprocessing(bit unnecessary)-cases passed(time limit exceeded)
//preprocessing
    int n=arr.size();
    unordered_map<int,vector<pair<int,int>>>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m[arr[i]+arr[j]].push_back({i,j});
        }
    }
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end()){
            vector<pair<int,int>>p=m[arr[i]];
            for(auto x:p){
                if(x.first!=i && x.second!=i){
                    return true;
                }
            }
        }
    }
    return false;
}
bool M2tripletFamily(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int z=n-1;z>=0;z--){
        int i=0,j=z-1;
        while(i<j){
            if(arr[i]+arr[j]==arr[z] || arr[j]+arr[z]==arr[i]|| arr[z]+arr[i]==arr[j]){
                return true;
            }
            else if(arr[i]+arr[j]<arr[z]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    return false;
}
bool binarySearch(vector<int> &arr,int low,int high,int target){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}
bool M3tripleFamily(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(binarySearch(arr,j,n-1,arr[i]+arr[j])){
                return true;
            }
        }
    }
    return false;
}
vector<vector<int>> M1foursum(vector<int> &arr,int target){ //approach-1(memory limit exceeded)-modified it for leetcode
    int n=arr.size();
    set<vector<int>>s; //to store the indexes vector
    unordered_map<long,vector<vector<int>>>m;  //to map sums at final for loop
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                m[arr[i]+arr[j]+arr[k]].push_back({i,j,k});
            }
        }
    } 
    //cout<<"size of m"<<m.size()<<endl;//count of all quadruples
    //pre-processed the map with sums of every 3 elements
    for(int i=0;i<n;i++){
        if(m.find(target-arr[i])!=m.end()){
            for(auto x: m[target-arr[i]]){
                if(x[0]!=i && x[1]!=i && x[2]!=i){
                    vector<int>v={arr[x[0]],arr[x[1]],arr[x[2]],arr[i]};
                    sort(v.begin(),v.end());
                    s.insert(v);
                }
            }
        }
    }
    vector<vector<int>>v(s.begin(),s.end());
    return v;
}
//reversal law in  mathematics
vector<vector<int>> LeetcodefourSum(vector<int>& arr, int target) { //it works with static long long modification 
    int n=arr.size();
    set<vector<int>>s; //to store the indexes vector
    unordered_map<int,vector<pair<int,int>>>m;  //to map sums at final for loop
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(m.find(target-(arr[i]+arr[j]))!=m.end()){
                //cout<<m[4].size()<<endl;
                for(auto x : m[target-(arr[i]+arr[j])]){
                    vector<int>v={arr[i],arr[j],x.first,x.second};
                    sort(v.begin(),v.end());
                    s.insert(v);
                }
            }
        }
        for(int j=0;j<i;j++){
            m[arr[i]+arr[j]].push_back(make_pair(arr[i],arr[j]));
            set<pair<int,int>>inner_set(m[arr[i]+arr[j]].begin(),m[arr[i]+arr[j]].end());
            vector<pair<int,int>>temp(inner_set.begin(),inner_set.end());
            m[arr[i]+arr[j]]=temp;
            
        }
    }
    
    vector<vector<int>>v(s.begin(),s.end());
    return v;
}
int twosumForFourSum(vector<int>&arr,int index,int target){ //specifically designed for four sum problem
    int n=arr.size();
    int count=0;
    unordered_map<int,int>m;
    for(int i=index;i<n;i++){
        if(m.find(target-arr[i])!=m.end()){
            count+=m[target-arr[i]]; //all values in m are with indexes less than i
        }
        m[arr[i]]++;
    }
    return count;
}
int M2foursum(vector<int> &arr,int target){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n-3;i++){ //1st element
        for(int j=i+1;j<n-2;j++){ //2nd element
            int sum=arr[i]+arr[j];
            count+=twosumForFourSum(arr,j+1,target-sum); //3rd and 4th element
        }
    }
    return count;

}
int M3foursum(vector<int> &arr,int target){ //-O(n^2) -beautiful solution
    int n=arr.size();
    int count=0;
    unordered_map<int,int>m;
    for(int i=0;i<n-1;i++){// 3rd element
        for(int j=i+1;j<n;j++){ //4th element
            int sum=arr[i]+arr[j];
            if(m.find(target-sum)!=m.end()){ //finding sums 
                count+=m[target-sum]; //(we wont get copies as we calculate members of maps are all before with indexes less than i(j is always less than i))
            }
        }
        for(int j=0;j<i;j++){ //storing sums of 1st and 2nd elements(here we wont get)
            m[arr[i]+arr[j]]++;
        }
    }
    return count; 
}
bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    unordered_map<int,vector<int>>m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]].push_back(i);
    }
    for(int i=0;i<arr.size();i++){
        vector<int>v=m[arr[i]];
        if(v.size()>1){
            if((v[1]-v[0])<=k){
                return true;
            }
        }
    }
    return false;
}
vector<int> M1rearrangeArray(vector<int>& arr) {
    int n=arr.size();
    vector<int>v=arr;
    sort(v.begin(),v.end());
    if(v.size()>=2){
        for(int i=2;i<n;i=i+2){
            swap(v[i-1],v[i]);
        }
    }
    return v;
}
vector<int> M2rearrangeArray(vector<int>& arr){
    int n=arr.size();
    vector<int>v=arr;
    for(int i=1;i<n;i++){ //i=1(we do arr[i-1] in loop)
        if((i+1)%2==0){ //even based indexing
            if(v[i]<v[i-1]){
                swap(v[i],v[i-1]);
            }
        }
        else{
            if(v[i]>v[i-1]){
                swap(v[i],v[i-1]);
            }
        }
    }
    return v;
}
void printQueriesPrefixSum(vector<int> &arr,vector<vector<int>>queries){
    int n=arr.size();
    int pre[n];
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    for(int i=0;i<queries.size();i++){
        int l=queries[i][0],r=queries[i][1];
        if(l<1 || r>n){
            cout<<i<<"th query is out of range"<<endl;
            continue;
        }
        if(l==1){
            cout<<pre[r-1]<<endl;
        }
        else{
            cout<<pre[r-1]-pre[l-2]<<endl;
        }
    }
    return;
}
int MoperationsAndMaxSum(int n,int m,vector<pair<int,int>>pairs){
    vector<int>arr(n,0);
    for(int i=0;i<pairs.size();i++){
        arr[pairs[i].first-1]+=100; //1-indexing(while doing prefix sum 100 gets added to all the elements from a to b)
        arr[pairs[i].second]-=100;// -100 neturalises the prefix sum from b+1 onwards
    }
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    return *max_element(arr.begin(),arr.end());
}
int M1equilibriumPoint(vector<int> &arr){
    int n=arr.size();
    vector<int>pre(n,0),suffix(n,0);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+arr[i];
    }
    for(int i=0;i<n;i++){
        if(pre[i]==suffix[i]){
            return i+1;
        }
    }
    return -1;
}
int M2equilibriumPoint(vector<int> &arr) {
    int n=arr.size();
    vector<int>pre(n,0);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    int index=-1;
    for(int i=0;i<n-1;i++){
        if(pre[n-1]-pre[i+1]==pre[i]){
            index=i+2; //1 indexing
        }
    }
    return index;
}
int M3equilibriumPoint(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n-1;i++){
        int left=0,right=0;
        for(int j=0;j<i;j++){
            left+=arr[j];
        }
        for(int j=i+1;j<n;j++){
            right+=arr[j];
        }
        if(left==right){
            return i+1;
        }
    }
    return -1;
}
int M4equilibriumPoint(vector<int> &arr){
    int n=arr.size();
    int left_sum=0,pivot=0,right_sum=0;
    for(int i=1;i<n;i++){
        right_sum+=arr[i];
    }
    while(pivot<n-1 && left_sum!=right_sum){
        pivot++;
        left_sum+=arr[pivot-1];
        right_sum-=arr[pivot];
    }
    return (left_sum==right_sum)?pivot+1:-1; //1-indexing
}
bool M1subArrayExists(vector<int>& arr) {
    int n=arr.size();
    unordered_set<int>s;
    vector<int>pre(n,0);
    
    pre[0]=arr[0];
    if(pre[0]==0){
        return true;
    }
    s.insert(pre[0]);
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
        if(s.find(pre[i])!=s.end() || pre[i]==0){
            return true;
        }
        s.insert(pre[i]);
    }
    return false;
}
bool M2subArrayExists(vector<int>& arr) {
    int n=arr.size();
    int sum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(s.find(sum)!=s.end() || sum==0){
            return true;
        }
        s.insert(sum);
    }
    return false;
}
//Maximum subarray size, such that all subarrays of that size have sum less than k
int M1maxSubArraySumLessThanK (vector<int> &arr,int k){
    int n=arr.size();
    vector<int>prefix=arr;
    for(int i=1;i<n;i++){
        prefix[i]+=prefix[i-1];
    }
    //i=0,1 cases
    for(int i=0;i<n;i++){
        if(arr[i]>k){
            return -1;
        }
    }
    int size=1;
    for(int i=2;i<n;i++){
        int low=-1,high=i-1;
        while(high<n){
            if(low==-1){
                if(prefix[high]>k){
                    return size; //size obtained upto now
                }
            }
            else{
                if((prefix[high]-prefix[low])>k){
                    return size;
                }
            }
            low++;
            high++;
        }
        size++;
    }
    return size;
}
int M2maxSubArraySumLessThanK (vector<int> &arr,int k){
    int n=arr.size();
    vector<int>prefix(n+1,0); //easier to handle the i=0 case
    for(int i=1;i<=n;i++){
        prefix[i]=arr[i-1]+prefix[i-1];
    }
    int ans=-1,left=1,right=n;//using 1 indexing
    while(left<=right){
        int mid=left+(right-left)/2;
        int i;
        for(i=mid;i<=n;i++){
            if(prefix[i]-prefix[i-mid]>k){
                break;
            }
        }
        if(i==n+1){
            left=mid+1;
            ans=mid; // mid is index so generally size will be mid+1(but this is 1 indexing)
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}
int M3maxSubArraySumLessThanK (vector<int> &arr,int k){
    int n=arr.size();
    bool not_possible=false;
    int sum=0,start=0,ans=n;
    for(int end=0;end<n;end++){
        sum+=arr[end];
        while(sum>k){
            sum-=arr[start];
            start++;
            ans=min(ans,end-start+1);
        }
        if(sum==0){ //sum=0 when 1 element >k
            not_possible=true; 
            break;
        }
    }
    if(not_possible){
        return -1;
    }
    return ans;
}
//2461. Maximum Sum of Distinct Subarrays With Length K
long long M1maximumSubarraySum(vector<int>& arr, int k){ //TLE
    int n=arr.size();
    long long sum=0;// to keep track of sum
    long long ans=0;//to keep track of ans
    if(k==1){
        return *max_element(arr.begin(),arr.end());
    }
    vector<int>v; //temp array of size k
    for(int i=0;i<k;i++){
        sum+=arr[i];
        v.push_back(arr[i]);
    }
    unordered_set<int>s(v.begin(),v.end());
    bool flag;
    ans=(s.size()==k)?sum:0;
    for(int i=k;i<n;i++){
        sum-=arr[i-k];
        sum+=arr[i];
        v.erase(v.begin());
        v.push_back(arr[i]);
        unordered_set<int>s(v.begin(),v.end());
        flag=(s.size()==k);
        if(flag){
            printVector(v);
            ans=max(ans,sum);
        }
    }
    return ans;
}
void printMap(unordered_map<int,int>m){
    for(auto x:m){
        cout<<x.first<<" "<<x.second<< "   ";
    }
    cout<<endl;
}
long long M2maximumSubarraySum(vector<int>& arr, int k){
    int n=arr.size();
    long long sum=0;// to keep track of sum
    long long ans=0;//to keep track of ans
    if(k==1){
        return *max_element(arr.begin(),arr.end());
    }
    unordered_map<int,int>m_org;
    unordered_map<int,int>m_copy;
    for(int i=0;i<k;i++){
        sum+=arr[i];
        if(m_org.find(arr[i])!=m_org.end()){
            m_copy[arr[i]]++;
        }
        m_org[arr[i]]++;
    }
    printMap(m_org);
    printMap(m_copy);
    ans=(m_copy.empty()?max(sum,ans):ans);
    for(int i=k;i<n;i++){
        if(m_copy.find(arr[i-k])!=m_copy.end()){
            m_copy[arr[i-k]]--;
            if(m_copy[arr[i-k]]==0){
                m_copy.erase(arr[i-k]);
            }
        }
        m_org[arr[i-k]]--;
        if(m_org[arr[i-k]]==0){
                m_org.erase(arr[i-k]);
            }
        if(m_org.find(arr[i])!=m_org.end()){
            m_copy[arr[i]]++;
        }
        m_org[arr[i]]++;
        printMap(m_org);
        printMap(m_copy);
        sum-=arr[i-k];
        sum+=arr[i];
        ans=(m_copy.empty()?max(sum,ans):ans);
    }
    return ans;
}
long long M3maximumSubarraySum(vector<int>& arr, int k){
    int n=arr.size();
    long long sum=0,ans=0;
    bitset<100001>bit=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(!bit[arr[i]]){
            sum+=arr[i];
            bit[arr[i]]=1;
            k--;
            if(k==-1){
                sum-=arr[j];
                bit[arr[j]]=0;
                j++;
                k++;
            }
        }
        else{
            while(j<n && arr[i]!=arr[j]){
                sum-=arr[j];
                bit[arr[j]]=0;
                j++;
                k++;
            }
            j++;
        }
        if(k==0){
            ans=max(ans,sum);
        }
    }
    return ans;
}
//Longest Span with same Sum in two Binary arrays
int M1longestCommonSum(vector<int> &arr1, vector<int> &arr2) { //TLE 
    int n=arr1.size();
    vector<int>presum1(n+1,0),presum2(n+1,0);
    presum1[0]=arr1[0];
    presum2[0]=arr2[0];
    for(int i=1;i<=n;i++){
        presum1[i]=presum1[i-1]+arr1[i-1];
        presum2[i]=presum2[i-1]+arr2[i-1];
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((presum1[j]-presum1[i])==presum2[j]-presum2[i]){
                res=max(res,j-i);
            }
        }
    }
    return res;
}
int M2longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
    int n=arr1.size();
    vector<int>diff(2*n+1,-1); //stores index
    int sum1=0,sum2=0,curr_diff=0,res=0,sum_for_diff_array;
    for(int i=0;i<n;i++){
        sum1+=arr1[i];
        sum2+=arr2[i];
        curr_diff=sum2-sum1;// sum1-sum2 also accepted (relative) 
        //curr_diff range from -n to n 
        sum_for_diff_array=n+curr_diff; // +n to place in the appropriate index
        if(!curr_diff){
            res=i+1;
        }
        if(diff[sum_for_diff_array]!=-1){
            res=max(res,i-diff[sum_for_diff_array]); // not doing +1?it is prefix sum
        }
        else{
            diff[sum_for_diff_array]=i;
        }
    }
    return res;
}
int M3longestCommonSum(vector<int> &arr1, vector<int> &arr2){
    int n=arr1.size();
    unordered_map<int,int>m;
    int sum=0,res=0;
    for(int i=0;i<n;i++){
        sum+=arr1[i]-arr2[i];
        if(sum==0){
            res=i+1;
        }
        if(m.find(sum)!=m.end()){
            res=max(res,i-m[sum]);
        }
        else{
            m[sum]=i;
        }
    }
    return res;
}
//Largest subarray with equal number of 0s and 1s
int M1maxLenBinary(vector<int> &arr) {
    int n=arr.size();
    int prefix=0,res=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        prefix+=(arr[i])?1:-1;
        if(prefix==0){
            res=i+1;
        }
        if(m.find(prefix)!=m.end()){
            res=max(res,i-m[prefix]);
        }
        else{
            m[prefix]=i;
        }
    }
    return res;
}
//Longest Subarray with 0 Sum
int M1maxLen(vector<int> &arr) {
    int n=arr.size();
    int prefix=0,res=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        prefix+=(arr[i]);
        if(prefix==0){
            res=i+1;
        }
        if(m.find(prefix)!=m.end()){
            res=max(res,i-m[prefix]);
        }
        else{
            m[prefix]=i;
        }
    }
    return res;
}
// Maximum subarray sum modulo m
long maximumSum(vector<long> a, long m) {
    int n=a.size();
    long sum=0;
    vector<long>prefix(n,0),suffix(n,0);
    prefix[0]=a[0]%m;
    suffix[n-1]=a[n-1]%m;
    for(int i=1;i<n;i++){
        prefix[i]=(prefix[i-1]+a[i])%m;
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=(suffix[i+1]+a[i])%m;
    }
    for(int i=0;i<n;i++){
        sum=max(sum,abs(prefix[i]-suffix[i]));
    }
    return sum;
}
//Single Among Doubles
int searchNumber(int n, int arr[]){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid!=0 && arr[mid-1]==arr[mid]){
            if(mid%2==0){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else if(mid!=n-1 && arr[mid]==arr[mid+1]){
            if(mid%2==0){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        else{
            return arr[mid];
        }
    }
    return arr[low];
}
//Missing and Repeating in an Array
vector<int> findTwoElement(vector<int>& arr){
    int n=arr.size();
    vector<int>v(2);
    int sum=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end()){
            v[0]=arr[i];
        }
        m[arr[i]]++;
        sum+=arr[i];
    }
    sum-=v[0];
    v[1]=(n*(n+1))/2-sum;
    return v;
}
//Only Repeating From 1 To n-1
int M1findDuplicate(vector<int>& arr){ //might cause overflow
    int n=arr.size();
    int sum=(n-1)*n/2;
    for(int i=0;i<n;i++){
        sum-=arr[i];
    }
    return abs(sum);
}
int M2findDuplicate(vector<int>& arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){ //works: only one number is extra and all numbers are from 1 to n-1
            return arr[i];
        }
    }
    return -1; //to avoid return type error
}
int M3findDuplicate(vector<int>& arr){ //genius method of solving(accesing the elements as indexes and setting negative after accesing)
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]<0){
            return abs(arr[i]);
        }
        arr[abs(arr[i])]=-arr[abs(arr[i])];
    }
    return -1; //to avoid return type error
}
int M4findDuplicate(vector<int>& arr){
    int n=arr.size(),res=0;
    for(int i=0;i<n-1;i++){ //here values start from 1 to n-1 (when i=n-1 in for res=res^arr[n-1]^n)                    
        res=res^arr[i]^(i+1);////but n not in array
    }
    res=res^arr[n-1];
    return res;
}
int M5findDuplicate(vector<int>& arr){
    int n=arr.size();
    int slow=arr[0],fast=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);
    fast=arr[0];
    while(slow!=fast){
        fast=arr[fast];
        slow=arr[slow];
    }
    return slow;
}
//Segregate 0s and 1s in an array
void M1segregate0and1(vector<int> &arr) {
    int n=arr.size();
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=1){
            swap(arr[i],arr[res]);
            res++;
        }
    }
    return;
}
void M2segregate0and1(vector<int> &arr) {
    int n=arr.size();
    int i=-1,j=n;
    while(i<j){
        do{
            i++;
        }while(arr[i]==0 && i<j);
        do{
            j--;
        }while(arr[j]==1 && i<j);
        if(i>=j){
            return;
        }
        swap(arr[i],arr[j]);
    }
    return;
}
void M3segregate0and1(vector<int> &arr) {
    int n=arr.size();
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]==1){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        else{
            i++;
        }
    }
    return;
}
vector<int> sortEvenOdd(vector<int>& arr) {
    int n=arr.size();
    vector<int>arr1,arr2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr1.push_back(arr[i]);
        }
        else{
            arr2.push_back(arr[i]);
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<int>ans(n,0);
    printVector(arr1);
    printVector(arr2);
    int inx=0,i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        ans[inx++]=arr1[i++];
        ans[inx++]=arr2[j++];
    }
    return ans;
}
//922. Sort Array By Parity II
vector<int> M1sortArrayByParityII(vector<int>& arr) { //given that n is even
    int n=arr.size();
    int i=-1,j=n;
    while(i<j){
        do{
            i++;
        }while(i<j && arr[i]%2==0);

        do{
            j--;
        }while(i<j && arr[j]%2==1);

        if(i>=j){
            break;
        }
        swap(arr[i],arr[j]);
    }
    i=1,j=n-2;
    while(i<j){
        swap(arr[i],arr[j]);
        i=i+2;
        j=j-2;
    }
    return arr;
}
vector<int> M2sortArrayByParityII(vector<int>& arr) {
    vector<int>ans(arr.size());
    int e=0,o=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]%2==0){
            ans[e]=arr[i];
            e=e+2;
        }
        else{
            ans[o]=arr[i];
            o=o+2;
        }
    }
    return ans;
}
vector<int> M3sortArrayByParityII(vector<int>& arr) {
    int j=1;
    for(int i=0;i<arr.size();i=i+2){
        if(arr[i]%2==1){
            while(arr[j]%2==1){
                j=j+2;
            }
            swap(arr[j],arr[i]);
        }
    }
    return arr;
}
//Move negatives to the end with relative order preserved using extra space
void M1segregateElements(vector<int>& arr){
    int n=arr.size();
    vector<int>pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    for(int i=0;i<neg.size();i++){
        pos.push_back(neg[i]);
    }
    arr=pos;
}
void M2segregateElements(vector<int>& arr){
    int n=arr.size();
    stack<int>pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push(arr[i]);
        }
        else{
            pos.push(arr[i]);
        }
    }
    int res=n-1;
    int a;
    while(!neg.empty()){
        a=neg.top();
        neg.pop();
        arr[res--]=a;

    }
    while(!pos.empty()){
        a=pos.top();
        pos.pop();
        arr[res--]=a;
    }
    return;
}
//Alternate Rearrangement of Positives and Negatives
void alternateRearrangementOfPositiveAndNegative(vector<int> &arr){
    int n=arr.size();
    if(n<=2){
        return;
    }
    int i=-1,j=n;
    int mid=0;
    while(i<j){
        do{
            i++;
        }while(i<j && arr[i]>0);

        do{
            j--;
        }while(i<j && arr[j]<0);

        if(i>=j){
            mid=i; // i gives first negative index
            break;
        }
        swap(arr[i],arr[j]);
    }
    //cout<<"value of Mid :"<<mid<<endl;
    
    if(mid>n/2){ //more positives 
        reverse(arr.begin(),arr.end());
        mid=n-mid;
        // reversing as extra positives must be at the end
    }
    //printVector(arr);
    //else - leave it as it is(negatives are more and extras will end up at the end)
    if(n%2!=0){
        mid++;
    }
    i=1,j=mid;
    while(i<mid){
        swap(arr[i],arr[j]);
        i=i+2;
        j=j+2;
    }
    return;
}
//Maximum Subarray Sum – Kadane’s Algorithm (printing the array elements)
vector<int> maxSubarraySum(vector<int> &arr) {
    int n=arr.size();
    int res=arr[0],maxSum=arr[0];
    int start=0,end=0;
    int inx1=0,inx2=0; //indexes
    int temp=arr[0];
    vector<int>ans;
    for(int i=1;i<n;i++){
        temp=maxSum;
        maxSum=max(maxSum+arr[i],arr[i]);
        if(maxSum==temp+arr[i]){
            end++;
        }
        else{
            start=i;
            end=i;
        }
        res=max(res,maxSum);
        if(res==maxSum){
            inx1=start;
            inx2=end;
        }
    }
    for(int i=inx1;i<=inx2;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}
//Maximum Product Subarray
int maxProduct(vector<int> &arr) {
    int prod=arr[0],res=arr[0];
    int count=0;//for all 0's corner case
    for(int i=1;i<arr.size();i++){
        if(arr[i]==0){
            res=max(prod,res);
            prod=0;
            continue;
        }
        if(prod==0){
            prod=arr[i];
            res=max(res,prod);
        }
        else{
            prod*=arr[i];
        }
        res=max(res,prod);
    }
    return res;
}

//Two Sum – Pair with given Sum
bool twoSum(vector<int>& arr, int target) {
    int n=arr.size();
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])!=s.end()){
            return true;
        }
        s.insert(target-arr[i]);
    }
    return false;
}
//Find all pairs with a given sum in two unsorted arrays
vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
    int n1=arr1.size(),n2=arr2.size();
    // if(n2>n1){
    //     vector<int>temp=arr1;
    //     arr1=arr2;
    //     arr2=temp;
    // }
    vector<pair<int,int>>ans;
    unordered_map<int,int>m;
    for(int i=0;i<n2;i++){
        m[arr2[i]]++;
    }
    for(int i=0;i<n1;i++){
        if(m.find(target-arr1[i])!=m.end()){
            int count=m[target-arr1[i]];
            while(count--){
                ans.push_back({arr1[i],target-arr1[i]});
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans; 
}
void printPair(vector<pair<int,int>>p){
    for(auto x: p){
        cout<<x.first<<" "<<x.second<<" ";
    }
    cout<<endl;
}

int countPairs(vector<int> &arr, int target) { //hashing
    int n=arr.size();
    int count=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        if(m.find(target-arr[i])!=m.end()){
            count+=m[target-arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}
//Check pair with given product
bool isProduct(vector<int> arr, long long x) {
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        if((arr[i]!=0 &&  !(x%arr[i]) && s.find(x/arr[i])!=s.end())||(x==0 && arr[i]==0)){
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}
//Smallest Difference pair of values between two unsorted Arrays
int findSmallestDifference(vector<int>arr1,vector<int>arr2){
    int n=arr1.size(),m=arr2.size();
    int i=0,j=0;
    int res=INT_MAX;
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    while(i<n && j<m){
        res=min(res,abs(arr1[i]-arr2[j]));
        if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return res;
}
//2 Sum – Pair Sum Closest to Target in Sorted Array
vector<int> M1pairSumClosestToTargetSortedArray(vector<int> arr,int target){
    int n=arr.size();
    vector<int>v={0,n-1};
    int low=0,high=n-1;
    int close=abs(target-(arr[low]+arr[high]));
    while(low<high){
        if(close>abs(target-(arr[low]+arr[high]))){
            // no need to check maximum difference as we the first pair we find will have maximum difference(two pointer approach)
            v[0]=arr[low];
            v[1]=arr[high]; 
            //cout<<"value of abs_diff :"<<abs_diff<<" value of close :"<<close<<endl;
            close=abs(target-(arr[low]+arr[high]));
        }
        if(arr[low]+arr[high]==target){
            v[0]=arr[low];
            v[1]=high;
            return v;
        }
        else if(arr[low]+arr[high]>target){
            high--;
        }
        else{
            low++;
        }
        //cout<<"Low : "<<low<<"high: "<<high<<endl;
        //cout<<"values of low and high are "<<arr[low]<<" "<<arr[high]<<endl;
        
    }
    return v;
}
int binarySearchForClosestPair(vector<int> arr,int low,int compliment){
    int n=arr.size();
    int res=arr[low],high=n-1;
    int curr_diff=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(abs(arr[mid]-compliment)<abs(res-compliment)){
            res=arr[mid];
        }
        else if(abs(arr[mid]-compliment)==abs(res-compliment)){
            res=max(arr[mid],res);
        }
        if(arr[mid]==compliment){
            return arr[mid];
        }
        else if(arr[mid]>compliment){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
vector<int> M2pairSumClosestToTargetSortedArray(vector<int> arr,int target){
    int n=arr.size();
    int curr_diff=INT_MAX;
    vector<int>ans(2,0);
    for(int i=0;i<n-1;i++){
        int compliment=target-arr[i];
        int temp=binarySearchForClosestPair(arr,i+1,compliment);
        if(curr_diff>abs(compliment-temp)){
            curr_diff=abs(compliment-temp);
            ans={arr[i],temp};
        }
    }
    return ans;
}
//Find closest number in Sorted array
int M1findClosest(vector<int>& arr, int k) {
    int n=arr.size();
    int low=0,high=n-1;
    int res=arr[0];
    while(low<=high){
        int mid = low+(high-low)/2;
        if(abs(k-arr[mid])<abs(k-res)){
            res=arr[mid];
        }
        else if(abs(k-arr[mid])==abs(k-res)){
            res=max(res,arr[mid]);
        }
        if(arr[mid]==k){
            return arr[mid];
        }
        else if(arr[mid]>k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int M2findClosest(vector<int>& arr, int k) {
    int low=0,high=arr.size()-1;
    int res=arr[low];
    while(low<high){
        if(abs(k-arr[low])<abs(k-arr[high])){
            high--;
        }
        else{
            low++;
        }
    }
    return arr[low];
}
//https://www.geeksforgeeks.org/maximum-subarray-sum-modulo-m/
int MaximumSubarrayLengthWithModulom(vector<int> &arr,int m){
    int prefix=0,maxim=0; //prefix-for each step--  maxim--to store maximum value
    set<int>s;
    s.insert(0);
    for(int i=0;i<arr.size();i++){
        prefix=(prefix+arr[i])%m; //calculating modulo prefix at each arr length
        maxim=max(maxim,prefix); //arr={1,2,3,4}; maxim=6; which is prefix at 3rd iteration
        auto it=s.lower_bound(prefix+1); //finding a number just greater than prefix
        if(it!=s.end()){
            maxim=max(maxim,prefix-(*it)+m);
        }
        s.insert(prefix);
    }
    return maxim;
}
//https://www.geeksforgeeks.org/maximum-occurred-integer-n-ranges/
// l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.

//beautiful problem
int maxOccured(int n, int l[], int r[], int maxx) { //here arr_forMaxOccured is declared globally(consists of the range)
    int arr_forMaxOccured[maxx+1];
    for(int i=0;i<n;i++){
        arr_forMaxOccured[l[i]]++;
        arr_forMaxOccured[r[i]+1]--;
    }
    int occurence=arr_forMaxOccured[0],inx=0; //inx-index of occurence
    for(int i=1;i<=maxx;i++){ //maxx is the largest element in all of the ranges(to reduce computation till 10^6 cases)
        arr_forMaxOccured[i]+=arr_forMaxOccured[i-1]; //computing prefix sum
        if(occurence<arr_forMaxOccured[i]){//taking only >  : (if equal-take smaller value)
            inx=i;
            occurence=arr_forMaxOccured[i];
        }
    }
    return inx;
}
//https://www.geeksforgeeks.org/maximum-value-array-m-range-increment-operations/
int findMaxInArrayAfterMrangeIncrement(int n,vector<vector<int>>range){ //range - (a,b,k)- a and b are ranges and k by which incremented
    vector<int>arr(n+1,0); //n+1 because (v[1]+1 is used in subsequent steps)
    for(int i=0;i<range.size();i++){
        vector<int>v=range[i];
        arr[v[0]]+=v[2]; //incrementing lower bound index with k
        arr[v[1]+1]-=v[2]; //decrementing upper bound index + 1 with k: to ensure prefix sum is not affected to elements outside range
    }
    //prefix sum
    int maxx=arr[0];
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+arr[i];
        maxx=max(maxx,arr[i]);
    }
    return maxx;
}
//https://www.geeksforgeeks.org/minimum-cost-for-acquiring-all-coins-with-k-extra-coins-allowed-with-every-coin/
int M1minCost(vector<int>arr,int k){
    int n=arr.size();
    int res=0;
    sort(arr.begin(),arr.end()); //to access minimum elements of array- get more for less
    int coins_needed=ceil((1.0*n/(k+1))); //with one coin we can get k more coins
    for(int i=0;i<coins_needed;i++){
        res+=arr[i];
    }
    return res;
}
void preprocessing(vector<int>&arr){
    sort(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i++){
        arr[i]+=arr[i-1];
    }
    return;
}
int M2minCost(vector<int> arr,int k){ //prefix array used to minimise computation time 
    preprocessing(arr);
    int coins_needed=ceil(1.0*(arr.size())/(k+1));
    return arr[coins_needed-1]; // n coins --> arr[0]+arr[1]....arr[n-1]==prefix[n-1]
}
//https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
int HoarepartitionForKLargest(vector<int> &arr,int left,int right){ //hoare partition
    int pivot=arr[left];
    int i=left-1,j=right;
    while(i<j){
        do{
            i++;
        }while(arr[i]>=pivot);
        do{
            j--;
        }while(arr[j]<=pivot);

        if(i>=j){
            return j;
        }
        swap(arr[i],arr[j]);
    }
    return j;
}
int LomutoPartitionForKLargest(vector<int> &arr,int left,int right){
    int pivot=arr[right];
    int index=left;
    for(int i=left;i<right;i++){
        if(arr[i]>=pivot){
            swap(arr[index++],arr[i]);
        }
    }
    swap(arr[index],arr[right]);
    return index;
}
void quickSelect(vector<int> &arr,int left,int right,int k){
    if(left<=right){
        int pivotInx=LomutoPartitionForKLargest(arr,left,right);
        int leftcnt=pivotInx-left+1;
        if(leftcnt==k){
            return; //array modified such that first k elements are largest
        }
        else if(leftcnt>k){
            quickSelect(arr,left,pivotInx-1,k);
        }
        else{
            quickSelect(arr,pivotInx+1,right,k-leftcnt);
        }
    }
    return;
}
vector<int> M1kLargest(vector<int>& arr, int k) {
    quickSelect(arr,0,arr.size()-1,k);
    vector<int>v(arr.begin(),arr.begin()+k);
    sort(v.begin(),v.end(),greater<int>());
    return v;
}
vector<int> M2kLargest(vector<int> &arr,int k){
    priority_queue<int,vector<int>,greater<int>>minHeap(arr.begin(),arr.begin()+k);
    for(int i=k;i<arr.size();i++){
        if(minHeap.top()<arr[i]){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    vector<int>res;
    while(!minHeap.empty()){
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
//https://www.geeksforgeeks.org/random-number-generator-in-arbitrary-probability-distribution-fashion/
int myCeil(vector<int>prefix,int l,int r,int x){ //we need to find value of x
    while(l<r){
        int mid=l+(r-l)/2;
        if(x>prefix[mid]){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    if(prefix[l]>=x){
        return l;
    }
    return -1;
}
int myRand(vector<int>arr,vector<int>freq){
    int n=arr.size();
    vector<int>prefix(n,0);
    prefix[0]=freq[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+freq[i]; 
    }

    //summation of all prefix gives us total occurences of all numbers
    int rand_number=(rand()%prefix[n-1])+1;
    int res=myCeil(prefix,0,n-1,rand_number);
    return arr[res];
}
//https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
bool isSubset(vector<int> &a, vector<int> &b) {
    int n=a.size();
    unordered_set<int>s(a.begin(),a.end());
    for(int i=0;i<b.size();i++){
        if(s.find(b[i])==s.end()){
            return false;
        }
    }
    return true;
}
//https://www.geeksforgeeks.org/check-two-given-sets-disjoint/
bool areDisjoint(vector<int> &a, vector<int> &b) {
    unordered_set<int>s(a.begin(),a.end());
    for(int i=0;i<b.size();i++){
        if(s.find(b[i])!=s.end()){
            return false;
        }
    }
    return true;
}
//https://www.geeksforgeeks.org/check-if-two-arrays-are-equal-or-not/
bool checkEqual(vector<int>& a, vector<int>& b) {
    unordered_map<int,int>m;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
        m[b[i]]--;
    }
    for(auto x:m){
        if(x.second!=0){
            return false;
        }
    }
    return true;
}
//https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/
int maxDistance(vector<int> &arr) {
    unordered_map<int,int>m;
    int max_length=0;
    for(int i=0;i<arr.size();i++){
        if(m.find(arr[i])!=m.end()){
            max_length=max(max_length,i-m[arr[i]]);
        }
        else{
            m[arr[i]]=i;
        }
    }
    return max_length;
}
//https://www.geeksforgeeks.org/intersection-of-two-arrays/
vector<int> M1intersectionWithDuplicates(vector<int>& a, vector<int>& b) { //method-1 (we use two sets)
    unordered_set<int>s(a.begin(),a.end());
    unordered_set<int>ans;
    for(int i=0;i<b.size();i++){
        if(s.find(b[i])!=s.end()){
            ans.insert(b[i]);
        }
    }
    vector<int>final_ans(ans.begin(),ans.end());
    return final_ans;
}
vector<int> M2intersectionWithDuplicates(vector<int>& a, vector<int>& b) { //method-1 (we use two sets)
    unordered_set<int>s(a.begin(),a.end());
    vector<int>ans;
    for(int i=0;i<b.size();i++){
        if(s.find(b[i])!=s.end()){
            ans.push_back(b[i]);
            s.erase(b[i]); //now b[i] can no longer be printed twice //genius step
        }
    }
    return ans;
}
//https://www.geeksforgeeks.org/union-of-two-arrays/
int findUnion(vector<int>& a, vector<int>& b) {
    unordered_set<int>s(a.begin(),a.end());
    for(int i=0;i<b.size();i++){
        if(s.find(b[i])==s.end()){
            s.insert(b[i]);
        }
    }
    return s.size();
}
//https://www.geeksforgeeks.org/frequent-element-array/
int mostFrequent(vector<int>arr){
    unordered_map<int,int>m;
    int max_value=arr[0],max_freq=1;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
        if(m.find(arr[i])!=m.end()){
            if(m[arr[i]]>max_freq){
                max_freq=m[arr[i]];
                max_value=arr[i];
            }
        }
    }
    cout<<max_freq<<endl;
    return max_value;
}
//Moore’s Voting Algorithm --only valid when an element is greater than n/2 (else wrong answer)
int findCandidate(vector<int>arr){
    int res=0,count=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[res]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            res=i;
            count=1;
        }
    }
    return arr[res]; //it is not the answer(it is a potential candidate)
}
//https:www.geeksforgeeks.org/majority-element/
int isMajority(vector<int>arr){
    int candidate=findCandidate(arr);
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==candidate){
            count++;
        }
    }
    return count>arr.size()/2; 
}
//https://www.geeksforgeeks.org/count-pairs-difference-equal-k/
int countPairsAnotherQuestion(vector<int>& arr, int k) {
    unordered_map<int,vector<int>>m;
    for(int i=0 ;i<arr.size();i++){
        m[arr[i]].push_back(i);
    }
    for(auto x:m){
        sort(x.second.begin(),x.second.end());
        cout<<"element: "<<x.first<<"indexes:";
        printVector(x.second);
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(m.find(abs(k+arr[i]))!=m.end()){
            vector<int>ans=m[abs(k-arr[i])];
            auto it=lower_bound(ans.begin(),ans.end(),i);
            if(it==ans.end()){
                cout<<"if"<<endl;
                count+=(ans.size()+1);
            }
            else{
                cout<<"else"<<endl;
                count+=(ans.size()-*it+1);
            }
        }
    }
    return count;
}
//https://www.geeksforgeeks.org/chocolate-distribution-problem/
int findMinDiff(vector<int>& a, int m) {
    sort(a.begin(),a.end());
    int i=0,j=m-1;
    int diff=INT_MAX,res=INT_MAX;
    while(j<a.size()){
        diff=a[j]-a[i];
        res=min(diff,res);
        i++;
        j++;
    }
    return res;
}
//https://www.geeksforgeeks.org/rearrange-array-arri/
void M1modifyArray(vector<int>& arr) {
unordered_set<int>s(arr.begin(),arr.end());
for(int i=0;i<arr.size();i++){
    if(s.find(i)!=s.end()){
        arr[i]=i;
    }
    else{
        arr[i]=-1;
    }
}
return;
}
void M2modifyArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=-1 && arr[i]!=arr[arr[i]]){
            swap(arr[i],arr[arr[i]]);
        }
    }
    return;
}
//https://www.geeksforgeeks.org/sort-array-contain-1-n-values/
vector<int> M1sortArray(vector<int>& arr) {
    int i=0;
    while(i<arr.size()){
        if(arr[i]!=arr[arr[i]-1]){
            swap(arr[i],arr[arr[i]-1]);
        }
        else{
            i++;
        }
    }
    return arr;
}
vector<int> M2sortArray(vector<int>& arr) { //genius -run time error for huge numbers
    int i=0,n=arr.size();
    for(int i=0;i<arr.size();i++){
        int original_value=arr[i]%(n+1); // because we may have added arr[x]*(n+1) before  now we get only the value which was there in it before addiiton
        int correct_index=original_value-1; // 0-indexing but values start from 1
        arr[correct_index]+=(original_value*(n+1)); //adding because when we do /(n+1) , only original_value remains
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=arr[i]/(n+1);
    }
    return arr;
}
//https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
//comparator function to sort the elements
bool comp(pair<int,int>p1,pair<int,int>p2){ //nice concept
    return (p1.second<p2.second);
}
vector<int> M1reorder(vector<int> arr,vector<int> order){
    vector<pair<int,int>>p;
    for(int i=0;i<arr.size();i++){
        p.push_back({arr[i],order[i]});
    }
    sort(p.begin(),p.end(),comp);
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        ans.push_back(p[i].first);
    }
    return ans;
}
vector<int> M2reorder(vector<int> arr,vector<int> order){
    vector<int>ans(arr.size());
    for(int i=0;i<arr.size();i++){
        ans[order[i]]=arr[i];
    }
    return ans;
}
vector<int> M3reorder(vector<int>&arr,vector<int>&order){
    int i=0;
    int z=*max_element(arr.begin(),arr.end());
    z++; //to take remainder
    for(int i=0;i<arr.size();i++){
        arr[order[i]]=arr[order[i]]%z +(arr[i]%z)*z;
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=arr[i]/z;
    }
    return arr;
}
//https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
int findMin(vector<int>& arr) {
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]<arr[high]){
            return arr[low];
        }
        else if(arr[mid]>=arr[high]){
            low=mid+1; //mid cannot be the minimum
        }
        else if(arr[mid]<arr[high]){
            high=mid; //mid can be the minimum
        }
    }
    return arr[low];
}
//https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
int findMinInSortedRotatedArray(vector<int>arr){//here array is rotated atleast once
    //in a rotated sorted array- at any point ,one half is sorted 
    int low=0,high=arr.size()-1;
    while(low<high){ //if low==high --> it means that it is the minimum
        int mid = low +(high-low)/2;
        if(arr[low]<arr[high]){
            return arr[low];
        }
        else if(arr[mid]>=arr[high]){  //left half is sorted- we wont find element in left half 
            low=mid+1; //the mid element cannot be the minimum
        }
        else if(arr[mid]<arr[high]){ //right half is sorted -- we wont find element there
            high=mid; //mid may be the eminimum-as the sorted array may start from mid itself -->(6,1,2)--arr[mid]=1;
        }
    }
    return arr[low];
}
//https://www.geeksforgeeks.org/maximum-element-in-a-sorted-and-rotated-array/
int findMaxInSortedRotatedArray(vector<int>arr){//here array is rotated atleast once
    //in a rotated sorted array- at any point ,one half is sorted 
    int n=arr.size();
    int low=0,high=arr.size()-1;
    while(low<high){ //if low==high --> it means that it is the minimum
        int mid = low +(high-low)/2;
        if(arr[low]<arr[high]){
            break;
        }
        else if(arr[mid]>=arr[high]){  //left half is sorted- we wont find element in left half 
            low=mid+1; //the mid element cannot be the minimum
        }
        else if(arr[mid]<arr[high]){ //right half is sorted -- we wont find element there
            high=mid; //mid may be the eminimum-as the sorted array may start from mid itself -->(6,1,2)--arr[mid]=1;
        }
    }
    if(low!=0){
        return arr[low-1];
    }
    else{
        return arr[n-1];
    }
    return -1;
}
//https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
int findK(vector<int>arr){
    int low=0,high=arr.size()-1; //finding minimum element and returning its index
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[low]<arr[high]){
            return low;
        }
        else if(arr[mid]>=arr[high]){
            low=mid+1;
        }
        else if(arr[mid]<arr[high]){
            high=mid;
        }
    }
    return low;
}
//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
int searchInSortedRotatedArray(vector<int>arr,int key) {
    int low=0,high=arr.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[low]<=arr[mid]){// left side is sorted
            if(key<arr[mid] && key>=arr[low]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(key>arr[mid] && key<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return (arr[low]==key)?low:-1;
}
//https://www.geeksforgeeks.org/nearly-sorted-algorithm/
void putInRightPlace(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int j=high-1;
    while(j>low-1 && arr[j]>pivot){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=pivot;
    return;
}
void sortInKsortedArray(vector<int>&arr,int k){
    sort(arr.begin(),arr.begin()+k+1);
    int i=1,j=k+2;
    while(j<arr.size()){
        putInRightPlace(arr,i,j);
        i++;
        j++;
    }
    return;
}

//https://www.geeksforgeeks.org/a-product-array-puzzle/
vector<int> productExceptSelf(vector<int>& arr) {
    int prod=1,n=arr.size(),count_of_zeros=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count_of_zeros++;
        }
        else{
            prod*=arr[i];
        }
    }
    cout<<prod<<endl;
    vector<int>ans(n,0);
    if(count_of_zeros>1){
        return ans;
    }
    for(int i=0;i<n;i++){
        if(count_of_zeros==0){
            ans[i]=prod/arr[i];
        }
        else{
            if(arr[i]==0){
                ans[i]=prod;
            }
        }
    }
    return ans;
}
// //https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// int kthLargestSum(vector<int>arr, int k){
//     int n=arr.size();
//     priority_queue<int,vector<int>,greater<int> >p;
//     vector<int>ans(n+1,0);
//     for(int i=0;i<n;i++){

//     }
// }
//https://www.geeksforgeeks.org/find-the-first-missing-number/
int findMissingNumber(vector<int>arr,int m){
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    for(int i=0;i<m;i++){
        if(s.find(i)==s.end()){
            return i;
        }
    }
    return -1;
}
//https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/
int smallestSubWithSum(int x, vector<int>& arr) {
    int n=arr.size();
    vector<int>prefix(n+1,0);
    prefix[1]=arr[0];
    if(*max_element(arr.begin(),arr.end())>x){
        return 1; 
    }
    for(int i=0;i<n;i++){
        prefix[i+1]=arr[i]+prefix[i];
    }
    printVector(prefix);
    int i=0,j=1,res_min=INT_MAX;
    while(i<j && j<=n){
        if(prefix[j]-prefix[i]>x){
            res_min=min(res_min,j-i);
            i++;
        }
        else{
            j++;
        }
    }
    return res_min==INT_MAX?0:res_min;
}
//https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/

int merge(vector<int>&arr,int low,int mid,int high){
    int z=0;
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
            z+=(n1-i);
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
            i++;
            k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
    return z;
}
int mergeSortInversionCount(vector<int>&arr,int low,int high){
    
    int res=0;
    if(low<high){
        int mid=low+(high-low)/2;
        res+=mergeSortInversionCount(arr,low,mid);
        res+=mergeSortInversionCount(arr,mid+1,high);
        res+=merge(arr,low,mid,high);
    }
    return res;
}
//https://www.geeksforgeeks.org/merging-intervals/
vector<vector<int>> M1mergeOverlap(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
        int first=arr[i][0];
        int end=arr[i][1]; //res contains the last merged interval 
        if(!res.empty() && res.back()[1]>=end){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(end>=arr[j][0]){
                end=max(end,arr[j][1]);
            }
        }
        res.push_back({first,end});
    }
    return res;
}
vector<vector<int>> M2mergeOverlap(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>res;
    res.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(res.back()[1]>=arr[i][0]){ //{1,5}{2,4} 5 is greater than 5
            res.back()[1]=max(res.back()[1],arr[i][1]);
        }
        else{
            res.push_back(arr[i]);
        }
    }
    return res;
}
int M3mergeOverlap(vector<vector<int>> &arr){ //no space required but arr is changed
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int res_index=0;
    for(int i=1;i<n;i++){
        if(arr[res_index][1]>=arr[i][0]){ //{1,5}{2,4} 5 is greater than 5
            arr[res_index][1]=max(arr[res_index][1],arr[i][1]);
        }
        else{
            res_index++;
            arr[res_index]=arr[i];
        }
    }
    return res_index+1;
}
//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
void sort012(vector<int>& arr) {
    int n=arr.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){ 
            swap(arr[mid++],arr[low++]); //why mid++ --> here arr[low] always=1 and we only swap(0 and 1) or (0 and 0)
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high--],arr[mid]); //here no mid++ beause we dont know what element we are swapping with (it may be 0,1,2)
            //hence we have to check mid again -> not incrementing the value
        }
    }
    return;
}
//https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
void M1mergeArrays(vector<int>& a, vector<int>& b) { //time limit exceeded for 1 case
    int n1=a.size(),n2=b.size();
    int i=0;
    while(i<n1){
        if(a[i]>=b[0]){
            int k=1;
            while(b[k]<a[i] && k<n2){
                k++;
            }

            k--;
            while(k>=0){
                swap(a[i],b[k]);
                k--;
            }
        }
        i++;
    }
    return;
}
void M2mergeArrays(vector<int>& a, vector<int>& b) {
    int n1=a.size(),n2=b.size();
    int i=n1-1,j=0;
    while(i>=0 && j<n2 && a[i]>b[j]){
        swap(a[i--],b[j++]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return;
}
void M3mergeArrays(vector<int>& a, vector<int>& b) {
    int n1=a.size(),n2=b.size();
    for(int i=n2-1;i>=0;i--){
        if(a.back()>b[i]){
            int last=a.back();
            int j=n1-2;
            while(j>=0 && b[i]<a[j]){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=b[i];
            b[i]=last;
        }
    }
    return;
}
//https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
int M1peakElement(vector<int> &arr) { //every array has a peak
    int n=arr.size();
    if(n<=1){
        return 0;
    }
    if(n==2){
        return (arr[0]>arr[1])?0:1;
    }
    int i=0,j=1,k=2;
    if(arr[n-1]>arr[n-2]){
        return n-1;
    }
    while(k<n){
        if(arr[i]<arr[j] && arr[j]>arr[k]){
            return j;
        }
        i++;
        j++;
        k++;
    }
    return 0; //loop will never reach here 
}
int M2peakElement(vector<int> &arr) {
    int n=arr.size();
    int low=0,high=n-1;
    if(n<=1){
        return 0;
    }
    if(n==2){
        return (arr[0]>arr[1])?0:1;
    }
    if(arr[n-1]>arr[n-2]){
        return n-1;
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(mid!=0 && arr[mid-1]>arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

bool hasMatch(string s, string p) {
    int index=p.find("*");
    // cout<<"the index of * "<<index<<endl;
    int n=p.length();
    int length_of_s=s.length();
    string left_half=p.substr(0,index);
    // cout<<"left half is"<<left_half<<endl;
    string right_half=p.substr(index+1,n-index);
    // cout<<"right half is "<<right_half<<endl;
    // cout<<s.find(left_half)<<endl;
    if(left_half=="" && right_half==""){
        return true;
    }
    if(s.find(left_half)!=string::npos){
        int z=s.find(left_half);
        int size_of_z=left_half.length();
        string remaining=s.substr(z+size_of_z,length_of_s);
        // cout<<remaining<<endl;
        if(remaining.find(right_half)!=string::npos || right_half==""){
            return true;
        }
    }
    return false;
}
// TaskManager(vector<vector<int>>& tasks) {
//         for(int i=0;i<tasks.size();i++){
//             vector<int>temp=tasks[i];
//             if(temp.size()==3){
//                 add(temp[0],temp[1],temp[2]);
//             }
//             if(temp.size()==2){
//                 edit(temp[0],temp[1]);
//             }
//         }
//     }
    
//     void add(int userId, int taskId, int priority) {
//         tasks.push_back({userId,taskId,priority});
//         return;
//     }
    
//     void edit(int taskId, int newPriority) {

//         for(int i=0;i<tasks.size();i++){
//             vector<int>edit_vector=tasks[i];
//             if(edit_vector.size()==3){
//                 if(edit_vector[1]==taskId){
//                     edit_vector[2]=newPriority;
//                     return;
//                 }
//             }
//         }
//         return;
//     }
    
//     void rmv(int taskId) {
//         for(int i=0;i<tasks.size();i++){
//             vector<int>rmv_vector=tasks[i];
//             if(rmv_vector.size()==3){
//                 if(rmv_vector[2]==taskId){
//                     tasks.erase(rmv_vector);
//                     return;
//                 }
//             }
//         }
//         return;
//     }
    
//     int execTop() {
//         vector<int>storing={-1,-1,-1};
//         int maxx=INT_MIN;
//         for(int i=0;i<tasks.size();i++){
//             vector<int>execTop_vector=tasks[i];
//             if(execTop_vector.size()==3){
//                 if(maxx<=execTop_vector[2]){
//                     if(maxx==execTop_vector[2] && execTop_vector[1]>storing[1]){
//                         storing=execTop_vector;
//                     }
//                     else if(maxx<execTop_vector[2]){
//                         storing=execTop_vector;
//                         maxx=execTop_vector[2];
//                     }
//                 }
//             }
//         }
//         if(storing[1]==-1){
//             return -1;
//         }
//         int temp=storing[1];
//         tasks.erase(storing);
//         return temp;
        
//     }
//https://www.geeksforgeeks.org/find-local-minima-array/
int findLocalMin(vector<int>arr){ //return the index
    //every array has a local minima
    int n=arr.size();
    if(n<=1){
        return 0;
    }
    if(arr[0]<arr[1]){
        return 0;
    }
    if(arr[n-1]<arr[n-2]){
        return n-1;
    }
    int low=0,high=n-1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
            return mid;
        }
        else if( mid>0 && arr[mid]>arr[mid-1]){ //if element on left is smaller -->min lies on left
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
//https://www.geeksforgeeks.org/find-number-of-triangles-possible/
int M1countTriangles(vector<int>& arr) {
    int n=arr.size(),count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        int j=i+1,k=i+2;
        while(j<n){
            while(k<n){
                if(arr[i]+arr[j]>arr[k] && arr[i]+arr[k]>arr[j] && arr[j]+arr[k]>arr[i]){
                    count++;
                    k++;
                }
                else{
                    k=n;
                }
            }
            j++;
            k=j+1;
        }
    }
    return count;
}
int M2countTriangles(vector<int>& arr) {
    int n=arr.size(),count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int k=lower_bound(arr.begin()+j+1,arr.end(),arr[i]+arr[j])-arr.begin();
            count+=(k-j-1);
        }
    }
    return count;
}
int M3countTriangles(vector<int>& arr) {
    int n=arr.size(),count=0;
    sort(arr.begin(),arr.end());
    for(int i=2;i<n;i++){
        int j=0,k=i-1;
        while(j<k){
        if(arr[j]+arr[k]>arr[i]){
            count+=(k-j);
            k--;
        }
        else{
            j++;
        }
    }  
    }
    return count;
}
//https://www.geeksforgeeks.org/find-subarray-with-given-sum/
vector<int> subarraySum(vector<int> &arr, int target) {
    int n=arr.size();
    int sum=0,i=0,j=0;
    while(j<n){
        sum+=arr[j];
        if(sum==target){
            return {i+1,j+1};
        }
        else if(sum>target){
            sum-=arr[i];
            i++;
        }
        else{
            j++;
            sum+=arr[j];
        }
    }
    return {-1};

}
//https://www.geeksforgeeks.org/find-missing-elements-of-a-range/
vector<int> M1findMissingElementsInARange(vector<int>arr,int low,int high){
    int n=arr.size();
    vector<int>ans;
    sort(arr.begin(),arr.end());
    auto index=lower_bound(arr.begin(),arr.end(),low);
    int i=index-arr.begin();
    int x=low;
    while(i<n && x<=high){
        if(arr[i]!=x){
            ans.push_back(x);
        }
        else{
            i++;
        }
        x++;
    }
    while(x<=high){
        ans.push_back(x);
        x++;
    }
    return ans;
}
vector<int> M2findMissingElementsInARange(vector<int>arr,int low,int high){
    int n=arr.size();
    vector<bool>arr_low_to_high(high-low+1,true);
    for(int i=0;i<n;i++){
        if(arr[i]-low>=0){
            arr_low_to_high[arr[i]-low]=false;
        }
    }
    vector<int>ans;
    for(int i=0;i<arr_low_to_high.size();i++){
        if(arr_low_to_high[i]){
            ans.push_back(low+i);
        }
    }
    return ans;
}
vector<int> M3findMissingElementsInARange(vector<int>arr,int low,int high){
    int n=arr.size();
    unordered_set<int>s(arr.begin(),arr.end());
    vector<int>ans;
    for(int i=low;i<=high;i++){
        if(s.find(i)==s.end()){
            ans.push_back(i);
        }
    }
    return ans;
}
//https://www.geeksforgeeks.org/minimum-number-subsets-distinct-elements/
int M1minNoOfSubsetsWithDistinctElements(vector<int>arr){
    unordered_map<int,int>m;
    int max_freq=0; //storing count of most frequently occured element--> minimum no. of subsets
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
        if(max_freq<m[arr[i]]){
            max_freq=m[arr[i]];
        }
    }
    return max_freq;
}
// int M2minNoOfSubsetsWithDistinctElements(vector<int>arr){
//     //method for c programming
//     //while traversing the array 
//     //if element present , then increment count++ and delete the entire set(made through LL)
//     //then add the current element as fresh node
//     //at the end of all the traversals.. if count==0?1:count+1 -->count is the count of duplicates apart from the original.
//     //hence we do return count+1(which is the frequency of the most occuring element and hence our answer)
// }
int M2minNoOfSubsetsWithDistinctElements(vector<int>arr){ //MY FIRST DYNAMIC PROGRAMMING PROBLEM :)
    int n=arr.size();
    int dp[n]; //stores the minimum subsets required 
    //indirectly stores frequency
    dp[0]=1;
    unordered_set<int>s;
    s.insert(arr[0]);
    for(int i=1;i<n;i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            dp[i]=dp[i-1];
        }
        else{
            dp[i]=dp[i-1]+1; //frequency updated by 1 (if dp[i-1] was 5 -->then now freq is 6)
            s.clear();
            s.insert(arr[i]);
        }
    }
    return dp[n-1]; //gives the frequency of most frequently occured element
}
//https://www.geeksforgeeks.org/2-sum-find-all-pairs-with-given-sum/
vector<vector<int>> findAllPairs(vector<int> &arr, int target) {
    int n=arr.size();
    vector<vector<int>>res;
    unordered_map<int,vector<int>>m;
    for(int i=0;i<n;i++){
        if(m.find(target-arr[i])!=m.end()){
            vector<int>temp=m[target-arr[i]];
            for(auto x:temp){
                res.push_back({x,i});
            }
        }
        m[arr[i]].push_back(i);
    }
    sort(res.begin(),res.end());
    return res;
}
//https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/
vector<vector<int>> M1distinctPairs(vector<int> &arr, int target) {
    int n=arr.size();
    set<vector<int>>res; //no vector<int> data type for unordered set
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        if(s.find(target-arr[i])!=s.end()){
                if(target-arr[i]>arr[i]){
                    res.insert({arr[i],target-arr[i]});
                }
                else{
                    res.insert({target-arr[i],arr[i]});
                }
            }
            s.insert(arr[i]);
        }
    vector<vector<int>>ans(res.begin(),res.end());
    return ans;
}
vector<vector<int>> M2distinctPairs(vector<int> &arr, int target) { //two pointer approach
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>res; //no vector<int> data type for unordered set
    int low=0,high=n-1;
    while(low<high){
        while(low>0 && arr[low]==arr[low-1]){ //elegant way of skipping through duplicates
            low++;
        }
        // if(low>0 && arr[low]==arr[low-1]){
        //     low++;
        //     continue;
        // }
        // if(high<n-1 && arr[high]==arr[high+1]){
        //     high--;
        //     continue;
        // }
        //now no need of if(arr[low]>arr[high])
        //why? bcas we check while(low<high)-->every time we increment low or decrement high        
        while(high<n-1 && arr[high]==arr[high+1]){//elegant way of skipping through duplicates
            high--; 
        }
        if(arr[low]>arr[high]){  //why? in one case low becomes greater than high but the while loop already checked (soo 1 duplicate pair will enter -->if any)
        //suppose 5,6 was a pair and now {6,5} will also be added-->this is avoided by this condition
            break;
        }
        if(arr[low]+arr[high]==target){
            res.push_back({arr[low],arr[high]});
            low++;
            high--;
        }
        else if(arr[low]+arr[high]>target){
            high--;
        }
        else{
            low++;
        }
    }
    return res;
}
vector<vector<int>> M3distinctPairs(vector<int> &arr, int target) {
    int n=arr.size();
    vector<vector<int>>res; //no vector<int> data type for unordered set
    unordered_map<int,int>m; //this is to keep track of frequncies 
    for(int i=0;i<n;i++){
        int compliment=target-arr[i];
        if(compliment==arr[i]){ //arr[i] and compliment =25 and target =50
            if(m.find(compliment)!=m.end() && m[compliment]<=1){ // if count of compliment is 2 or more-->would've already been counted in
            //previous iteration
                res.push_back({arr[i],compliment});
            }
        }
        else if(compliment!=arr[i]){
            if(m.find(compliment)!=m.end()&& m[arr[i]]==0){ //compliment must be there and arr[i] must not be there
            //if m[arr[i]]>0 and compliment is already there(freq doesnt matter:compliment is useless without arr[i])
            //then it wouldve already been added into the ans (in previous iterations)
            int first=min(compliment,arr[i]);
                res.push_back({first,target-first});
            }
        }
        m[arr[i]]++;
    }
    sort(res.begin(),res.end());
    return res;
}
//https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
bool M1hasTripletSum(vector<int> &arr, int target) {
    int n=arr.size();
    unordered_set<int>s;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            // cout<<"index of i and j :"<<i<<" "<<j<<endl;
            // cout<<"sum of"<<sum;
            if(s.find(target-sum)!=s.end()){
                return true;
            }
        }
        s.insert(arr[i]);
    }
    return false;
}
bool M2hasTripletSum(vector<int> &arr, int target) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        int low=i+1,high=n-1;
        int findSum=target-arr[i];
        while(low<high){
            if(arr[low]+arr[high]==findSum){
                return true;
            }
            else if(arr[low]+arr[high]>findSum){
                high--;
            }
            else{
                low++;
            }
        }
    }
    return false;
}
//https://www.geeksforgeeks.org/4-sum-find-any-quadruplet-having-given-sum/
//sorting and two pointer -->O(n^3)
vector<int> findQuadruplet(vector<int> &arr, int target){ //returns only one quadruple(many others may exist)
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int low=j+1,high=n-1;
            while(low<high){
                int sum=target-arr[i]-arr[j];
                if(arr[low]+arr[high]==sum){
                    return {arr[i],arr[j],arr[low],arr[high]}; //this prints the indexes
                                           // if we want values replace index with arr[index]
                }
                else if(arr[low]+arr[high]>sum){
                    high--;
                }
                else{
                    low++;
                }
            }
            
        }
    }
    return {};
}
//https://www.geeksforgeeks.org/find-surpasser-count-of-each-element-in-array/
void mergeForSurpasserCount(vector<int>&arr,unordered_map<int,int>&m,int low,int mid,int high){
    int res=0;
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i]; //here mid is included
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+1+i]; //so hence mid+1
    }
    int a=0,b=0,k=low;
    while(a<n1 && b<n2){
        if(left[a]<=right[b]){
            m[left[a]]+=(n2-b);
            arr[k++]=left[a++];
        }
        else{
            arr[k++]=right[b++];
        }
    }
    while(a<n1){
        arr[k++]=left[a++];
    }
    while(b<n2){
        arr[k++]=right[b++];
    }
}
void mergeSortForSurpasserCount(vector<int>&arr,unordered_map<int,int>&m,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSortForSurpasserCount(arr,m,low,mid);
        mergeSortForSurpasserCount(arr,m,mid+1,high);
        mergeForSurpasserCount(arr,m,low,mid,high);
    }
    
}
//https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/
//METHOD-1
struct CustomComparator{
    bool operator()(const pair<int,int>&p1,const pair<int,int>&p2){
        return (p1.second<p2.second || (p1.second==p2.second && p1.first<p2.first));
    }
};

vector<int> M1findKMostFrequent(vector<int>arr,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,CustomComparator>p;
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    for(auto x: m){
        p.push({x.first,x.second});
    }
    vector<int>ans;
    int count=k;
    while(k>0 && !p.empty()){
        ans.push_back((p.top()).first);
        p.pop();
        k--;
    }
    return ans;
}
bool comparator(const pair<int,int>&p1,const pair<int,int>&p2){
        return (p1.second>p2.second || (p1.second==p2.second && p1.first>p2.first));
}
vector<int> M2findKMostFrequent(vector<int>arr,int k){
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    vector<pair<int,int>>freq_array(m.begin(),m.end());
    sort(freq_array.begin(),freq_array.end(),comparator);
    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(freq_array[i].first);
    }
    return ans;
}

// //https://www.geeksforgeeks.org/k-th-missing-element-in-sorted-array/
// int kthMissing(vector<int> &arr, int k) {
//     int n=arr.size();
//     int max_element=arr[n-1];
//     int count=0,index=0;
//     if(arr[0]==1){
//         count-=
//     }
// }

//BINARY_SEARCH-lower_bound and upper_bound functions --only work for sorted arrays


//https://www.geeksforgeeks.org/program-to-find-largest-element-in-an-array/
int M1largestInArray(vector<int>&arr,int i){
    if(i==arr.size()-1){
        return arr[arr.size()-1];
    }
    return max(arr[i],M1largestInArray(arr,i+1));
}
int M2largestInArray(vector<int>&arr){
    int maxx=INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxx=max(arr[i],maxx);
    }
    return maxx;
}
//https://www.geeksforgeeks.org/sort-array-wave-form-2/
void convertToWave(vector<int>& arr){ //O(nlogn) -using sort
    int n=arr.size();
    sort(arr.begin(),arr.end());
    if(n<=2){
        return;
    }
    int low=0,high=1;
    while(high<n){
        swap(arr[low],arr[high]);
        low=low+2;
        high=high+2;
    }
    return;
}
//Kadane's Algorithm
int KadaneAlgorithm(vector<int>arr){
    int res=arr[0],curr_sum=arr[0];
    for(int i=1;i<arr.size();i++){
        curr_sum=max(curr_sum+arr[i],arr[i]);
        res=max(res,curr_sum);
    }
    return res;
}
//https://www.geeksforgeeks.org/maximum-subarray-sum-array-created-repeated-concatenation/
//and
//LEETCODE-
//https://leetcode.com/problems/k-concatenation-maximum-sum/description/
//DIFFERENCE BETWEEN TWO PROBLEMS-GFG-HAVE TO TAKE 1 ELEMENT(EVEN IF -VE)
//LEETCODE -JUST TAKE 0 (IF ALL NEGATIVE)  and module 10^9+7
//METHOD-1
int KadaneAlgorithmForKConcatenateProblem(vector<int>arr){
    int res=arr[0]%1000000007,curr_sum=arr[0]%1000000007;
    for(int i=1;i<arr.size();i++){
        curr_sum=max((curr_sum+arr[i])%1000000007,arr[i]%1000000007);
        res=max(res,curr_sum);
    }
    return res%1000000007;
}
int sumOfEntireArray(vector<int>arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i]%1000000007;
    }
    return sum;
}
int MaxsumFromBeginning(vector<int>arr){
    int sum=arr[0],maxx=arr[0];
    for(int i=1;i<arr.size();i++){
        sum+=arr[i]%1000000007;
        maxx=max(maxx,sum);
    }
    return maxx%1000000007;
}
int SummingKTimesToPreventOverflow(int sum,int k){
    int res=0;
    for(int i=0;i<k;i++){
        res=(res+sum)%1000000007;
    }
    return res%1000000007;
}
int MaxSumFromEnding(vector<int>arr){
    int n=arr.size();
    int sum=arr[n-1],maxx=arr[n-1];
    for(int i=n-2;i>=0;i--){
        sum+=arr[i]%1000000007;
        maxx=max(maxx,sum);
    }
    return maxx%1000000007;
}
int kConcatenationMaxSum(vector<int>& arr, int k) {
    if(k==1){
        return max(KadaneAlgorithmForKConcatenateProblem(arr),0);
    }
    if(k>=2){
        int sum=sumOfEntireArray(arr);
        if(sum>0){
            return (SummingKTimesToPreventOverflow(sum,k-2) + (MaxsumFromBeginning(arr)+MaxSumFromEnding(arr))%1000000007)%1000000007;
        }
        else{
            int first_max=max(KadaneAlgorithmForKConcatenateProblem(arr),(MaxsumFromBeginning(arr)+MaxSumFromEnding(arr))%1000000007);
            return max(first_max,0);
        }
    }
    return 0;
}
//METHOD-2
int maxSubArraySumRepeated(vector<int>& arr, int k) {
    int64_t n=arr.size();
    long long res=INT_MIN,curr=0;
    for(int64_t i=0;i<n*k;i++){
        curr=(curr%1000000007+arr[i%n])%1000000007;
        res=max(res%1000000007,curr%1000000007);
        if(curr<0){
            curr=0;
        }
    }
    return (res>0)?res:0;
}
//https://www.geeksforgeeks.org/stock-buy-sell/
int maximumProfit(vector<int> &prices) {
    int profit=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            profit+=(prices[i]-prices[i-1]);
        }
    }
    return profit;
}
//STOCK BUY AND SELL
int maxProfit(vector<int>& prices) {
    auto large_index=max_element(prices.begin(),prices.end())-prices.begin();
    auto small_index=min_element(prices.begin(),prices.end())-prices.begin();
    int minimum=INT_MAX;
    for(int i=0;i<large_index;i++){
        minimum=min(minimum,prices[i]);
    }
    int max_profit_1=prices[large_index]-minimum;
    int maximum=INT_MIN;
    for(int i=small_index;i<prices.size();i++){
        maximum=max(maximum,prices[i]);
    }
    int max_profit_2=maximum-prices[small_index];
    return (max(max_profit_1,max_profit_2));
}
//https://www.naukri.com/code360/contests/weekly-contest-163/17813033/problems/31157?leftPanelTabValue=PROBLEM
int minimumChanges(int n, vector<int> &v) {
    if(n==1){
        return 0;
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]>1){
            count++;
            v[i]=v[i-1]+1;
        }
    }
    return count;
}

int minSizeOfArray(vector<int>v){
    int n=v.size();
    bool even_flag=false;
    bool odd_flag=false;
    for(int i=0;i<n;i++){
        if(v[i]%2==0){
            even_flag=true;
        }
        else {
            odd_flag=true;
        }
        if(even_flag && odd_flag){
            return 1;
        }
    }
    return n;
}
//Problem statement
// You are given two positive integers 'A' and 'B'.
// In one operation, you can update 'A' to '|A - B|'.
// You are able to perform the above operation any number of times (including 0). Determine the number of different values of 'A' you can generate.
// Example:
// A = 5
// B = 3
// The total possible values of 'A' you can generate are '2', '3', and '5'.
// So, the answer for this case is '3'.
int numberofvalues(int a,int b){
    int count=(a-1)/b;
    if(a%b!=abs(a%b-b)){
        return count+2;
    }
    return count+1;
}
// int minimumOperations(int n, string &s){
//     string t="01";
//     unordered_set<string>set={"0","1","01"};
//     int i=2;
//     int count=0;
//     while(i<n){
//         cout<<"hello1\n";
//         auto index=s.begin()+i;
//         string r=s.substr(index,2);
//         cout<<r<<endl;
//         //cout<<set.find(s.substr(i,2))!=set.end();
//         if(i<n-2 && set.find(s.substr(i,2))!=set.end()){
//             i=i+2;
//             set.insert(s.substr(i-3,2));
//             count++;
//             cout<<"hello2\n";
//         }
//         else if(i<n-2 && set.find(s.substr(i,2))==set.end()){
//             count++;
//             set.insert(s.substr(i-1,2));
//             i++;
//             cout<<"hello3\n";
//         }
//         else if(i==n-2){
//             count++;
//             i++;
//             cout<<"hello4\n";
//         }
//     }
//     return count;
// }
//https://www.geeksforgeeks.org/square-root-of-an-integer/
int M1floorSqrt(int n) { //->not a good solution
    if(n<4){
        return 1;
    }
    int a=2;
    while(a*a<=n){
        a=a*2;
    }
    if(a*a==n){
        return a;
    }
    else{
        while(a*a>n){
            a--;
        }
        return a;
    }
}
int M2floorSqrt(int n) {
    int res=1;
    while(res*res<=n){
        res++;
    }
    return res-1;
}
int M3floorSqrt(int n) {
    int low=1,high=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
int M4floorSqrt(int n){
    int ans= exp(log(n)/2); //problem-->due to decimal truncation-->some values reduced by 1
    if((ans+1)*(ans+1)<=n){ //solution-->check for the next value
        return ans+1;
    }
    return ans;
}

//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
//GOAL-->minimise the number of comparsions
pair<int, int> M1getMinMax(vector<int> arr) {  //->2n comparisons
    int min_ele=INT_MAX,max_ele=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<min_ele){ //-->n comparisons
            min_ele=arr[i];
        }
        if(arr[i]>max_ele){ //-->n comparisons
            max_ele=arr[i];
        }
    }
    return {min_ele,max_ele};
}

pair<int, int> M2getMinMax(vector<int> arr) {  //->(nlogn) comparisons -->any sorting algo has atmost n comparisons
    sort(arr.begin(),arr.end());
    return {arr[0],arr[arr.size()-1]}; 
}
pair<int,int> M3getMinMax(vector<int>arr){ //--> 1+2*(n-2)->worstcase-->reverse sorted array
                                            //--> 1+ (n-2)-->bestcase-->sorted array
    int n=arr.size();
    if(n==1){
        return {arr[0],arr[0]};
    }
    int minn,maxx;
    if(arr[0]>arr[1]){
         maxx=arr[0];
         minn=arr[1];
    }
    else{
         minn=arr[0];
         maxx=arr[1];
    }
    for(int i=2;i<n;i++){
        if(arr[i]>maxx){
            maxx=arr[i];
        }
        else if(arr[i]<minn){
            minn=arr[i];
        }
    }
    return {minn,maxx};
}
pair<int,int> M4getMinMax(vector<int>arr,int low,int high){ //3n/2 -2 comparisons in best case->(n-->power of 2)
                                                            // else >3n/2 -2 comparisons
    pair<int,int> ans,left,right;
    if(low==high){
        return {arr[low],arr[low]};
    }
    if(low+1==high){
        if(arr[low]>arr[high]){
            return {arr[high],arr[low]};
        }
        else{
            return {arr[low],arr[high]};
        }
    }
    int mid=low+(high-low)/2;
    left=M4getMinMax(arr,low,mid);
    right=M4getMinMax(arr,mid+1,high);
    if(left.first>right.first){
        ans.first=right.first;  //minimum element
    }
    else{
        ans.first=left.first;   //minimum element
    }
    if(left.second>right.second){
        ans.second=left.second; //maximum element
    }
    else{
        ans.second=right.second; //maximum element
    }
    return ans;
}
pair<int,int> M5getMinMax(vector<int>arr){ //->3(n-2)/2 +1 ->when  n is even
                                            //3(n-1)/2 -->when n is odd
    int n=arr.size();
    pair<int,int>p;
    int i;
    if(n%2==0){
        if(arr[0]>arr[1]){
            p={arr[1],arr[0]};
        }
        else{
            p={arr[0],arr[1]};
        }
        i=2;
    }
    else{
        p={arr[0],arr[0]};
        i=1;
    }
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i]>p.second){
                p.second=arr[i];
            }
            if(arr[i+1]<p.first){
                p.first=arr[i+1];
            }
        }
        else{
            if(arr[i+1]>p.second){
                p.second=arr[i+1];
            }
            if(arr[i]<p.first){
                p.first=arr[i];
            }
        }
    i+=2;
    }
    return p;
}
//https://www.geeksforgeeks.org/find-frequency-of-each-element-in-a-limited-range-array-in-less-than-on-time/
void M1frequencyOfEachElementLimitedRange(vector<int>arr,int low,int high,unordered_map<int,int>&m){    
            //TC->O(logn)
            //SC->O(n)
    if(low<=high){
        if(low==high){
            m[arr[low]]++;
            return;
        }
        int mid=low+(high-low)/2;
        if(arr[mid]==arr[low]){
            m[arr[low]]+=(mid-low+1);
            M1frequencyOfEachElementLimitedRange(arr,mid+1,high,m);
            return;
        }
        else if(arr[mid+1]==arr[high]){
            m[arr[high]]+=(high-mid);
            M1frequencyOfEachElementLimitedRange(arr,low,mid,m);
            return;
        }
        else{
            M1frequencyOfEachElementLimitedRange(arr,low,mid,m);
            M1frequencyOfEachElementLimitedRange(arr,mid+1,high,m);
            return;
        }
    }
    return;
}
void M2frequencyOfEachElementLimitedRange(vector<int>arr){
    //
    //
    int n=arr.size();
    int i=1,freq=1;
    while(i<n){
        if(arr[i]==arr[i-1]){
            freq++;
        }
        else{
            cout<<"The element "<<arr[i-1]<<" has freq "<<freq<<endl;
            freq=1;
        }
        i++;
    }
    cout<<"The element "<<arr[i-1]<<" has freq "<<freq<<endl;
}
void M3frequencyOfEachElementLimitedRange(vector<int>arr,int low,int high,vector<int>&ans){
    int mid=low+(high-low)/2;
    if(low<=high){
        if(arr[low]==arr[high]){
            ans[arr[low]]+=(high-low+1);
        }
        else{
            M3frequencyOfEachElementLimitedRange(arr,low,mid,ans);
            M3frequencyOfEachElementLimitedRange(arr,mid+1,high,ans);
        }
    }
    return;
}

void M4frequencyOfEachElementLimitedRange(vector<int>arr){ //->fails when *max_element(arr)>=n
    //Time Complexity - O(n)
    //Space Complexity - O(1)
    int n=arr.size();
    
    // for(int i=0;i<n;i++){ // unnecessary step given in the solution
    //     arr[i]--;
    // }
    for(int i=0;i<n;i++){
        arr[arr[i]%n]+=n;
    }
    for(int i=0;i<n;i++){
        if(arr[i]/n){
            cout<<(i+1)<<"has the freq of "<<arr[i]/n<<"\n";
        }
    }
}
void M5frequencyOfEachElementLimitedRange(vector<int>arr){
    //Time Complexity - O(max(n,max_element of n))
    //Space Complexity - O(max_element of n)
    int n=arr.size();
    int maxx=*max_element(arr.begin(),arr.end());
    vector<int>storage(maxx+1,0); //maxx+1-->(we cant store maxx value if we dont +1 )
    for(int i=0;i<n;i++){
        storage[arr[i]]++;
    }
    for(int i=0;i<=maxx;i++){
        if(storage[i]){
            cout<<"freq of "<<i<<"is "<<storage[i]<<"\n";
        }
    }
    return;
}
//https://www.geeksforgeeks.org/search-in-a-row-wise-and-column-wise-sorted-2d-array-using-divide-and-conquer-algorithm/
pair<int,int> searchInSorted(vector<vector<int>>&mat,int x){
    int m=mat.size(),n=mat[0].size();
    int i=0,j=n-1; //starting from top right corner 
    while(i<m && j>=0){
        if(mat[i][j]>x){ //x is less than element than it will be less than all the elements in that column(sorted)
            // cout<<mat[i][j]<<"\n j-value: "<<j<<" \n";
            j--;
        }
        else if(mat[i][j]<x){ //x is greater than that element then x will be greater than 
            // cout<<mat[i][j]<<"\n i-value"<<i<<" \n";;
            i++;
        }
        else{
            return {i,j};
        }
    }
    return {-1,-1};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //printing vector template
        // vector<int>ans;
        // ans=M2intersectionWithDuplicates(arr1,arr2);
        // printVector(ans);
        // ans=M2intersectionWithDuplicates(arr3,arr4);
        // printVector(ans);
        // ans=M2intersectionWithDuplicates(arr5,arr6);
        // printVector(ans);
    //printing vector of vector template
        // vector<vector<int>>ans;
        // ans=M2distinctPairs(arr1,6);
        // for(int i=0;i<ans.size();i++){
        //     printVector(ans[i]);
        // }
        // ans=M2distinctPairs(arr2,2);
        // for(int i=0;i<ans.size();i++){
        //     printVector(ans[i]);
        // }
        // ans=M2distinctPairs(arr3,125);
        // for(int i=0;i<ans.size();i++){
        //     printVector(ans[i]);
        // }
    vector<int>arr1={1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
    vector<int>arr2={2, 2, 6, 6, 7, 7, 7, 11};
    vector<int>arr3={4,1,4,1};
    vector<int>arr4={2,3,4,9,2,10};
    vector<int>arr5={1,3,5,1,3,5,1};
    vector<int>arr6={-5,-2,0,0,3,9,-2,-5,4};
    vector<vector<int>>arr={
        {12, 13, 18, 24, 32, 41, 50, 52, 53, 61},
        {18, 19, 21, 29, 37, 50, 51, 56, 58, 65},
        {25, 33, 38, 48, 49, 55, 56, 64, 71, 72},
        {28, 36, 44, 55, 62, 72, 74, 78, 79, 82},
        {38, 45, 53, 57, 71, 73, 79, 84, 90, 96},
        {39, 50, 59, 62, 74, 81, 83, 94, 97, 98},
        {42, 60, 69, 71, 82, 87, 89, 96, 103, 109},
        {45, 65, 78, 86, 93, 94, 102, 106, 107, 112},
        {47, 70, 79, 88, 103, 108, 109, 110, 120, 123},
        {52, 78, 83, 95, 110, 119, 128, 132, 141, 143},
        {60, 82, 91, 101, 117, 121, 135, 138, 149, 150},
        {62, 89, 97, 102, 123, 133, 143, 151, 158, 164},
        {63, 93, 104, 110, 125, 138, 147, 154, 161, 170},
        {70, 98, 105, 111, 128, 139, 151, 160, 162, 175},
        {76, 100, 107, 113, 130, 146, 159, 163, 171, 182},
        {86, 109, 110, 120, 133, 147, 166, 174, 180, 184},
        {95, 117, 124, 133, 137, 150, 172, 175, 187, 196},
        {105, 125, 135, 143, 152, 160, 181, 187, 192, 200},
        {112, 126, 137, 152, 153, 161, 190, 198, 203, 204},
        {118, 130, 142, 157, 165, 168, 196, 201, 208, 211},
        {121, 131, 152, 164, 175, 183, 203, 205, 213, 214},
        {127, 136, 158, 169, 181, 187, 208, 212, 223, 232},
        {131, 144, 159, 172, 183, 188, 213, 217, 224, 240},
        {136, 154, 161, 178, 189, 197, 223, 228, 232, 244},
        {137, 157, 162, 186, 195, 201, 229, 233, 239, 246},
        {144, 166, 172, 193, 201, 208, 233, 239, 249, 251},
        {147, 170, 179, 199, 204, 217, 240, 241, 256, 262},
        {154, 174, 183, 202, 206, 224, 250, 259, 268, 273},
        {155, 181, 191, 206, 207, 226, 258, 266, 269, 281},
        {160, 190, 198, 207, 212, 229, 261, 275, 283, 289},
        {168, 191, 199, 216, 218, 231, 264, 283, 288, 293}
    };
    pair<int,int>p=searchInSortedMatrix(arr,76);
    cout<<p.first<<" "<<p.second<<" ";
    // M5frequencyOfEachElementLimitedRange(arr2);
    return 0;
}