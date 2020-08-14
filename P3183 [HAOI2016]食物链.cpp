/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-13 12:31:08
 * @LastEditTime: 2020-08-13 13:31:28
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3183 [HAOI2016]食物链.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 100005
#define maxm 200005

using namespace std;

struct node
{
    int to, next;
} e[maxm];
int head[maxm];
int cnt;

int n, m, ans;
int in[maxn], out[maxn];
int f[maxn];
void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int x)
{
    if (f[x])
        return f[x];
    int sum = 0;
    if (out[x] == 0 && in[x])
    {
        sum++;
    }
    for (int i = head[x]; i; i = e[i].next)
    {
        sum += dfs(e[i].to);
    }
    f[x] = sum;
    return f[x];
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
        in[v]++;
        out[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            ans += dfs(i);
    }
    cout << ans;
}
