/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 11:35:20
 * @LastEditTime: 2020-07-29 15:15:59
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2420 让我们异或吧.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;

int head[maxn], dis[maxn];
int n, m, cnt;
int u, v, w;
int visit[maxn];

struct node
{
    int to, next, w;
} edge[maxn * 2];

void dfs(int id, int val)
{
    dis[id] = val;
    visit[id] = 1;
    for (int i = head[id]; i; i = edge[i].next)
    {
        if (!visit[edge[i].to])
        {
            dfs(edge[i].to, val ^ edge[i].w);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        edge[++cnt].to = v;
        edge[cnt].next = head[u];
        edge[cnt].w = w;
        head[u] = cnt;
        edge[++cnt].to = u;
        edge[cnt].next = head[v];
        edge[cnt].w = w;
        head[v] = cnt;
    }
    dfs(1, 0);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cout << (dis[u] ^ dis[v]) << endl;
    }
}
