const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {

    private:

    int ans = 0;
public:

    void Inorder(TreeNode* root, int low, int high){

        if(root == nullptr){return;}

        Inorder(root->left, low, high);
        
        if(root->val > high){return;} // эта строка учитывает информацию о том, что дано BST -- при inorder обходе значения в узлах образуют возрастающую последовательность
        if(low<= root->val && root->val <= high){ans+= root->val;}
        
        Inorder(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        
        Inorder(root, low, high);
        return ans;
    }
};
