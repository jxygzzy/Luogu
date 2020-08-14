/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-13 14:29:17
 * @LastEditTime: 2020-08-13 14:53:31
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5365 [SNOI2017]英雄联盟.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 1000000
using namespace std;

long long int k[maxn];
long long int c[maxn];
long long int dp[maxn];
long long int n, m, maxQ, ans;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        maxQ += c[i] * k[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = maxQ; j >= 0; j--)
        {
            for (int x = 0; x <= k[i] && x * c[i] <= j; x++)
            {
                dp[j] = max(dp[j], dp[j - x * c[i]] * x);
            }
        }
    }
    while (ans <= maxQ && dp[ans] < m)
    {
        ans++;
    }
    cout << ans;
    return 0;
}