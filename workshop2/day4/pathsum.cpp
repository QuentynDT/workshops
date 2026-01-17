//Given a tree and a target, find a root to leaf path 
// such that the sum = target


#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
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
    vector<int> nums = {1, 2, 3, 8, -1, 6, 7};
    //    1
    // 2     3
    //8 null   6 7
    //9
    TreeNode* root = buildTree(nums);
    vector<vector<int>> ans;
    int target = 11;
    vector<int> path;

    auto dfs = [&](this auto self, TreeNode* root, int target) -> void {
        if(!root) return;
        path.push_back(root->val);
        target -= root->val;
        if(!root->left && !root->right && target == 0){
            ans.push_back(path);
        } else {
            self(root->left, target);
            self(root->right, target);
        }
        target += root->val;
        path.pop_back();
    };

    dfs(root, target);
    for(auto& v : ans){
        for(auto& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}