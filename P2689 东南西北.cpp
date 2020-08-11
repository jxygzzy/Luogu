/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-11 09:21:21
 * @LastEditTime: 2020-08-11 09:44:52
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2689 东南西北.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
using namespace std;

int x1, y1;
int x2, y2;
int n, ans;
char dir;
int flag;

int main()
{
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dir;
        if(flag) continue;
        if (dir == 'E' && x1 < x2)
        {
            x1++;
            ans++;
        }
        if (dir == 'S' && y1 > y2)
        {
            y1--;
            ans++;
        }
        if (dir == 'W' && x1 > x2)
        {
            x1--;
            ans++;
        }
        if (dir == 'N' && y1 < y2)
        {
            y1++;
            ans++;
        }
        if (x1 == x2 && y1 == y2)
        {
            flag=1;
        }
    }
    if (x1 == x2 && y1 == y2)
        cout << ans;
    else
        cout << -1;
}
