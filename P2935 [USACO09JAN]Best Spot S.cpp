#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f

using namespace std;

int p, f, c;
int fa[500];
int g[550][550];
int dis[550][550];
int ans;
int mi = INF;

int main()
{
    cin >> p >> f >> c;
    for (int i = 1; i <= f; i++)
    {
        cin >> fa[i];
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= p; j++)
            dis[i][j] = INF;
        dis[i][i] = 0;
    }
    int x, y, z;
    for (int i = 1; i <= c; i++)
    {
        cin >> x >> y >> z;
        g[x][y] = z;
        dis[x][y] = z;
        dis[y][x] = z;
    }
    for (int k = 1; k <= p; k++)
    {
        for (int i = 1; i <= p; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= p; i++)
    {
        int sum = 0;
        for (int j = 1; j <= f; j++)
        {
            sum += dis[i][fa[j]];
        }
        if (sum < mi)
        {
            mi = sum;
            ans = i;
        }
    }
    cout << ans;
}
