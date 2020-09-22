#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define maxn 20
#define maxm 1005
#define INF 0x3f3f3f
#define ll long long
using namespace std;

int n, m;
int g[maxn][maxm];
ll ans[maxn];
ll res = INF;

int main()
{
    cin >> n >> m;
    int u, v, w;
    memset(g, INF, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u][v] = min(w, g[u][v]);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] != INF)
                ans[i] += g[i][j];
        }
        res = min(res, ans[i]);
    }
    cout << res;
    return 0;
}