/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * inorder_traversal(struct TreeNode * root, struct TreeNode ** new_root)
{
    if(root)
    {
        root->left = inorder_traversal(root->left, new_root);

        //Attach the current Node to the answer
        printf("parent_root : %p ", *new_root);
        (*new_root)->right = root; 
        *new_root = root;

        inorder_traversal(root->right, new_root);

        return NULL;
    }
    return NULL;
}

struct TreeNode* increasingBST(struct TreeNode* root) 
{
    //Create a dummy node
    struct TreeNode * new_root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_root->val = INT_MIN;    //Put some random value in dummy node
    new_root->left = NULL;
    new_root->right = NULL;

    struct TreeNode * ptr = new_root;
    struct TreeNode * return_root = new_root;

    inorder_traversal(root, &ptr);    
    return return_root->right;
}    
