/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-04 10:39:13
 * @LastEditTime: 2020-08-04 14:18:07
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3916 图的遍历.cpp
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

void dfs(int u, int from)
{
    if (ans[u])
            return;
    ans[u] = from;
    for (int i = head[u]; i; i = e[i].next)
    {
        dfs(e[i].to, from);
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(v, u);
    }
    for (int i = n; i >= 1; i--)
    {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

/**
 *暴力超时做法
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
*/