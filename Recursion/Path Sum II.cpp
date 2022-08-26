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
    vector<vector<int>> ans;
public:
    
    void dfs(TreeNode* root, int targetSum,int sum,vector<int>& vec){
        if(!root) return;
        
        sum += root->val;
        vec.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum == targetSum)
            {
                ans.push_back(vec);
            }
        }
        
        dfs(root->left,targetSum,sum,vec);
        dfs(root->right,targetSum,sum,vec);
        vec.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return ans;
        int sum = 0;
        vector<int> vec;
        dfs(root,targetSum,sum,vec);
        
        return ans;
    }
};
