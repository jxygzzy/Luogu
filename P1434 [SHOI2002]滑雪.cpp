/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-31 09:32:39
 * @LastEditTime: 2020-07-31 10:05:21
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1434 [SHOI2002]滑雪.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 105

using namespace std;

int a[maxn][maxn];
int r, c;
int ans;
int dis[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int i, int j)//记忆化搜索
{
    if (dis[i][j])
        return dis[i][j];
    dis[i][j] = 1;
    for (int x = 0; x < 4; x++)
    {
        int next_i = i + dx[x];
        int next_j = j + dy[x];
        if (next_i >= 0 && next_j >= 0 && next_i < r && next_j < c && a[i][j] > a[next_i][next_j])
        {
            dis[next_i][next_j]=dfs(next_i, next_j);
            dis[i][j] = max(dis[i][j], dis[next_i][next_j] + 1);
        }
    }
    return dis[i][j];
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}