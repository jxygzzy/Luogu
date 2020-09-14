#include <iostream>
#include <algorithm>
#include <cstring>
#pragma GCC optimize("Ofast")
#define maxn 1005
#define maxm 100005
#define INF 0x3f3f3f

using namespace std;



int g[maxn][maxn];
int g2[maxn][maxn];
int n, m;

int main()
{
    ios::sync_with_stdio;
    cin >> n >> m;
    int u, v, w;
    memset(g, INF, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u][v] = min(w, g[u][v]);
        g2[v][u]=min(w,g2[v][u]);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (g[i][k] < INF)
                for (int j = 1; j <= n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += (g[1][i] + g[i][1]);
    }
    cout << ans;

    return 0;
}