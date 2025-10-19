#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

vector<int> inorderTraversal(TreeNode* root) {
    if(!root){
        return {};
    }
    vector<int>ans;
    // unordered_set<int>s;
    stack<TreeNode*>st;
    // st.push(root);
    TreeNode* curr=root;
    while(!st.empty() ||curr){
        
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        ans.push_back(curr->val);
        
        curr=curr->right;
        
        }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}