#include<bits/stdc++.h>
using namespace std;
void printVector(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
int kthLargestSum(vector<int>arr, int k){
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int> >p;
    vector<int>ans(n+1,0);
    for(int i=0;i<n;i++){}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<searchInSortedRotatedArray(arr1,3)<<endl;
    // cout<<searchInSortedRotatedArray(arr2,6)<<endl;
    // cout<<searchInSortedRotatedArray(arr3,100)<<endl;
    vector<int>arr1={20, -5, -1};
    vector<int>arr2={10, -10, 20, -40};
    vector<int>arr3={3, 2, 1};
    vector<int>arr4={2, 6, 4, 1};
    // vector<int>ans;
    // ans=productExceptSelf(arr1);
    // printVector(ans);
    // ans=productExceptSelf(arr2);
    // printVector(ans);
    // ans=productExceptSelf(arr3);
    // printVector(ans);
    cout<<kthLargestSum(arr1,3)<<endl;
    cout<<kthLargestSum(arr2,4)<<endl;
    cout<<kthLargestSum(arr3,2)<<endl;
    cout<<kthLargestSum(arr4,3)<<endl;
    
    return 0;

}