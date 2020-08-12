/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-12 10:03:44
 * @LastEditTime: 2020-08-12 10:06:38
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1244 [NOI2000]青蛙过河.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#define maxh 25

using namespace std;

int f[maxh];
int h, k;

int main()
{
    cin >> h >> k;
    f[0] = k + 1;
    int t = f[0] + k + 1;
    for (int i = 1; i <= h; i++)
    {
        f[i]=t;
        t+=f[i];
    }
    cout<<f[h];
}
