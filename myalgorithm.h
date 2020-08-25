#pragma once

#include<iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <random>

#define LISTOPTION_INORDER 1      /* 结点值随机，链表有序 */
#define LISTOPTION_NOORDER 2      /* 结点值随机，链表无序 */
#define LISTOPTION_1NORDER 3      /* 从最小值开始,每个结点值+1的N个结点 */

using namespace std;

struct ListNode;
struct TreeNode;

void randomvector(vector<int> &data, int N, int min, int max);
void qs(vector<int> &data, int left, int right);
void heapsort(vector<int> &data);
void perDown(vector<int> &data, int i, int n);

ListNode* randomList(int N, int min, int max, unsigned int OPTION = LISTOPTION_NOORDER);

// 递归终止函数
template<typename...T>
ListNode * initList()
{
    return nullptr;
}
// 展开函数
template<typename... T>
ListNode * initList(int t, T...r)
{
    ListNode* rtn;
    rtn = new ListNode(t);
    rtn->next = initList(r...);
    return rtn;
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* BBT(vector<int> &data);       // 根据data中的数据构建一个棵平衡二叉树并返回根节点

int kmp(string str, string pattern);    // 返回模式子串在str中的起始位置
int maxcompresuf(string);


/*
vector<vector<int>> ans;
vector<int> temp;
void dfsenum(int cur, vector<int> &nums)    // 枚举子序列的模板
{
    if (cur == nums.size()) {
        if (isValid() && isRepeat())   // 判断合法以及是否重复
        {
            ans.push_back(temp);
        }
    }

    // 加入当前元素
    temp.push_back(nums[cur]);
    dfsenum(cur + 1, nums);
    // 不加入当前元素
    temp.pop_back();
    dfsenum(cur + 1, nums);


}*/













