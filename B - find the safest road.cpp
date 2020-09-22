#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

double g[1005][1005];
int n, q;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%lf", &g[i][j]);
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
                }
            }
        }
        scanf("%d", &q);
        int s, e;
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d", &s, &e);
            if (!g[s][e])
            {
                printf("What a pity!\n");
            }
            else
            {
                printf("%.3f\n", g[s][e]);
            }
        }
    }
}