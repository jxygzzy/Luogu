/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-13 13:50:12
 * @LastEditTime: 2020-08-13 14:21:36
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3884 [JLOI2009]二叉树问题.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 110

using namespace std;

struct node
{
    int to, next;
} e[maxn];
int head[maxn];
int cnt;

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int n, st, lt, lca, max_dep = 1, max_width = 1, dis;
int f[maxn];
int vis[maxn];
int dep[maxn];
int width[maxn];

int find(int x)
{
    if (f[x] == x)
        return x;
    else
        return find(f[x]);
}

void tarjan(int x)
{
    for (int i = head[x]; i; i = e[i].next)
    {
        tarjan(e[i].to);
        vis[e[i].to] = 1;
        f[e[i].to] = x;
    }
    if (x == st)
    {
        if (vis[lt])
        {
            lca = find(lt);
            return;
        }
    }
    if (x == lt)
    {
        if (vis[st])
        {
            lca = find(st);
            return;
        }
    }
}

int main()
{
    cin >> n;
    int u, v;
    dep[1] = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        add(u, v);
        f[i] = i;
        dep[v] = dep[u] + 1;
    }
    cin >> st >> lt;
    for (int i = 1; i <= n; i++)
    {
        max_dep = max(max_dep, dep[i]);
        width[dep[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        max_width = max(max_width, width[i]);
    }
    tarjan(1);
    dis = (dep[st] - dep[lca]) * 2 + (dep[lt] - dep[lca]);
    cout << max_dep << endl;
    cout << max_width << endl;
    cout << dis;
}
