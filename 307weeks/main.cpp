#include <iostream>
#include <vector>
#include "./header/Solution.h"

using namespace std;


int main(){
    Solution ss;
    TreeNode *b;
    b = &TreeNode(1, &TreeNode(2), &TreeNode(3));
    // int en[5] = {1,6};
    // int exp[5] = {3,5};
    // vector<int> energy(en, en+5);
    // vector<int> experience(exp, exp+5);
    // cout<<ss.minNumberOfHours(2, 4, energy, experience)<<endl;
    // cout<<ss.largestPalindromic("00000")<<endl;
    ss.amountOfTime(b, 2);
    return 0;
}