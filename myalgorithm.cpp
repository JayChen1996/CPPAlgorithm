#include "myalgorithm.h"

using namespace std;

void MSort(vector<int> input, vector<int> & output, int s, int m)
{
    // ��input�д�s��m�������ŵ�output��ȥ
    if (s > m)
        return;
    else if (s == m)
        output[s] = input[s];
    else {
        // ��input��Ϊ��ߺ��ұߣ��Ƚ�input����ź����ٽ����ұ��ұ��ź���Ȼ��鲢��output��Ӧλ��
        vector<int> t(input);
        int center = (m + s) / 2;
        MSort(input, t, s, center);
        MSort(input, t, center + 1, m);
        // �ϲ�t�еĶ��ߵ�output��ȥ��
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
    // ��data������N��������ɵ�[min, max)֮�������
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
    // ����
    for (int i = data.size() / 2; i >= 0; i--)
    {
        perDown(data, i, data.size());
    }

    // �Ѷ�Ԫ�غ����һ��Ԫ�ؽ���
    for (int i = data.size(); i > 1; i--)
    {
        swap(data[0], data[i-1]);
        perDown(data, 0, i - 1);
    }
}

void perDown(vector<int> &data, int i, int n)
/**
*   ������Ԫ�طŴ�Ѷ�
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
* random    N,   -������������N�����
*           min, -���������н��ֵ��СΪmin
*           max, -���������н��ֵ���Ϊmax
*           OPTION,    -LISTOPTION_INORDER(1)  ��������
*                      -LISTOPTION_NOORDER(2)  ��������  (Ĭ��)
*                      -LISTOPTION_1NORDER(3)  ��min��ʼ��N����������ÿ������ǰһ��+1
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
            if (t->val >= move->val) {   // ���뵽��ǰ��
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
    // ��data����ƽ��������С�
}
TreeNode* BBT(vector<int> &data, int loc, TreeNode* &root)
{
    TreeNode* t = new TreeNode(data[loc]);


    return root;
}
TreeNode* BBT(vector<int> &data)
{
    TreeNode* rtn(nullptr);
    // ����data�е����ݹ���һ����ƽ������������ظ��ڵ�
    if (data.size() == 0)
        return nullptr;
    BBT(data, 0, rtn);
    return rtn;
}

int kmp(string str, string pattern)
{
    // https://www.bilibili.com/video/BV1jb411V78H/
    // �����next����
    vector<int> next(pattern.length(),0);
    for (int i = 0; i < next.size(); i++)
    {
        int nextval = maxcompresuf(string(pattern.begin(), pattern.begin() + i));
        next[i] = nextval;
    }

    int i = 0; int j = 0;
    for (; j < pattern.length()&&i<str.length();) {
        if (str[i] != pattern[j]) {
            // �����֮��ʹ��j�ĵ�next[j]���ַ�������str[i]���бȽ�
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
    // �õ�str�������ǰ��׺,ǰ׺��׺�ĳ���С��str�ĳ���
    // ���������ǰ��׺�ĳ���
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

















