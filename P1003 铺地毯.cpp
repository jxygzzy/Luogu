/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-14 09:44:33
 * @LastEditTime: 2020-08-14 10:12:14
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1003 铺地毯.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxe 10001

using namespace std;
int e[maxe][5];
int n, x, y;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> e[i][j];
        }
    }
    cin >> x >> y;
    for (int i = n; i >= 1; i--)
    {
        if (e[i][0] <= x && (e[i][0] + e[i][2]) >= x && e[i][1] <= y && (e[i][1] + e[i][3]) >= y)
        {
            cout << i;
            break;
        }
        if (i == 1)
        {
            cout << -1;
        }
    }
    return 0;
}
