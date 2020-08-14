/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-14 16:39:07
 * @LastEditTime: 2020-08-14 17:13:05
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2034 选择数字.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;
int sum[N];
int f[N]; 
int a[N];
int n, k;

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = max(0, i - k - 1); j < i; j++)
        {
            f[i] = max(f[i], f[j] + sum[i - 1] - sum[j]);
        }
    }

    cout << f[n + 1];
}