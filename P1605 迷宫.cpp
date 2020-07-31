/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-31 10:05:47
 * @LastEditTime: 2020-07-31 14:06:58
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1605 迷宫.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[6][6];
int n, m, t;
int visit[6][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sx, sy;
int fx, fy;
int tx, ty;
int ans;

void dfs(int x, int y) //回溯
{
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!visit[xx][yy]&&a[xx][yy])
        {
            visit[x][y] = 1;
            dfs(xx, yy);
            visit[x][y] = 0;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= n; i++)//下标从1开始，注意分析样例
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = 1;//确定地图范围
        }
    }
    for (int i = 0; i < t; i++)
    {
        cin >> tx >> ty;
        a[tx][ty] = 0;//障碍物和边界都不在范围
    }
    dfs(sx, sy);
    cout << ans;
}