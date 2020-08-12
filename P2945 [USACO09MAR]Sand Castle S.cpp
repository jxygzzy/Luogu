/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-12 10:39:31
 * @LastEditTime: 2020-08-12 10:43:36
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2945 [USACO09MAR]Sand Castle S.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 25550

using namespace std;

int a[maxn], b[maxn];
int n, x, y, ans;

int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
            ans += (a[i] - b[i]) * y;
        else
            ans += (b[i] - a[i]) * x;
    }
    cout << ans;
}