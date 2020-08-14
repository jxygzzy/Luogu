/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-14 11:24:48
 * @LastEditTime: 2020-08-14 11:39:20
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P6155 修改.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;
const long long MOD = 2e64;

int n;
int a[1000005];
int b[1000005];
long long ans;

bool check(int end)
{
    for (int i = 1; i < end; i++)
    {
        if (a[i] == a[end])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n, greater<int>());
    for (int i = 2; i <= n; i++)
    {
        if (!check(i))
        {
            ans += (b[i] * (a[i - 1] + 1 - a[i]))%MOD;
            a[i] = a[i - 1] + 1;
        }
    }
    cout << ans;
}
