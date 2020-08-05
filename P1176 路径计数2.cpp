/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-05 12:36:32
 * @LastEditTime: 2020-08-05 13:18:01
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1176 路径计数2.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 1005
#define MOD 100003
using namespace std;

int f[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int x, y;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        vis[x][y] = 1;
    }
    f[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
            if (vis[i][j])
                f[i][j] = 0; //有障碍物，记为0
        }
    }
    cout << f[n][n];
}

// #include <iostream>
// #include <algorithm>
// #define maxn 1005
// #define MOD 100003

// using namespace std;

// int g[maxn][maxn];
// int vis[maxn][maxn];
// int dx[2] = {0, 1};
// int dy[2] = {1, 0};
// int ans;
// int n, m;
// int x, y;

// void dfs(int x, int y)
// {
//     if (x == n && y == n)
//     {
//         ans = (ans+1) % MOD;
//         return;
//     }
//     int x1 = x + dx[0];
//     int y1 = y + dy[0];
//     if (!vis[x1][y1] && g[x1][y1])
//     {
//         vis[x1][y1] = 1;
//         dfs(x1, y1);
//         vis[x1][y1] = 0;
//     }
//     int x2 = x + dx[1];
//     int y2 = y + dy[1];
//     if (!vis[x2][y2] && g[x2][y2])
//     {
//         vis[x2][y2] = 1;
//         dfs(x2, y2);
//         vis[x2][y2] = 0;
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             g[i][j] = 1;
//         }
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> x >> y;
//         g[x][y] = 0;
//     }
//     vis[1][1] = 1;
//     dfs(1, 1);
//     cout << ans;
// }
