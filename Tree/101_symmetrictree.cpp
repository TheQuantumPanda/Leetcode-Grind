/*I understood the question still got a little better at writing
the code for implementation for tree*/
/*These are just conditions*/
/*
    bool mirror(TreeNode* left, TreeNode* right)
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        if(left->val != right->val)
            return false;
        return mirror(left->left, right->right)
            && mirror(left->right, right->left);
*/

/*Here the gpt fixed code it also took consideration if root is null itself i didn't consider that*/

class Solution {
public:

    bool mirror(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr)
            return true;

        if(left == nullptr || right == nullptr)
            return false;

        if(left->val != right->val)
            return false;

        return mirror(left->left, right->right)
            && mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root == nullptr)
            return true;

        return mirror(root->left, root->right);
    }
};
