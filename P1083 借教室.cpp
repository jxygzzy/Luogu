/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-14 10:17:56
 * @LastEditTime: 2020-08-14 11:15:32
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1083 借教室.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 1000005

using namespace std;

int n, m;
int r[maxn];
int need[maxn];
int diff[maxn];
int d[maxn], s[maxn], t[maxn];
int ans;

bool check(int x)
{
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= x; i++)
    {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        need[i] = need[i - 1] + diff[i];
        if (need[i] > r[i])
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    if (check(m))
    {
        cout << 0;
        return 0;
    }
    int l = 1, r = m;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << -1 << '\n'
         << l;
    return 0;
}
