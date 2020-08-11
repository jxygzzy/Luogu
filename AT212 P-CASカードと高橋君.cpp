/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-11 10:23:52
 * @LastEditTime: 2020-08-11 10:35:19
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\AT212 P-CASカードと高橋君.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

int x, y;
char w;
int g[10][10];
int ans[4];
// R : 右方向
// L : 左方向
// U : 上方向
// D : 下方向
// RU : 右上方向
// RD : 右下方向
// LU : 左上方向
// LD : 左下方向
int main()
{
    cin >> x >> y >> w;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (w == 'R')
        {
            ans[i] = g[x][y];
            x++;
            if (x == 9)
            {
                w = 'L';
            }
        }
    }
}