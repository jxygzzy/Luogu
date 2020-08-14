/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-13 14:54:51
 * @LastEditTime: 2020-08-13 15:55:40
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1550 [USACO08OCT]Watering Hole G.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 350
using namespace std;

struct node
{
    int x, y, w;
} e[maxn * maxn];
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int cnt;
int f[maxn];

int find(int x)
{
    if (f[x] == x)
        return x;
    else
        return f[x] = find(f[x]);
}

int n, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        e[++cnt].w = t;
        e[cnt].x = 0;
        e[cnt].y = i;
        f[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t;
            cin >> t;
            if (i > j)
            {
                e[++cnt].w = t;
                e[cnt].x = i;
                e[cnt].y = j;
            }
        }
    }
    sort(e + 1, e + 1 + cnt, cmp);
    int t = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int u, v;
        u = find(e[i].x);
        v = find(e[i].y);
        if (u == v)
            continue;
        f[u]=v;
        t++;
        ans += e[i].w;
        if (n == t)
            break;
    }
    cout << ans;
    return 0;
}
