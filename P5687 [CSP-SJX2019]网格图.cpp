/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-04 15:24:07
 * @LastEditTime: 2020-08-04 16:13:43
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5687 [CSP-SJX2019]网格图.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 300005

using namespace std;

struct node
{
    int w;
    int dir;
} g[maxn];
int cnt;
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int n, m;
int ans;
int f[maxn * 2];

int find(int x)
{
    if (x == f[x])
        return f[x];
    else
        return f[x] = find(f[x]);
}

void kruskal()
{
    for (int i = 1; i <= cnt; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int dir = g[i].dir;
        int w = g[i].w;
        // (i - 1) * n + j;
        int u = find(i);
        int v = find(i + 1);
        if (u == v)
            continue;
        f[u] = v;
        ans += g[i].w;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[++cnt].w;
        g[cnt].dir = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> g[++cnt].w;
        g[cnt].dir = 1;
    }
    sort(g + 1, g + cnt + 1, cmp);
    kruskal();
    cout << ans;
}
