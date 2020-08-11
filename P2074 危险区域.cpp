/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-11 09:52:11
 * @LastEditTime: 2020-08-11 10:10:55
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2074 危险区域.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#define maxn 100005

using namespace std;

int n, m, k, t;
int x, y;
int ans, now;

int dfs(int x, int y)
{
    int sum = 0;
    for (int i = max(x - t,1); i <= min(x+t,n); i++)
    {
        for (int j = max(y-t,1); j <= min(y+t,m); j++)
        {
            if (sqrt((i - x) * (i - x) + (j - y) * (j - y)) <= t)
            {
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        now = dfs(x, y);
        if (ans < now)
        {
            ans = now;
        }
    }
    cout << ans;
    return 0;
}