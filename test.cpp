/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-04-30 10:15:37
 * @LastEditTime: 2020-08-04 11:21:28
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\test.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 100005

using namespace std;

struct node
{
    int to, next;
} e[maxn];
int head[maxn];
int cnt;
int ans[maxn];
int n, m;
int vis[maxn];

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int x)
{
    vis[x] = 1;
    int ans = x;
    for (int i = head[x]; i; i = e[i].next)
    {
        if (!vis[e[i].to])
            ans = max(ans, dfs(e[i].to));
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        ans[i] = dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}