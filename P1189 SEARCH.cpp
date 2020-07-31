/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-31 13:51:45
 * @LastEditTime: 2020-07-31 14:43:03
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1189 SEARCH.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define maxn 60

using namespace std;

int a[maxn][maxn];     //地图范围。1表示可走
int ans[maxn][maxn];   //可能的位置
int visit[maxn][maxn]; //搜索时防止重复
char m[maxn][maxn];    //原始地图字符
int r, c, n;
string dir;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int index)
{
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (ans[i][j] && !visit[i][j])
            {
                int x = i + dx[index];
                int y = j + dy[index];
                ans[i][j] = 0;  //离开当前位置，当前位置不为最终位置
                while (a[x][y]) //在地图范围内查找所有可以到的位置
                {
                    ans[x][y] = 1;
                    visit[x][y] = 1;
                    x = x + dx[index];
                    y = y + dy[index];
                }
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == '*')
            {
                ans[i][j] = 1;
                a[i][j] = 1;
            }
            else if (m[i][j] == '.')
            {
                a[i][j] = 1;
            }
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dir;
        if (dir[0] == 'N')
            dfs(0);
        if (dir[0] == 'E')
            dfs(1);
        if (dir[0] == 'S')
            dfs(2);
        if (dir[0] == 'W')
            dfs(3);
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (ans[i][j])
            {
                cout << '*';
            }
            else if (m[i][j]=='*')
            {
                cout << '.';
            }
            else
            {
                cout << m[i][j];
            }
        }
        cout << '\n';
    }
}
