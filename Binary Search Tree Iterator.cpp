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
class BSTIterator {
public:
    
    vector<int> vec;
    void getAll( TreeNode* root ){
        if( root == NULL ) return;
        getAll( root->left );
        vec.push_back( root->val );
        getAll( root->right );
    }
    
    BSTIterator(TreeNode* root) {
        getAll( root );
    }
    
    int pos = 0;
    int next() {
        return vec[pos++];
    }
    
    bool hasNext() {
        return pos < vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
