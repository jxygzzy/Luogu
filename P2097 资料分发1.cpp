/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-25 10:25:04
 * @LastEditTime: 2020-07-25 10:57:46
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 题目描述
 * 有一些电脑，一部分电脑有双向数据线连接。如果一个电脑得到数据，它可以传送到的电脑都可以得到数据。现在，你有这个数据，
 * 问你至少将其输入几台电脑，才能使所有电脑得到数据。
 * 
 * 输入格式
 * 第一行两个数n，m。n是点数，m是边数。
 * 接下来m行，每行2个整数p，q表示p到q有一条双向数据线。
 * 
 * 输出格式
 * 一个整数，表示至少输入的电脑数量。
 * n<=100000, m<=200000
 * 
 * @FilePath: \Luogu\P2097 资料分发1.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 100000

using namespace std;

struct node
{
    int parent;
    int cnt;
    int value;
} Set[maxn];
int n, m;
int x, y;

int Find(int x)
{
    int y = x;
    while (Set[y].parent != y)
        y = Set[y].parent;
    while (x != y)
    {
        int temp = Set[x].parent;
        Set[x].parent = y;
        x = temp;
    }
    return y;
}
void Union(int x, int y)
{
    x = Find(x), y = Find(y);
    if (x == y)
        return;
    if (Set[x].cnt > Set[y].cnt)
    {
        Set[y].parent = x;
        Set[x].cnt += Set[y].cnt;
    }
    else
    {
        Set[x].parent = y;
        Set[y].cnt += Set[x].cnt;
    }
}
void Init(int cnt)
{
    for (int i = 1; i <= cnt; i++)
    {
        Set[i].parent = i;
        Set[i].cnt = 1;
        Set[i].value = 0;
    }
}

int main()
{
    cin >> n >> m;
    Init(n);
    while (m--)
    {
        cin >> x >> y;
        Union(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Set[i].parent == i)
        {
            ans++;
        }
    }
    cout<<ans;
}