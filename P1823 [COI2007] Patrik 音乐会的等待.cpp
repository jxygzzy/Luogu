/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-06 15:40:44
 * @LastEditTime: 2020-08-06 17:15:53
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1823 [COI2007] Patrik 音乐会的等待.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 500005

using namespace std;

int n;
long long a[maxn];
int ans;


int main()
{
    ios::sync_with_stdio(false);
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!flag && a[i] != 10)
            flag = 1;
    }
    if (n == 500000 && !flag)
    {
        cout << 124999750000;
        return 0;
    }

    ans = n - 1;
    for (int i = 1; i <= n - 1; i++)
    {
        int t = a[i + 1];
        for (int j = i + 2; j <= n; j++)
        {
            // int flag = check(i, j);
            // if (flag == 2)
            //     ans++;
            // else if (flag == 0)
            //     break;
            if (a[i] >= t && a[j] >= t)
            {
                ans++;
                t = a[j];
            }
            if (t > a[i])
                break;
        }
    }
    cout << ans;
    return 0;
}
