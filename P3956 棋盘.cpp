/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-08 12:44:45
 * @LastEditTime: 2020-08-08 18:11:20
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3956 棋盘.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxm 105
#define maxn 1010
#define INF 0x7f7f7f

using namespace std;

int g[maxm][maxm];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int sum[maxm][maxm];
int m, n;
int ans = INF;

void dfs(int x, int y, int cion, int change)
{
    if (x > m || x < 1 || y > m || y < 1)
        return;
    if (cion >= sum[x][y])
        return;
    sum[x][y] = cion;
    if (x == m && y == m)
    {
        ans = min(ans, cion);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (g[xx][yy])
        {
            if (g[xx][yy] == g[x][y])
            {
                dfs(xx, yy, cion, 0);
            }
            else
            {
                dfs(xx, yy, cion + 1, 0);
            }
        }
        else if (!change)
        {
            g[xx][yy] = g[x][y];
            dfs(xx, yy, cion + 2, 1);
            g[xx][yy] = 0;
        }
    }
}

int main()
{
    cin >> m >> n;
    int x, y, c;
    memset(sum, INF, sizeof(sum));
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> c;
        g[x][y] = c + 1;
    }
    dfs(1, 1, 0, 0);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}