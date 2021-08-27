#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
void dfs(vector<int> temp, vector<vector<int>> &ans, TreeNode *node, int targetSum)
{
    if (node == nullptr)
        return;
    if (node->left == nullptr && node->right == nullptr && targetSum == 0)
    {
        ans.push_back(temp);
    }
    temp.push_back(node->val);
    dfs(temp, ans, node->left, targetSum - node->val);
    dfs(temp, ans, node->right, targetSum - node->val);
    temp.pop_back();
}
int main()
{
    TreeNode *root = new TreeNode;
    root->val=-2;
    root->left=nullptr;
    root->right->val=-3;
    int targetSum=-5;
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(temp, ans, root, targetSum);
    return 0;
}