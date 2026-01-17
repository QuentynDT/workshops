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

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> curr;
        //q size is 4
        for(int sz = q.size(); sz > 0; sz--){
            root = q.front();
            q.pop();
            //q size = 3
            if(!root) continue;
            curr.push_back(root->val);
            q.push(root->left);
            //q size = 4
            q.push(root->right);
            //q size = 5
        }
        if(!curr.empty()) ans.push_back(curr);
    }
    return ans;

}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    //    1
    // 2     3
    //4 null   6 7
    TreeNode* root = buildTree(nums);
    vector<vector<int>> ans = levelOrder(root);
    for(vector<int>& v : ans){
        for(int& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}