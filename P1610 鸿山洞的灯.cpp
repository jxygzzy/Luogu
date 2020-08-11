/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-11 14:32:49
 * @LastEditTime: 2020-08-11 14:39:43
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1610 鸿山洞的灯.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;

int a[maxn];
int n, dist, ans;

int main()
{
    cin >> n >> dist;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i < n; i++)
    {
        if (a[i + 1] - a[i - 1] <= dist)
        {
            a[i] = a[i - 1];
            ans++;
        }
    }
    cout << ans;
}