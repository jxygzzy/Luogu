/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-10 10:28:00
 * @LastEditTime: 2020-08-10 10:58:26
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1033 自由落体.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double H, S1, V, L, K, n;

int main()
{
    cin >> H >> S1 >> V >> L >> K >> n;
    double t_l = sqrt(H / 5);
    double t_r = sqrt((H - K) / 5);
    int l = int(S1 - t_l * V);
    int r = int(S1 - t_r * V + L);
    // if (l - int(l) < 0.0001)
    //     l = int(l);
    if (l < 0)
        l = 0;
    // if (int(r + 1) - r < 0.0001)
    //     r = int(r + 1);
    if (r > n)
        r = n;
    cout << r - l;
}