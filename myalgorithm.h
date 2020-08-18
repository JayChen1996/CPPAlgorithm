#pragma once

#include<iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <random>

#define LISTOPTION_INORDER 1      /* ���ֵ������������� */
#define LISTOPTION_NOORDER 2      /* ���ֵ������������� */
#define LISTOPTION_1NORDER 3      /* ����Сֵ��ʼ,ÿ�����ֵ+1��N����� */

using namespace std;

struct ListNode;
struct TreeNode;

void randomvector(vector<int> &data, int N, int min, int max);
void qs(vector<int> &data, int left, int right);
void heapsort(vector<int> &data);
void perDown(vector<int> &data, int i, int n);

ListNode* randomList(int N, int min, int max, unsigned int OPTION = LISTOPTION_NOORDER);

// �ݹ���ֹ����
template<typename...T>
ListNode * initList()
{
    return nullptr;
}
// չ������
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


TreeNode* BBT(vector<int> &data);       // ����data�е����ݹ���һ����ƽ������������ظ��ڵ�

















