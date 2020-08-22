#include <iostream>
#include <algorithm>
#define maxn 100010

using namespace std;

struct node
{
    int to, next;
} e[maxn * 2];
int head[maxn * 2];
int cnt;

int dep[maxn], ans[maxn], ans_cnt, n;
int root[maxn];

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int x, int pre)
{
    root[x] = 1;
    int num = 0;
    for (int i = head[x]; i; i = e[i].next)
    {
        if (e[i].to != pre)
        {
            dep[x] += dfs(e[i].to, x);
            if (!num)
            {
                num = dep[e[i].to];
            }
            if (num != dep[e[i].to])
            {
                root[x] = 0;
            }
        }
    }
    dep[x]++;
    if (x != 1 && num != n - dep[x] && num)
    {
        root[x] = 0;
    }
    return dep[x];
}

int main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (root[i])
        {
            cout << i << ' ';
        }
    }
    return 0;
}