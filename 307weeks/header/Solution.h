// #ifndef SOLUTION_H
// #define SOLUTION_H
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience);
        string largestPalindromic(string num);
        int amountOfTime(TreeNode* root, int start);
};

// #endif