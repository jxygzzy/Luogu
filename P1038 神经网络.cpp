#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
queue<int> q;
struct node
{
    int u, v, w, nt;
} edge[MAXN * MAXN];
int c[MAXN], u[MAXN], head[MAXN], in[MAXN], out[MAXN];
int n, m, cnt;
void add(int u, int v, int w)
{
    edge[++cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].nt = head[u];
    head[u] = cnt;
    in[v]++;
    out[u]++;
}
void topsort()
{
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i != 0; i = edge[i].nt)
        {
            int v = edge[i].v;
            in[v]--;
            if (c[x] > 0)
                c[v] += c[x] * edge[i].w;
            if (!in[v])
                q.push(v);
        }
    }
}
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> u[i];
        if (!c[i])
            c[i] -= u[i];
    }
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    topsort();
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] > 0 && out[i] == 0)
        {
            cout << i << ' ' << c[i] << endl;
            flag=1;
        }
    }
    if (!flag)
        cout << "NULL" << endl;
    return 0;
}