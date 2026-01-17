#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root){
    if(!root) return;
    cout << root -> val << ' ';
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root -> left);
    cout << root -> val << ' ';
    inorder(root -> right);
}

void postorder(TreeNode* root){
    if(!root) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> val << ' ';
}

TreeNode* buildTree(vector<int>& nums){
    if(nums.size() == 0 || nums[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    const int n = nums.size();
    while(q.size() > 0 && i < n){
        TreeNode* curr = q.front();
        q.pop();

        if(i < n && nums[i] != -1){
            curr -> left = new TreeNode(nums[i]);
            q.push(curr -> left);
        }
        i++;
        if(i < n && nums[i] != -1){
            curr -> right = new TreeNode(nums[i]);
            q.push(curr -> right);
        }
        i++;
    }
    return root;
    
}

int main(){
    vector<int> nums = {1, 2, 3, 4, -1, 6, 7};
    //    1
    // 2     3
    //4 null   6 7
    TreeNode* root = buildTree(nums);
    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    return 0;
}