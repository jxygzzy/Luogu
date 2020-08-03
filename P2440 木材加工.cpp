/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-03 11:19:31
 * @LastEditTime: 2020-08-03 12:18:02
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2440 木材加工.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define ll long long
#define maxn 100010

using namespace std;

ll a[maxn];
ll ans;
ll n, k;
ll l, r, mid;

bool check(ll mid)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i] / mid;
    }
    return sum >= k;
}

void find()
{
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid < 1)
        {
            ans = 0;
            return;
        }
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    ans = l - 1;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    find();
    cout << ans;
}
