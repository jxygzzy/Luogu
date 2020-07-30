/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-24 09:45:55
 * @LastEditTime: 2020-07-24 10:15:54
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 
 * 题目描述
 * 虽然 Miss Medusa 到了北京，领了科技创新奖，但是他还是觉得不满意。原因是：他发现很多人都和他一样获了科技创新奖，
 * 特别是其中的某些人，还获得了另一个奖项——特殊贡献奖。而越多的人获得了两个奖项，Miss Medusa就会越眼红。于是她决定统计有哪些人获得了两个奖项，
 * 来知道自己有多眼红。
 * 
 * 输入格式
 * 第一行两个整数 n, m表示有 n 个人获得科技创新奖，m 个人获得特殊贡献奖。
 * 第二行 n 个正整数，表示获得科技创新奖的人的编号。
 * 第三行 m 个正整数，表示获得特殊贡献奖的人的编号。
 * 输出格式
 * 输出一行，为获得两个奖项的人的编号，按在科技创新奖获奖名单中的先后次序输出。
 * 
 * 对于 100% 的数据，1≤n,m≤10^5，获得奖项的人的编号 <2×10^9
 * 
 * @FilePath: \Luogu\P1571 眼红的Medusa.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <map>
#include <algorithm>
#define maxn 100005

using namespace std;

int n, m;
map<int, int> a;       //映射记录初始位置
int first_sort[maxn];  //单个获奖,需排序
int first[maxn];       //初始不动
int judge[maxn] = {0}; //获奖两项

int find(int x) //二分查找，未找到返回-1
{
    int left = 0;
    int right = n;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (x == first_sort[mid])
            return mid;
        if (x > first_sort[mid])
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        if (x < first_sort[mid])
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    if (left > right)
        return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        first[i] = t;
        first_sort[i] = t;
        a[t] = i;
    }
    sort(first_sort, first_sort + n); //排好序，以便二分查找
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (find(x) != -1)
            judge[a[x]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (judge[i])
            cout << first[i] << " ";
    }
}