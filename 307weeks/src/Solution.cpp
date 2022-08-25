#include <iostream>
#include <cmath>
#include "../header/Solution.h"

using namespace std;

int Solution::dfs(TreeNode* root, int level, int start)
{
    if(root == nullptr) return 0;
    if(root->val == start) depth = level;   //判断初始感染是否为当前节点
    int l = dfs(root->left, level + 1, start); //左子树高度
    bool inLeft = depth != -1;
    int r = dfs(root->right, level + 1, start);
    if(root->val == start) ans = max(ans, max(l, r));
    if(inLeft) ans = max(ans, depth - level + r);
    else ans = max(ans, depth - level + l);
    return max(l, r);
}

int Solution::amountOfTime(TreeNode* root, int start)
{
    dfs(root, 0, start);
    return ans;
}

// 你正在参加一场比赛，给你两个 正 整数 initialEnergy 和 initialExperience 分别表示你的初始精力和初始经验。
// 另给你两个下标从 0 开始的整数数组 energy 和 experience，长度均为 n 。
// 你将会 依次 对上 n 个对手。第 i 个对手的精力和经验分别用 energy[i] 和 experience[i] 表示。当你对上对手时，需要在经验和精力上都 严格 超过对手才能击败他们，然后在可能的情况下继续对上下一个对手。
// 击败第 i 个对手会使你的经验 增加 experience[i]，但会将你的精力 减少  energy[i] 。
// 在开始比赛前，你可以训练几个小时。每训练一个小时，你可以选择将增加经验增加 1 或者 将精力增加 1 。
// 返回击败全部 n 个对手需要训练的 最少 小时数目。
//  
// 示例 1：
// 输入：initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
// 输出：8
// 解释：在 6 小时训练后，你可以将精力提高到 11 ，并且再训练 2 个小时将经验提高到 5 。
//
// 按以下顺序与对手比赛：
// - 你的精力与经验都超过第 0 个对手，所以获胜。
//   精力变为：11 - 1 = 10 ，经验变为：5 + 2 = 7 。
// - 你的精力与经验都超过第 1 个对手，所以获胜。
//   精力变为：10 - 4 = 6 ，经验变为：7 + 6 = 13 。
// - 你的精力与经验都超过第 2 个对手，所以获胜。
//   精力变为：6 - 3 = 3 ，经验变为：13 + 3 = 16 。
// - 你的精力与经验都超过第 3 个对手，所以获胜。
//   精力变为：3 - 2 = 1 ，经验变为：16 + 1 = 17 。
// 在比赛前进行了 8 小时训练，所以返回 8 。
// 可以证明不存在更小的答案。

// 示例 2：
// 输入：initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
// 输出：0
// 解释：你不需要额外的精力和经验就可以赢得比赛，所以返回 0 。
// Accepted
int Solution::minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
{
    int n = energy.size();
    unsigned int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(initialEnergy <= energy[i])
        {
            int p = energy[i] - initialEnergy + 1;
            initialEnergy += p;
            ans += p;
        }

        if(initialExperience <= experience[i])
        {
            int exp = experience[i] - initialExperience + 1;
            initialExperience += exp;
            ans += exp;
        }

        initialEnergy -= energy[i];
        initialExperience += experience[i];
    }
    return ans;
    
}

// 给你一个仅由数字（0 - 9）组成的字符串 num 。
// 请你找出能够使用 num 中数字形成的 最大回文 整数，并以字符串形式返回。该整数不含 前导零 。
// 注意：
// 你 无需 使用 num 中的所有数字，但你必须使用 至少 一个数字。
// 数字可以重新排序。
//  
// 示例 1：
// 输入：num = "444947137"
// 输出："7449447"
// 解释：
// 从 "444947137" 中选用数字 "4449477"，可以形成回文整数 "7449447" 。
// 可以证明 "7449447" 是能够形成的最大回文整数。
//
// 示例 2：
// 输入：num = "00009"
// 输出："9"
// 解释：
// 可以证明 "9" 能够形成的最大回文整数。
// 注意返回的整数不应含前导零。
// Accepted
string Solution::largestPalindromic(string num)
{
    int swap[10] = {0}; //记录0-9出现的次数
    string ans;     //最终
    string p1, p2;  //p1前半部分，p2后半部分
    string middle;  //中间
    int n = num.size();
    for(int i = 0; i < n; i++)
    {
        swap[num[i] - '0']++;
    }
    for(int j = 9; j >= 0; j--)
    {
        if(swap[j] == 0)
            continue;
        if(swap[j]%2 != 0 && middle.empty())
            middle = to_string(j);
        if(j == 0 && p1.empty())
        {
            if(middle.empty()) middle = "0";
            break;
        }
        for(int k = 1; k <= swap[j]/2; k++)
        {
            p1 += to_string(j);
        }
    }
    p2 = p1;
    reverse(p2.begin(), p2.end());
    ans = p1 + middle + p2;
    return ans;
}


