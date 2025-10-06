#include<bits/stdc++.h>
using namespace std;
void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
struct Node{
    int key;
    Node *left,*right;
    Node (int d){
        key=d;
        left=right=NULL;
    }
};
void printPreorder(Node *root){ //NLR
    if(!root){
        return;
    }
    cout<<root->key<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printPreorderStack(Node *root){
    stack<Node*>s;
    Node *curr=root;
    s.push(root);
    while(curr && !s.empty()){
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
        cout<<curr->key<<" ";
        curr=s.top();
        s.pop();
    }
}
void printInorderRecursion(Node *root){
    if(!root){
        return;
    }
    printInorderRecursion(root->left);
    cout<<root->key<<" ";
    printInorderRecursion(root->right);
}
void printInorderStack(Node *root){
    stack<Node*>s;
    s.push(root);
    Node *curr=root->left;
    while(curr || !s.empty()){
        while(curr){
            s.push(curr);
            curr=curr->left;

        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }

}
void MorrisTraversalInorder(Node *root){

}
void printPostorder(Node *root){
    if(!root){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->key<<" ";
}
vector<int> printPostOrderUsingTwoStack(Node *root){
    if(!root){
        return {};
    }
    vector<int>ans;
    stack<Node*>s1,s2;
    //s1->storing temporarily  (in NRL format)
    //s2->storing reverse postorder(such that while popping ->postorder)
    s1.push(root);
    while(!s1.empty()){
        Node *curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left){ //in NRL-->left should go first in stack(LIFO property)
            s1.push(curr->left);
        }
        if(curr->right){
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->key);
        s2.pop();
    }
    return ans;
}
vector<int> M1iterativePostorderTraversal(Node *root){
    vector<int>ans;
    if(!root){
        return {};
    }
    Node *curr=root;
    stack<Node*>s;
    while(curr || !s.empty()){
        while(curr){
            if(curr->right){
                s.push(curr->right);
            }
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        if(curr->right && !s.empty() && s.top()==curr->right){
            s.pop();//popping curr->right element
            s.push(curr);
            curr=curr->right;
        }
        else{
            ans.push_back(curr->key);
            curr=NULL;
        }
    }
    return ans;
}
vector<int> M2iterativePostorderTraversal(Node *root){
    if(!root){
        return {};
    }
    vector<int>ans;
    stack<Node*>s;
    s.push(root);
    Node *prev=NULL;
    Node *curr=root;
    while(!s.empty()){
        curr=s.top();
        if(!prev || prev->left==curr || prev->right==curr){
            if(curr->left){
                s.push(curr->left);
            }
            else if(curr->right){
                s.push(curr->right);
            }
            else{
                s.pop();
                ans.push_back(curr->key);
            }
        }
        else if(curr->left==prev){
            if(curr->right){
                s.push(curr->right);
            }
            else{
                s.pop();
                ans.push_back(curr->key);
            }
        }
        else if(curr->right==prev){
            s.pop();
            ans.push_back(curr->key);
        }
        prev=curr;
    }

    return ans;
}
void deleteATree(Node *root){
    if(!root){
        return;
    }
    deleteATree(root->left);
    deleteATree(root->right);
    cout<<"\n Deleting Node"<<root->key<<" ";
    delete(root);
}
void LevelOrderTraversal(Node *root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<temp->key<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return;
}
vector<vector<int>> levelOrderTraversalIterative(Node *root){
    if(!root){
        return {{}};
    }
    queue<Node*>q;
    vector<vector<int>>res; //to store elements level by level
    q.push(root);
    int level=0;
    while(!q.empty()){
        int nodes_in_level=q.size();
        res.push_back({});
        for(int i=0;i<nodes_in_level;i++){
            Node *curr=q.front();
            q.pop();
            res[level].push_back(curr->key);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        level++;
    }
    return res;

}
//helper functions for Boundary Tree Traversal
void printLeftBoundary(Node *root){
    if(!root || (!(root->left) && !(root->right))){ //stops at leaf node (as we will print leaf nodes with different function)
        return;
    }
    cout<<root->key<<" ";
    printLeftBoundary(root->left);
}
void printLeafNode(Node *root){
    if(!root){
        return;
    }
    if(!(root->left) && !(root->right)){
        cout<<root->key<<" ";
    }
    printLeafNode(root->left);
    printLeafNode(root->right);
}
void printRightBoundary(Node *root){
    if(!root || (!(root->left) && !(root->right))){
        return;
    }
    printRightBoundary(root->right);
    cout<<root->key<<" ";
}
void BoundaryTreeTraversal(Node *root){
    if(root){
        cout<<root->key<<" ";
        printLeftBoundary(root->left);
        printLeafNode(root->left);
        printLeafNode(root->right);
        printRightBoundary(root->right);
    }
}
//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
//IT WORKS -GOOD JOB :)
//GFG AND LEETCODE QUESTION SOLVED

void printLeftBoundaryGFG(Node *root,vector<int>&globalVectorForBoundaryTraversal){
    if(!root || (!(root->left) && !(root->right))){ //stops at leaf node (as we will print leaf nodes with different function)
        return;
    }
    globalVectorForBoundaryTraversal.push_back(root->key);
    if(root->left){
        
        printLeftBoundaryGFG(root->left,globalVectorForBoundaryTraversal);
    }
    else{
        printLeftBoundaryGFG(root->right,globalVectorForBoundaryTraversal);
    }
}
void printLeafNodeGFG(Node *root,vector<int>&globalVectorForBoundaryTraversal){
    if(!root){
        return;
    }
    if(!(root->left) && !(root->right)){
        globalVectorForBoundaryTraversal.push_back(root->key);
    }
    printLeafNodeGFG(root->left,globalVectorForBoundaryTraversal);
    printLeafNodeGFG(root->right,globalVectorForBoundaryTraversal);
}
void printRightBoundaryGFG(Node *root,vector<int>&globalVectorForBoundaryTraversal){
    if(!root || (!(root->left) && !(root->right))){
        return;
    }
    if(root->right){
        printRightBoundaryGFG(root->right,globalVectorForBoundaryTraversal);
    }
    else{
        printRightBoundaryGFG(root->left,globalVectorForBoundaryTraversal);
    }
    globalVectorForBoundaryTraversal.push_back(root->key);
}
vector<int> BoundaryTreeTraversalGFG(Node *root){
    vector<int>globalVectorForBoundaryTraversal;
    if(root){
        globalVectorForBoundaryTraversal.push_back(root->key);
        printLeftBoundaryGFG(root->left,globalVectorForBoundaryTraversal);
        printLeafNodeGFG(root->left,globalVectorForBoundaryTraversal);
        printLeafNodeGFG(root->right,globalVectorForBoundaryTraversal);
        printRightBoundaryGFG(root->right,globalVectorForBoundaryTraversal);
    }
    return globalVectorForBoundaryTraversal;
}
void BFSUsingQueue(Node *root){
    queue<Node*>q;
    if(!root){
        return;
    }
    Node *curr=root;
    q.push(root);
    while(!q.empty()){ //while(curr || !q.empty()) -->curr not required because curr will never become NULL and while loop will not terminate
                        //get segfault at curr->key(NULL->key)
        curr=q.front();
        cout<<"here "<<curr->key<<endl;
        q.pop();

        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    return;
}
vector<vector<int>>LOTUsingQueueVectorOfVector(Node *root){ //i got it in the first try (OMG)
    vector<vector<int>>res;
    if(!root){
        return res;
    }
    queue<Node*>q;
    q.push(root);
    res={{}};
    res[0].push_back(root->key);
    int level=0;
    while(!q.empty()){
        res.push_back({});
        for(int i=0;i<res[level].size();i++){
            Node *curr=q.front();
            if(curr->left){
                q.push(curr->left);
                res[level+1].push_back(curr->left->key);
            }
            if(curr->right){
                q.push(curr->right);
                res[level+1].push_back(curr->right->key);
            }
            q.pop();
        }
        level++;
    }
    return res;
}
void LOTHelperFunction(Node *root,int level,vector<vector<int>>&res){
    if(!root){
        return;
    }
    if(res.size()<=level){ //we need to create another vector to push_back next level elements
        res.push_back({});
    }
    res[level].push_back(root->key);
    LOTHelperFunction(root->left,level+1,res);
    LOTHelperFunction(root->right,level+1,res);
}
vector<vector<int>> LOTUsingStackVectorOfVector(Node *root){
    vector<vector<int>>res;
    LOTHelperFunction(root,0,res);
    return res;
}
int M1heightofTree(Node* root,int height){ //recursion
    if(!root){
        return height-1;
    }
    int maxx=max(M1heightofTree(root->left,height+1),M1heightofTree(root->right,height+1));
    return maxx;
}
int M2heightofTree(Node *root){
    if(!root){
        return -1;
    }
    queue<Node*>q;
    Node *curr=root;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int nodes_in_level=q.size();
        for(int i=0;i<nodes_in_level;i++){
            Node *curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        level++;
    }
    return level-1;//taking root as height 0
}
int M3heightofTree(Node *root){
    if(!root){
        return 0;
    }
    int lheight=M3heightofTree(root->left);
    int rheight=M3heightofTree(root->right);
    return max(lheight,rheight)+1;
}
int M4heightOfTree(Node *root){
    if(!root){
        return 0;
    }
    queue<Node*>q;
    q.push(root);
    int height=0;
    q.push(NULL); //to segregate level by level
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        if(!curr){ //if we came here -->one level of nodes are done
            height++;
            if(!q.empty()){ //NULL for the next layer
                q.push(NULL);
            }
        }
        else{
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return height;
}

//https://www.geeksforgeeks.org/height-and-depth-of-a-node-in-a-binary-tree/

//METHOD-1
int M1depthofNode(Node*root,int k,int height){
    if(!root){
        return -1;
    }
    if(root->key==k){
        return (height);
    }
    int lheight=M1depthofNode(root->left,k,height+1);
    if(lheight!=-1){
        return lheight;
    }
    return M1depthofNode(root->right,k,height+1);
}
int M1heightofNode(Node *root,int k){
    int depthOfTree=M4heightOfTree(root);
    if(M1depthofNode(root,k,0)==-1){
        return -1;
    }
    return (depthOfTree-M1depthofNode(root,k,0)-1);
}
pair<int,int> M1depthAndHeightOfNode(Node *root,int k){
    pair<int,int>p;
    p.first=M1heightofNode(root,k);
    p.second=M1depthofNode(root,k,0);
    return p;
}
//METHOD-2
int M2findDepth(Node *root,int k){
    if(!root){
        return -1;
    }
    int dist=-1;
    // dist =m2(root->left ) and dist=m2(root->right) will be greater than or equal to 0 when k is found
    if(root->key==k || (dist=M2findDepth(root->left,k))>=0|| (dist=M2findDepth(root->right,k))>=0){
        return dist+1;
    }
    return dist;
}
int M2findHeight(Node *root,int k,int &height){ //helper function (finds total height(return value) 
//and height of the node is stored in output variable "height"
    if(!root){
        return -1;
    }
    int lheight=M2findHeight(root->left,k,height);
    int rheight=M2findHeight(root->right,k,height);
    int ans=max(lheight,rheight)+1;
    if(root->key==k){
        height=ans;
    }
    return ans;
}
int M2findHeightOfNode(Node *root,int k){
    int height=-1; //
    int HeightOfTree=M2findHeight(root,k,height);
    return height;
}
//https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
int M1getLevelOfaNode(Node *root,int target,int height){
    if(!root){
        return -1;
    }
    if(root->key==target){
        return height;
    }
    return max(M1getLevelOfaNode(root->left,target,height+1),M1getLevelOfaNode(root->right,target,height+1));
}
int M2getLevelOfaNode(Node *root,int target){
    if(!root){
        return 0;
    }
    if(root->key==target){
        return 1;
    }
    Node *curr=root;
    queue<Node*>q;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int nodes_of_level=q.size();
        for(int i=0;i<nodes_of_level;i++){
            Node *curr=q.front();
            q.pop();
            if(curr->key==target){
                return level;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        level++;
    }
    return 0;
}
//https://www.geeksforgeeks.org/search-a-node-in-binary-tree/
bool ifNodeExists(Node *root,int k){
    if(!root){
        return false;
    }
    if(root->key==k){
        return true;
    }
    if(ifNodeExists(root->left,k)){
        return true;
    }
    return ifNodeExists(root->right,k);
}
//https://www.geeksforgeeks.org/find-the-parent-of-a-node-in-the-given-binary-tree/
int M1returnParentNode(Node *root,int k){
    if(!root ||(!root->left && !root->right)){
        return -1;
    }
    if(root->key==k){
        return -1;
    }
    Node* curr=root;
    int left=-1,right=-1;
    if(curr->left){
        if(curr->left->key==k){
            left=curr->key;
            return left;
        }
        else{
            left=M1returnParentNode(root->left,k);
            if(left!=-1){
                return left;
            }
        }
    }
    if(curr->right){
        if(curr->right->key==k){
            right=curr->key;
            return right;
        }
        else{
            right=M1returnParentNode(root->right,k);
            if(right!=-1){
                return right;
            }
        }
    }
    return max(left,right);
}
int M2returnParentNode(Node *root,int k,int parent){ //intialise parent to -1;
    if(!root){
        return -1;
    }
    if(root->key==k){
        return parent;
    }
    int leftsearch=M2returnParentNode(root->left,k,root->key);
    if(leftsearch!=-1){
        return leftsearch;
    }
    return M2returnParentNode(root->right,k,root->key);
}
//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
Node* insertionInaBinaryTree(Node *root,int k){
    Node *newnode=new Node(k);
    if(!root){
        return newnode;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        if(curr->left){
            q.push(curr->left);
        }
        else{
            curr->left=newnode;
            return root;
        }
        if(curr->right){
            q.push(curr->right);
        }
        else{
            curr->right=newnode;
            return root;
        }
    }
    return root;
}
//https://www.geeksforgeeks.org/deletion-binary-tree/
//THOUGHT PROCESS
//1.search for k(yes-->search for deepest node(rightmost leaf)-->replace k node with RML-->delete RML)
//2.k not found-->return root
//going iterative
void deleteDeepest(Node *root,Node *dNode){ //if we are calling this function -->it means we have found the node
    queue<Node*>q;
    q.push(root);
    Node *curr=NULL;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr==dNode){
            curr=NULL;
            free(dNode); 
            return;
        }
        if(curr->left){
            if(curr->left==dNode){
                curr->left=NULL;
                free(dNode);
                return;
            }
            q.push(curr->left);
        }
        if(curr->right){
            if(curr->right==dNode){
                curr->right=NULL;
                free(dNode);
                return;
            }
            q.push(curr->right);
        }
    }
    return;
}
Node* deletionOfNode(Node *root,int k){ //return root 
    if(!root){
        return NULL;
    }
    if(!(root->right) && !(root->left)){
        if(root->key==k){
            return NULL;
        }
        return root;
    }
    Node *kNode=NULL;
    queue<Node*>q;
    q.push(root);
    Node *curr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr->key==k){
            kNode=curr;
        }
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    if(!kNode){
        return root;
    }
    else{
        kNode->key=curr->key;
        deleteDeepest(root,curr);
        return root;
    }
    return root;
}
//https://www.geeksforgeeks.org/print-leaf-nodes-left-right-binary-tree/
void M1printLeafNodes(Node *root){ //using DFS
    if(!root){
        return;
    }
    if(!(root->left) &&!(root->right)){
        cout<<root->key<<" ";
        return;
    }
    if(root->left){
        M1printLeafNodes(root->left);
    }
    if(root->right){
        M1printLeafNodes(root->right);
    }
    return;
}
void M2printLeafNodes(Node *root){
    if(!root){
        return;
    }
    stack<Node*>s;
    s.push(root);
    Node *curr=root;
    while(!s.empty()){
        curr=s.top();
        s.pop();
        if(!(curr->left) && !(curr->right)){
            cout<<curr->key<<" ";
        }
        if(curr->right){ //right first because Stack-->LIFO
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
    cout<<"\n";
    return;
}
//https://www.geeksforgeeks.org/binary-tree-array-implementation/
//array-->0 to n-1
//parent -->p
//left child-->2*p+1
//right child-->2*p+2
void setRootInArrayImplementation(vector<int>&tree,int data){
    tree[0]=data;
    return;
}
void setLeftInArrayImplementation(vector<int>&tree,int data,int parent){
    if(tree[parent]==-1){
        cout<<"parent "<<parent<<"doesnt exist\n";
        return;
    }
    tree[parent*2+1]=data;
    return;
}
void setRightInArrayImplementation(vector<int>&tree,int data,int parent){
    if(tree[parent]==-1){
        cout<<"parent "<<parent<<"doesnt exist\n";
        return;
    }
    tree[parent*2+2]=data;
    return;
}
void printTreeInArrayImplementation(vector<int>&tree){
    for(int i=0;i<tree.size();i++){
        if(tree[i]==-1){
            cout<<"N ";
        }
        else{
            cout<<tree[i]<<" ";
        }
    }
    return;
}
///BINARY SEARCH TREE
//insertion in BST
Node  * insertionInBSTRecursive(Node *root,int data){
    if(!root){
        return new Node(data);
    }
    if(root->key==data){
        return root;
    }
    else if(root->key<data){
        root->right=insertionInBSTRecursive(root->right,data);
    }
    else{
        root->left=insertionInBSTRecursive(root->left,data);
    }
    return root;
}

Node * insertionInBSTIterative(Node *root,int data){
    if(!root){
        return new Node(data);
    }
    Node *parent=NULL;
    Node* curr=root;
    while(curr){
        if(curr->key==data){
            // cout<<"here1";
            return root;
        }
        else if(curr->key<data){
            // cout<<"here2";
            parent=curr;
            curr=curr->right;
        }
        else{
            // cout<<"here3";
            parent=curr;
            curr=curr->left;
        }
    }
    curr=new Node(data);
    if(parent->key<data){
        parent->right=curr;
    }
    else if(parent->key>data){
        parent->left=curr;
    }
    return root;
}
//SEARCHING IN BINARY TREE
Node* searchInBSTRecursive(Node *root,int data){
    if(!root){ //root is null or key not found
        return NULL;
    }
    if(root->key==data){
        return root;
    }
    else if(root->key<data){
        return searchInBSTRecursive(root->right,data);
    }
    else{
        return searchInBSTRecursive(root->left,data);
    }
}

Node* searchInBSTIterative(Node *root,int data){
    if(!root){
        return NULL;
    }
    Node *curr=root;
    while(curr){
        if(curr->key==data){
            return curr;
        }
        else if(curr->key<data){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    return NULL;
}
//Deletion in BST
// Node* MainFunction(Node* root,int data){
//     bool flag=searchInBSTRecursive(root,data);
//     if(!flag){
//         return root;
//     }
//     root=DeletionInBSTRecursive(root,data);
//     return root;
// }
Node * DeletionInBSTRecursive(Node* root,int data){
    if(!root){
        return NULL;
    }
    if(root->key<data){
        root->right=DeletionInBSTRecursive(root->right,data);
    }
    else if(root->key>data){
        root->left=DeletionInBSTRecursive(root->left,data);
    }
    
    else{ //key found
    Node *curr=root;
        if(!(curr->left)){
            Node *temp=curr->right;
            free(curr);
            return temp;
        }
        else if(!(curr->right)){
            Node *temp=curr->left;
            free(curr);
            return temp;
        }
        else{
            Node *rightmax=curr->left;
            while(rightmax && (rightmax->right)){  
                rightmax=rightmax->right;
            }
            curr->key=rightmax->key;
            curr->left=DeletionInBSTRecursive(curr->left,rightmax->key);
            return curr;
        }
    }
    return root;
}
Node* DeletionInBSTIterative(Node *root,int data){
    if(!root){
        return NULL;
    }
    Node *parent=NULL;
    Node *curr=root;
    while(curr && curr->key!=data){
        if(curr->key<data){
            parent=curr;
            curr=curr->right;
            continue;
        }
        else if(curr->key>data){
            parent=curr;
            curr=curr->left;
            continue;
        }
    }
    if(!curr){
        return root;
    }
    if(!(curr->right) && !(curr->left)){
        if(curr==root){
            return NULL;
        }
        free(curr);
        return root;
    }
    else if(!(curr->left)){
        if(curr->right){
            Node *temp=curr->right;
            if(parent==NULL){
                
            }
            if(parent->key>data){
                parent->left=temp;
            }
            else{
                parent->right=temp;
            }
            free(curr);
            return root;
        }
    }
    else if(!(curr->right)){
        if(curr->left){
                Node *temp=curr->left;
                if(parent->key>data){
                parent->left=temp;
            }
            else{
                parent->right=temp;
            }
            free(curr);
            return root;
        }
    }
    else{
        Node *parentRightMaxx=curr;
        Node *rightmaxx=curr->right;
        while(rightmaxx && rightmaxx->left){
            parentRightMaxx=rightmaxx;
            rightmaxx=rightmaxx->left;
        }
        curr->key=rightmaxx->key;
        if((rightmaxx->right)){ //rightmaxx wont have a left as we have already traversed till left
        //  when we dint traverse
            if(parentRightMaxx==curr){
                curr->key=rightmaxx->key;
                curr->right=NULL;
                free(rightmaxx);
                return root;
            }
            //when we traverse
            else{
                Node *temp=rightmaxx->right;
                parentRightMaxx->right=temp;
                parentRightMaxx->left=NULL;
                free(rightmaxx);
                return root;
            }
        }
        else{
            //if rightmax->right==NULL
            parentRightMaxx->left=NULL;
            free(rightmaxx);
            return root;
        }
    }
    return root;
}

//https://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/
    
Node * minimumElementInBSTRecursive(Node *root){
    if(!root){
        return NULL;
    }
    if(!(root->left)){
        return root;
    }
    Node *curr=minimumElementInBSTRecursive(root->left);
    return curr;
}

Node * minimumElementInBSTIterative(Node *root){
    if(!root){
        return NULL;
    }

    Node *curr=root;
    while(curr->left){
        curr=curr->left;
    }
    return curr;
}

//https://www.geeksforgeeks.org/floor-in-binary-search-tree-bst/
int floorInBSTIterative(Node *root,int x){
    if(!root){
        return -1;
    }
    int curr_floor=root->key;
    Node *curr=root;
    while(curr){
        if(curr->key==x){
            return x;
        }
        else if(curr->key<x){
            curr_floor=curr->key;
            curr=curr->right;
        }
        else{
            
            curr=curr->left;
            
        }
    }
    return curr_floor;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root= new Node(50);
    // root->left=new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);
    // vector<int>tree(7,-1);
    root=insertionInBSTIterative(root,30);
    root=insertionInBSTIterative(root,70);
    root=insertionInBSTIterative(root,20);
    root=insertionInBSTIterative(root,40);
    root=insertionInBSTIterative(root,60);
    root=insertionInBSTIterative(root,80);
    root=insertionInBSTIterative(root,55);
    root=insertionInBSTIterative(root,65);

    printInorderRecursion(root);
    cout<<endl;
    cout<<floorInBSTIterative(root,54)<<" ";
    // cout<<"\n";
    // Node *newRoot=DeletionInBSTRecursive(root,2);
    // printInorderRecursion(newRoot);
    // cout<<"\n";
    // newRoot=DeletionInBSTRecursive(root,5);
    // printInorderRecursion(newRoot);
    // cout<<"\n";
    // newRoot=DeletionInBSTRecursive(root,4);
    // printInorderRecursion(newRoot);
    // cout<<"\n";
    
    //printInorderRecursion(root);
    return 0;
}