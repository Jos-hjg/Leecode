#include <iostream>
#include <vector>
#include "./header/Solution.h"

using namespace std;


int main(){
    Solution ss;
    TreeNode *b = new TreeNode(1);
    b->left = new TreeNode(2, new TreeNode(4, new TreeNode(8), new TreeNode(9)), new TreeNode(6));
    b->right = new TreeNode(3, new TreeNode(5), new TreeNode(7));
    // int en[5] = {1,6};
    // int exp[5] = {3,5};
    // vector<int> energy(en, en+5);
    // vector<int> experience(exp, exp+5);
    // cout<<ss.minNumberOfHours(2, 4, energy, experience)<<endl;
    // cout<<ss.largestPalindromic("00000")<<endl;
    // cout<<ss.amountOfTime(b, 8)<<endl;
    vector<int> ans;
    cout<<ss.dfs(b, 0)<<endl;
    return 0;
}