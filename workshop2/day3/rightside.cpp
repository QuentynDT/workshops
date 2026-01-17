//Print the right side view of a tree
//    1
// 2     3
//4 null   6 7


//1 3 7

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
vector<int> rightSide(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(i == 0) ans.push_back(curr->val);

            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    //    1
    // 2     3
    //4 null   6 7
    TreeNode* root = buildTree(nums);
    vector<int> ans = rightSide(root);
    for(int& x : ans){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}