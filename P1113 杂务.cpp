/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-01 13:02:05
 * @LastEditTime: 2020-08-01 15:07:44
 * @LastEditors: P19Y0UN9_居居
 * @Description: 关键路径，拓扑排序
 * @FilePath: \Luogu\P1113 杂务.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int g[10005][10005]; //连通
int cnt[10005];      //入度
int t[10005];        //时间
int f[10005];        //最晚结束时间
int n;               //杂物数
queue<int> q;

int topsort()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0)
        {
            q.push(i);
            f[i] = t[i];
        }
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        // f[i]=t[i];
        ans = max(ans, f[i]);
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == 1)
            {
                cnt[j]--;
                f[j] = max(f[j], f[i] + t[j]);
                if (cnt[j] == 0)
                {
                    q.push(j);
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        cin >> t[v];
        int u;
        while (cin >> u && u != 0)
        {
            g[u][v] = 1;
            cnt[v]++;
        }
    }
    cout << topsort();
}