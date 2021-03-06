/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /* 递归 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;
        
        if(root->left != nullptr)
        {
            const vector<int> &left = inorderTraversal(root->left);
            res = std::move(left);
        }
        res.push_back(root->val);
        if(root->right != nullptr)
        {
            const vector<int> &right = inorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
        }
   
        return res;
    }
};

/* 栈 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;

        stack<TreeNode *> s;
        TreeNode *node = root;
        while(node != nullptr || !s.empty())
        {
            while(node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};