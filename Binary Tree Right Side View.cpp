/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> ans;
public:
    void reCur(TreeNode* root,int level){
        if(root == NULL) return;
        
        if( level == ans.size() ){
            ans.push_back(root->val);
        }
        reCur(root->right, level+1);
        reCur(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        reCur(root,0);
        
        return ans;
    }
};
