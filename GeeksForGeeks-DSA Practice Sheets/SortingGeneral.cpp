#include<bits/stdc++.h>
using namespace std;
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


int LomutoPartition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
int randPartition(vector<int>&arr,int low,int high){
    int rand_pivot=rand()%(high-low+1);
    swap(arr[low+rand_pivot],arr[high]);
    return LomutoPartition(arr,low,high);
}
void LomutoquickSort(vector<int>&arr,int low,int high){
    if(low<high){
        int p=randPartition(arr,low,high);
        LomutoquickSort(arr,low,p-1);
        LomutoquickSort(arr,p+1,high);
    }
    return;
}
//FINDING KTH SMALLEST ELEMENT IN AN ARRAY
int HeapMethod(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>>h;
    for(auto x:arr){
        h.push(x);
    }
    while(k>1){
        h.pop();
        k--;
    }
    return h.top();
}
int M1QuickSelect(vector<int>&arr,int k,int low,int high){
    if(low==high){
        return arr[low];
    }
    int p=LomutoPartition(arr,low,high);
    if(k==p-low+1){
        return arr[p];
    }
    else if(k<p-low+1){
        return M1QuickSelect(arr,k,low,p-1);
    }
    else{
        return M1QuickSelect(arr,k-(p-low+1),p+1,high);
    }
}
int M2QuickSelect(vector<int>&arr,int k){
    int pivot=arr[rand()%arr.size()];
    vector<int>left,right,mid;
    for(auto x:arr){
        if(x<pivot){
            left.push_back(x);
        }
        else if(x==pivot){
            mid.push_back(x);
        }
        else{
            right.push_back(x);
        }
    }
    if(k<=left.size()){ //kth smallest is in left half <pivot
        return M2QuickSelect(left,k);
    }//kth smallest is in right half >pivot
    else if(k>left.size()+mid.size()){
        return M2QuickSelect(right,k-left.size()-mid.size());
    }
    return pivot; //its in the mid portion and all the elements in mid are equal to pivot
}
vector<int> countingsortForNumbers(vector<int>arr){ //->only good when max_element is of size <=nlogn 
    int maxx=*max_element(arr.begin(),arr.end());
    vector<int>count(maxx+1,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    for(int i=1;i<count.size();i++){
        count[i]+=count[i-1];
    }
    vector<int>output(arr.size());
    for(int i=arr.size()-1;i>=0;i--){ //traversing from reverse to ensure stability
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    return output;
}
string countingSortForStrings(string s){
    vector<int>ans(26,0);
    for(auto x : s){
        ans[x-'a']++;
    }
    string q="";
    for(int i=0;i<ans.size();i++){
        if(ans[i]){
            string temp(ans[i],97+i);
            q+=temp;
        }
    }
    return q;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    vector<int>arr={3,2,1,5,6,4};
    cout<<HeapMethod(arr,2)<<endl;

    return 0;
}