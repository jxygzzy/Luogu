/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-15 16:11:09
 * @LastEditTime: 2020-08-15 16:14:53
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\UVA572 油田 Oil Deposits.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 150

using namespace std;

char g[maxn][maxn];
int vis[maxn][maxn];
int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int n, m, ans;

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x > n || y > m)
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {

        int xx = x + dx[i];
        int yy = y + dy[i];
        if (g[xx][yy] == '@' && !vis[xx][yy])
            dfs(xx, yy);
    }
}

int main()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        memset(g, '*', sizeof(g));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> g[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] == '@' && !vis[i][j])
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
}
