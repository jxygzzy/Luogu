/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-06 14:45:42
 * @LastEditTime: 2020-08-06 15:36:48
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1250 种树.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int b, e, t;
} dp[5005];
bool cmp(node a, node b)
{
    if (a.e < b.e || a.e == b.e && a.b > b.b)
        return true;
    else
        return false;
}
int n, h;
int ans;
int vis[5005 * 5005];

int main()
{
    cin >> n >> h;
    for (int i = 1; i <= h; i++)
    {
        cin >> dp[i].b >> dp[i].e >> dp[i].t;
    }
    sort(dp + 1, dp + 1 + h, cmp);
    for (int i = 1; i <= h; i++)
    {
        int k = 0;
        for (int j = dp[i].b; j <= dp[i].e; j++)
        {
            if (vis[j])
                k++;
        }
        if (k >= dp[i].t)
            continue;
        for (int j = dp[i].e; j >= dp[i].b; j--)
        {
            if (!vis[j])
            {
                vis[j] = 1;
                k++;
                ans++;
                if (k == dp[i].t)
                    break;
            }
        }
    }
    cout << ans;
}