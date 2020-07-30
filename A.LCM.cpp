/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 23:12:46
 * @LastEditTime: 2020-07-29 23:35:08
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\A.LCM.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t;
int l, r;
int x, y;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        int flag = 0;
        for (int i = l; i <= r/2; i++)
        {
            for (int j = r; j >= r/2; j--)
            {
                if (gcd(i, j) >= l && gcd(i, j) <= r)
                {
                    flag = 1;
                    cout << i << " " << j << endl;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (!flag)
            cout << -1 << " " << -1 << endl;
    }
}