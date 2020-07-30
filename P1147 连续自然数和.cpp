/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-28 10:33:52
 * @LastEditTime: 2020-07-28 10:51:22
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1147 连续自然数和.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;
int m;
int sum;
int i,j;

int main()
{

    cin >> m;
    for ( i = 1; i <= m / 2; i++)
    {
        sum = 0;
        for ( j = i ; j < m; j++)
        {
            sum += j;
            if (sum >= m)
                break;
        }
        if (sum == m)
            cout << i << " " << j << endl;
    }
}
