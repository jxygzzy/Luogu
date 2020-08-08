/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-07 09:56:54
 * @LastEditTime: 2020-08-07 10:18:40
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1149 火柴棒等式.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

int f[2222] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};//1111+1=1112 f[1112]=25,n<=24

int n;
int ans;

int main()
{
    cin >> n;
    for (int i = 10; i <= 2222; i++)
    {
        int j = i;
        while (j >= 1)
        {
            f[i] = f[i] + f[j % 10];
            j /= 10;
        }
    }
    for (int i = 0; i <= 1111; i++)
    {
        for (int j = 0; j <= 1111; j++)
        {
            if (f[i] + f[j] + f[i + j] + 4 == n)
                ans++;
        }
    }
    cout << ans;
}