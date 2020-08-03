/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-03 10:25:15
 * @LastEditTime: 2020-08-03 11:17:54
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1873 砍树.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 1000010
using namespace std;

ll n, m;
ll a[maxn];
ll ans;
ll l=maxn*2, r;
ll mid;
ll sum;

void check(int x)
{
    sum=0;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] > x)
        {
            sum += a[i] - x;
        } 
    }
}

void find()
{ 
    while (l <= r)
    {
        mid = (l + r) / 2;
        check(mid);
        if (sum>=m)
        {
            l = mid + 1;
        }
        if (sum<m)
        {
            r = mid - 1;
        }
    }
    ans=l-1;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
        l = min(l, a[i]);
    }
    find();
    cout << ans;
    return 0;
}
