#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 205
#define INF 0x3f3f3f

using namespace std;

int f[maxn], n, r, g[maxn][maxn];

int main()
{
    cin >> n;
    // memset(f,INF,sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                g[i][j] = INF;
            else
                g[i][j] = 0;
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1 + i; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    // f[1]=0;
    // for(int i=2;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         f[j]=min(f[i]+g[i][j],f[j]);
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            g[1][i] = min(g[1][i], g[1][k] + g[k][i]);
        }
    }
    cout << g[1][n];
}