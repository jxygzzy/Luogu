/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-12 10:20:18
 * @LastEditTime: 2020-08-12 10:31:57
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5117 [USACO18DEC]The Bucket List B.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxt 1010

using namespace std;

int s, t, b;

int n;
int p[maxt];
int ans, now;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> t >> b;
        p[s] += b;
        p[t + 1] -= b;
    }
    for (int i = 0; i <= maxt; i++)
    {
        now += p[i];
        ans = max(now, ans);
    }
    cout << ans;
}
