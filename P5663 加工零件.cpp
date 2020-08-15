#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 10005

using namespace std;

int n, m, q;
int vis[maxn][maxn];
struct node
{
    int u, v, next;
} e[maxn * 2];
int head[maxn * 2];
int cnt;

void add(int u, int v)
{
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int a, int l)
{
    if (l == -1 || vis[a][l])
        return;
    vis[a][l] = 1;
    for (int i = head[a]; i; i = e[i].next)
    {
        dfs(e[i].v, l - 1);
    }
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= q; i++)
    {
        int a, l;
        memset(vis, 0, sizeof(vis));
        cin >> a >> l;
        dfs(a, l);
        if (vis[1][0])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
