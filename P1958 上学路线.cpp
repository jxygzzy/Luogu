/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-05 11:40:12
 * @LastEditTime: 2020-08-05 13:10:07
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1958 上学路线.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 50
using namespace std;

int a, b;
int g[maxn][maxn];
int ans;
int n, x, y;
int vis[maxn][maxn];
int dx[2] = {1, 0}; //只能往右和下
int dy[2] = {0, 1};

void dfs(int x, int y)
{

    if (x == a && y == b)
    {
        ans++;
        return;
    }
    int x1 = x + dx[0];
    int y1 = y + dy[0];
    if (!vis[x1][y1] && g[x1][y1])
    {
        vis[x1][y1] = 1;
        dfs(x1, y1);
        vis[x1][y1] = 0;
    }
    int x2 = x + dx[1];
    int y2 = y + dy[1];
    if (!vis[x2][y2] && g[x2][y2])
    {
        vis[x2][y2] = 1;
        dfs(x2, y2);
        vis[x2][y2] = 0;
    }
}

int main()
{
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            g[i][j] = 1;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        g[x][y] = 0;
    }
    vis[1][1] = 1;
    dfs(1, 1);
    cout << ans;
}
