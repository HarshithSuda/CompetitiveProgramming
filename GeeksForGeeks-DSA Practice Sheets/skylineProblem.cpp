// A divide and conquer based C++
// program to find skyline of given buildings
#include <bits/stdc++.h>
using namespace std;
void PrintVectorOfVector(vector<vector<int>>v){
    for(int i=0;i<v.size();i++){
        vector<int>temp=v[0];
        for(int j=0;j<temp.size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}
// A structure for building
struct Building {
    // x coordinate of left side
    int left;

    // height
    int ht;

    // x coordinate of right side
    int right;
};

// A strip in skyline
class Strip {
    // x coordinate of left side
    int left;

    // height
    int ht;

public:
    Strip(int l = 0, int h = 0)
    {
        left = l;
        ht = h;
    }
    friend class SkyLine;
};

// Skyline: To represent Output(An array of strips)
class SkyLine {
    // Array of strips
    Strip* arr;

    // Capacity of strip array
    int capacity;

    // Actual number of strips in array
    int n;

public:
    ~SkyLine() { delete[] arr; }
    int count() { return n; }

    // A function to merge another skyline
    // to this skyline
    SkyLine* Merge(SkyLine* other);

    // Constructor
    SkyLine(int cap)
    {
        capacity = cap;
        arr = new Strip[cap];
        n = 0;
    }

    // Function to add a strip 'st' to array
    void append(Strip* st)
    {
        // Check for redundant strip, a strip is
        // redundant if it has same height or left as
        // previous
        if (n > 0 && arr[n - 1].ht == st->ht)
            return;
        if (n > 0 && arr[n - 1].left == st->left) {
            arr[n - 1].ht = max(arr[n - 1].ht, st->ht);
            return;
        }

        arr[n] = *st;
        n++;
    }

    // A utility function to print all strips of
    // skyline
    void print()
    {
        for (int i = 0; i < n; i++) {
            cout << " (" << arr[i].left << ", " << arr[i].ht
                 << "), ";
        }
    }
};

// This function returns skyline for a
// given array of buildings arr[l..h].
// This function is similar to mergeSort().
SkyLine* findSkyline(Building arr[], int l, int h)
{
    if (l == h) {
        SkyLine* res = new SkyLine(2);
        res->append(new Strip(arr[l].left, arr[l].ht));
        res->append(new Strip(arr[l].right, 0));
        return res;
    }

    int mid = (l + h) / 2;

    // Recur for left and right halves
    // and merge the two results
    SkyLine* sl = findSkyline(arr, l, mid);
    SkyLine* sr = findSkyline(arr, mid + 1, h);
    SkyLine* res = sl->Merge(sr);

    // To avoid memory leak
    delete sl;
    delete sr;

    // Return merged skyline
    return res;
}

// Similar to merge() in MergeSort
// This function merges another skyline
// 'other' to the skyline for which it is called.
// The function returns pointer to the
// resultant skyline
SkyLine* SkyLine::Merge(SkyLine* other)
{
    // Create a resultant skyline with
    // capacity as sum of two skylines
    SkyLine* res = new SkyLine(this->n + other->n);

    // To store current heights of two skylines
    int h1 = 0, h2 = 0;

    // Indexes of strips in two skylines
    int i = 0, j = 0;
    while (i < this->n && j < other->n) {
        // Compare x coordinates of left sides of two
        // skylines and put the smaller one in result
        if (this->arr[i].left < other->arr[j].left) {
            int x1 = this->arr[i].left;
            h1 = this->arr[i].ht;

            // Choose height as max of two heights
            int maxh = max(h1, h2);

            res->append(new Strip(x1, maxh));
            i++;
        }
        else {
            int x2 = other->arr[j].left;
            h2 = other->arr[j].ht;
            int maxh = max(h1, h2);
            res->append(new Strip(x2, maxh));
            j++;
        }
    }

    // If there are strips left in this
    // skyline or other skyline
    while (i < this->n) {
        res->append(&arr[i]);
        i++;
    }
    while (j < other->n) {
        res->append(&other->arr[j]);
        j++;
    }
    return res;
}
void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void RedundancyCheckAndAdd(vector<vector<int>>&res,int x,int h){
    // cout<<"is res empty here?"<<res.empty()<<endl;
    // PrintVectorOfVector(res);
    if(x==1 && h==-1){
        return;
    }
    if(res.empty()){
        res.push_back({x,h});
        // PrintVectorOfVector(res);
        // cout<<"hello3"<<endl;
        return;
    }
    
    else if(res.back()[0]==x){ //if the skyline has current
        res.back()[1]=max(res.back()[1],h);
        return;
    }
    else if(res.back()[1]==h){
        return;
    }
    res.push_back({x,h});
    return;
}
vector<vector<int>> mergeForSkyline(vector<vector<int>>a1,vector<vector<int>>a2){
    int h1=0,h2=0,maxhh=0; //maintenance of heights of the two different skylines to be merged
    int i=0,j=0;
    vector<vector<int>>res;
    while(i<a1.size() && j<a2.size()){
        if(a1[i][0]<a2[j][0]){
            int x1=a1[i][0];
            h1=a1[i][1];
            maxhh=max(h1,h2);
            RedundancyCheckAndAdd(res,x1,maxhh);
            i++;
        }
        else{
            int x2=a2[j][0];
            h2=a2[j][1];
            maxhh=max(h1,h2);
            RedundancyCheckAndAdd(res,x2,maxhh);
            j++;
        }
    }
    while(i<a1.size()){
        RedundancyCheckAndAdd(res,a1[i][0],a1[i][1]);
        i++;
    }
    while(j<a2.size()){
        RedundancyCheckAndAdd(res,a2[j][0],a2[j][1]);
        j++;
    }
    return res;

}
vector<vector<int>> calcSkyline(vector<vector<int>>arr,int l,int h){
    //arr={{left1,height1,right1},{left2,height2,right2}};
    //l and h indicate the low and high in arrays
    if(l==h){
        vector<vector<int>>res; // only 1 builing exists and hence 2 skylines exist for it
        RedundancyCheckAndAdd(res,arr[l][0],arr[l][2]);
        RedundancyCheckAndAdd(res,arr[l][1],0);
        return res;
    }
    if(l<h){
        int mid=l+(h-l)/2;
        vector<vector<int>>temp;
        vector<vector<int>>SkylineLeft=calcSkyline(arr,l,mid);
        cout<<"printing left";
        PrintVectorOfVector(SkylineLeft);
        vector<vector<int>>SkylineRight=calcSkyline(arr,mid+1,h);

        cout<<"printing right";
        PrintVectorOfVector(SkylineRight);
        vector<vector<int>>res=mergeForSkyline(SkylineLeft,SkylineRight);
        cout<<"print after merging"<<endl;
        PrintVectorOfVector(res);
        return res;
    }
    // return {{-1,-1}};
}

//skyline is of format -->{(left1,height1),(left2,height2)}
//NEW SOLUTION
class Solution {
public:

vector<vector<int>> mergeForSkyline(vector<vector<int>>a1,vector<vector<int>>a2){
    int h1=0,h2=0,maxhh=0; //maintenance of heights of the two different skylines to be merged
    int i=0,j=0;
    int left=0,right=0;
    vector<vector<int>>res;
    int curr=0;
    while(i<a1.size() && j<a2.size()){
        if(a1[i][0]<a2[j][0]){
            curr=a1[i][0];
            h1=a1[i++][1];
            
        }
        else if(a1[i][0]>a2[j][0]){
            curr=a2[j][0];
            h2=a2[j++][1];
            
        }
        else{
            curr=a1[i][0];
            h1=a1[i++][1];
            h2=a2[j++][1];
            
        }
        maxhh=max(h1,h2);
        if(res.empty() || maxhh!=res.back()[1]){
            res.push_back({curr,maxhh});
        }
    }
    while(i<a1.size()){
        res.push_back(a1[i]);
        i++;
    }
    while(j<a2.size()){
        res.push_back(a2[j]);
        j++;
    }
    return res;

}
vector<vector<int>> calcSkyline(vector<vector<int>>arr,int l,int h){
    //arr={{left1,height1,right1},{left2,height2,right2}};
    //l and h indicate the low and high in arrays
    if(l==h){
        return{{arr[l][0],arr[l][2]},{arr[l][1],0}};// only 1 builing exists and hence 2 skylines exist for it

    }
    int mid=l+(h-l)/2;
    vector<vector<int>>SkylineLeft=calcSkyline(arr,l,mid);
    vector<vector<int>>SkylineRight=calcSkyline(arr,mid+1,h);
    return mergeForSkyline(SkylineLeft,SkylineRight);
    
}
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        return calcSkyline(arr,0,arr.size()-1);
    }
};

// Driver Function
int main()
{
    vector<vector<int>>arr= [[1,2,1],[1,2,2],[1,2,3]];
    set<vector<int>>ans(arr.begin(),arr.end());
    for(auto x : ans){
        printVector(x);
    }
    vector<vector<int>>res(ans.begin(),ans.end());
    PrintVectorOfVector(res);
    int n = sizeof(arr) / sizeof(arr[0]);
    // vector<vector<int>>ans=calcSkyline(arr,0,arr.size()-1);
    // PrintVectorOfVector(ans);
    // Find skyline for given buildings
    // and print the skyline
    // SkyLine* ptr = findSkyline(arr, 0, n - 1);
    // cout << " Skyline for given buildings is \n";
    // ptr->print();
    return 0;
}