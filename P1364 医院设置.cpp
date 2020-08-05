/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-04 09:29:20
 * @LastEditTime: 2020-08-04 09:59:00
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1364 医院设置.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f

using namespace std;

struct node
{
    int l, r, w;
    int fa;
} tree[110];

int n, w, u, v;
int ans = INF;
int vis[110];

int dfs(int x, int dep)
{
    vis[x] = 1;
    int sum = 0;
    sum += tree[x].w * dep;
    if (tree[x].fa != 0 && !vis[tree[x].fa])
    {
        sum += dfs(tree[x].fa, dep + 1);
    }
    if (tree[x].l != 0 && !vis[tree[x].l])
    {
        sum += dfs(tree[x].l, dep + 1);
    }
    if (tree[x].r != 0 && !vis[tree[x].r])
    {
        sum += dfs(tree[x].r, dep + 1);
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> u >> v;
        tree[i].l = u;
        tree[i].r = v;
        tree[i].w = w;
        tree[u].fa = i;
        tree[v].fa = i;
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        ans = min(ans, dfs(i, 0));
    }
    cout << ans;
}
