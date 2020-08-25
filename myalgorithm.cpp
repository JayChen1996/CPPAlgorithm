#include "myalgorithm.h"

using namespace std;

void MSort(vector<int> input, vector<int> & output, int s, int m)
{
    // 将input中从s到m，排序后放到output中去
    if (s > m)
        return;
    else if (s == m)
        output[s] = input[s];
    else {
        // 将input分为左边和右边，先将input左边排好序，再将其右边右边排好序，然后归并到output对应位置
        vector<int> t(input);
        int center = (m + s) / 2;
        MSort(input, t, s, center);
        MSort(input, t, center + 1, m);
        // 合并t中的二者到output中去，
        int i = s, j = center + 1, k = s;
        for (; i <= center && j <= m; k++)
        {
            if (t[i] < t[j])
            {
                output[k] = t[i];
                i++;
            }
            else
            {
                output[k] = t[j];
                j++;
            }
        }
        while (i <= center) {
            output[k] = t[i];
            i++;
            k++;
        }
        while (j <= m) {
            output[k] = t[j];
            j++;
            k++;
        }
    }
}


void MergeSort(vector<int> & data)
{
    vector<int> t(data);
    MSort(t, data, 0, data.size() - 1);
    return;  
}


void randomvector(vector<int> &data, int N, int min, int max)
{
    // 向data中增加N个随机生成的[min, max)之间的整数
    random_device rd;
    for (int i = 0; i < N; i++) {
        data.push_back((rd() % (max - min) + min));
    }
}

void qs(vector<int> &data, int left, int right)
{
    if (left >= right)
        return;

    int t = data[left];
    int l = left;
    int r = right;

    while (l < r) {
        while (l<r&&data[r]>t)
            r--;
        if (l < r) {
            data[l] = data[r]; l++;
        }
        while (l < r&&data[l] < t)
            l++;
        if (l < r) {
            data[r] = data[l]; r--;
        }
    }
    data[l] = t;
    qs(data, left, l - 1);
    qs(data, l + 1, right);

}

void heapsort(vector<int> &data)
{
    // 建堆
    for (int i = data.size() / 2; i >= 0; i--)
    {
        perDown(data, i, data.size());
    }

    // 堆顶元素和最后一个元素交换
    for (int i = data.size(); i > 1; i--)
    {
        swap(data[0], data[i-1]);
        perDown(data, 0, i - 1);
    }
}

void perDown(vector<int> &data, int i, int n)
/**
*   把最大的元素放大堆顶
*/
{
    int tmp = data[i];
    int child = 2 * i + 1;

    while (child < n) {
        if (child < n - 1 && data[child] < data[child + 1])
            child++;
        if (tmp < data[child])
        {
            data[i] = data[child];
            i = child; child = 2 * i + 1;
        }
        else
            break;
    }
    data[i] = tmp;
}



ListNode* randomList(int N, int min, int max, unsigned int OPTION)
/*
* random    N,   -返回链表中有N个结点
*           min, -返回链表中结点值最小为min
*           max, -返回链表中结点值最大为max
*           OPTION,    -LISTOPTION_INORDER(1)  有序链表
*                      -LISTOPTION_NOORDER(2)  无序链表  (默认)
*                      -LISTOPTION_1NORDER(3)  从min开始的N个结点的链表，每个结点比前一个+1
*/
{
    random_device rd;
    ListNode* rtn(nullptr);
    ListNode* move(nullptr);
    if (N < 1)
        return rtn;
    if (N == 1 && OPTION != LISTOPTION_1NORDER) {
        rtn = new ListNode(rd() % (max - min) + min);
        return rtn;
    }
    rtn = new ListNode(rd() % (max - min) + min);
    N--;
    move = rtn;
    if (OPTION == LISTOPTION_INORDER) {
        while (N--) {
            move = new ListNode(rd() % (max - min) + min);
            ListNode* t = rtn;
            if (t->val >= move->val) {   // 插入到最前面
                move->next = t;
                rtn = move;
                continue;
            }
            while (t->next != nullptr) {
                if (t->next->val < move->val)
                    t = t->next;
                else
                    break;
            }
            move->next = t->next;
            t->next = move;
        }
        return rtn;
    }
    if (OPTION == LISTOPTION_1NORDER) {
        bool firstflg(true);
        ListNode* move;
        ListNode* t;
        while (N-- || min<max) {
            if (firstflg) {
                move = new ListNode(min); rtn = move; move = rtn; t = rtn;
                min++;
            }
            else {
                t = new ListNode(min); move->next = t; move = move->next;
                min++;
            }
        }
        return rtn;
    }
    ListNode *t;
    while (N--) {
        t = new ListNode(rd() % (max - min) + min);
        move->next = t; move = move->next;
    }
    return rtn;
}



void insertBBT(TreeNode* root, TreeNode* data)
{
    // 将data插入平衡二叉树中。
}
TreeNode* BBT(vector<int> &data, int loc, TreeNode* &root)
{
    TreeNode* t = new TreeNode(data[loc]);


    return root;
}
TreeNode* BBT(vector<int> &data)
{
    TreeNode* rtn(nullptr);
    // 根据data中的数据构建一个棵平衡二叉树并返回根节点
    if (data.size() == 0)
        return nullptr;
    BBT(data, 0, rtn);
    return rtn;
}

int kmp(string str, string pattern)
{
    // https://www.bilibili.com/video/BV1jb411V78H/
    // 先求出next数组
    vector<int> next(pattern.length(),0);
    for (int i = 0; i < next.size(); i++)
    {
        int nextval = maxcompresuf(string(pattern.begin(), pattern.begin() + i));
        next[i] = nextval;
    }

    int i = 0; int j = 0;
    for (; j < pattern.length()&&i<str.length();) {
        if (str[i] != pattern[j]) {
            // 不相等之后，使用j的第next[j]个字符继续和str[i]进行比较
            j = next[j];
            if (j == 0) { i++; }
        }
        else {
            i++; j++;
        }
    }
    if (j == pattern.length())
        return i - j;
    return -1;
}

int maxcompresuf(string str)
{
    // 得到str的最长公共前后缀,前缀后缀的长度小于str的长度
    // 返回最长公公前后缀的长度
    if (str.length() <= 1)
        return 0;
    int rtn;
    int len = str.length();
    for (rtn = len-1; rtn >=1; rtn--)
    {
        int i;
        for (i = 0; i < rtn; i++)
        {
            if (str[i] == str[len - rtn+i]) {
                continue;
            }
            else {
                break;
            }
        }
        if (i == rtn)
            return rtn;
    }
}

















