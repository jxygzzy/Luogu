/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 23:38:46
 * @LastEditTime: 2020-07-30 00:03:31
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\B.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 100005

using namespace std;
int a[maxn];
int b[maxn];
int t, n, k, z;
int sum;

int main()
{
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n >> k >> z;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b+1, b+1 + n);
        int j = 1;
        sum+=a[1];
        for (int i = 2; i <= k + 1; i++)
        {
            sum += a[i];
            if (z > 0&&check())
            {
                sum += a[i+1];
                j++;
                z--;
            }
        }
        cout << sum << endl;
    }
}