/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 18:08:39
 * @LastEditTime: 2020-07-29 20:24:41
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * --最小生成树--
 * 首先每个格子都跟它周围的格子建边。
 * 然后将边权从小到大排序依次加入。
 * 每加入一条边后，判断是否有集合里的元素超过了一半格子数。
 * 如果超过了，直接输出这条边的权即可。
 * @FilePath: \Luogu\P3073 [USACO13FEB]Tractor S.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#define maxn 505

using namespace std;
int g[maxn][maxn];
int n;
int cnt;
int maxt;//一半的格子数
int ans;
struct node
{
    int u, v, w;
} e[maxn * maxn * 2];
bool cmp(node a, node b)
{
    return a.w < b.w;
}

int f[maxn * maxn];    //并查集,并查集是一维的结构，把二维压缩到一维的方法：(i,j)→(i−1)n+j
int size[maxn * maxn]; //集合里元素个数
int trans(int i, int j)
{
    return (i - 1) * n + j;
}

int find(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = find(f[x]);
}

int main()
{
    cin >> n;
    maxt = n * n / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) //建边
    {
        for (int j = 1; j <= n; j++)
        {
            int x = i, y = j + 1;
            if (x >= 1 && x <= n && y >= 1 && y <= n)//防止越界
            {
                e[++cnt].u = trans(i, j);
                e[cnt].v = trans(x, y);
                e[cnt].w = abs(g[i][j] - g[x][y]);
            }
            x = i + 1, y = j;
            if (x >= 1 && x <= n && y >= 1 && y <= n)
            {
                e[++cnt].u = trans(i, j);
                e[cnt].v = trans(x, y);
                e[cnt].w = abs(g[i][j] - g[x][y]);
            }
        }
    }
    sort(e + 1, e + 1 + cnt, cmp);//按边长排序
    for (int i = 1; i <= n * n; i++)//初始化集合
    {
        f[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int x, y;
        x = find(e[i].u);
        y = find(e[i].v);
        if (x == y)
            continue;
        if (x > y) //交换值，新学的，异或的应用
        {
            x = x ^ y;
            y = x ^ y;
            x = y ^ x;
        }
        size[y] += size[x];
        f[x] = y;
        if (size[y] >= maxt)
        {
            cout << e[i].w;
            break;
        }
    }
}
