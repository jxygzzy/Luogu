/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-24 10:17:57
 * @LastEditTime: 2020-07-24 11:30:55
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2038 无线网络发射器选址.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#define maxn 129

using namespace std;

int graph[maxn][maxn];
int max_ans = 0;
int max_count = 0;
int d;
int n;
int x, y, k;

int main()
{
    cin >> d >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> k;
        graph[x][y] = k;
    }
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            int counts = 0;
            int x1, y1, x2, y2;
            if (i - d < 0)
                x1 = 0;
            else
                x1 = i - d;
            if (j - d < 0)
                y1 = 0;
            else
                y1 = j - d;
            if (i + d > 128)
                x2 = 128;
            else
                x2 = i + d;
            if (j + d > 128)
                y2 = 128;
            else
                y2 = j + d;
            for (int a = x1; a <= x2; a++)
            {
                for (int b = y1; b <= y2; b++)
                {
                    counts += graph[a][b];
                }
            }
            if (max_ans < counts)
            {
                max_count = 1;
                max_ans = counts;
            }
            else if (max_ans == counts)
                max_count++;
        }
    }
    cout << max_count << " " << max_ans;
}