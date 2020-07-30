/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-24 09:20:03
 * @LastEditTime: 2020-07-24 09:53:26
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 一个 n×n 的网格图（标号由 1 开始）上有 m 个探测器，
 * 每个探测器有个探测半径 r ，问这 n×n 个点中有多少个点能被探测到。
 * 输入格式
 * 第一行 3 个整数 n,m,r ;
 * 接下来 m 行，每行两个整数 x,y表示第 i 个探测器的坐标。
 * 输出格式
 * 能被探测到的点的个数
 * 1≤n,m≤100
 * @FilePath: \Luogu\P3717 [AHOI2017初中组]cover.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <cmath>

using namespace std;
const int maxn = 1001;

int map[maxn][maxn] = {0};
double l;
int x, y;
int n, m, r;
int ans=0;

int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                l = sqrt((x - j) * (x - j) + (y - k) * (y - k));
                if (l <= r)
                    map[j][k] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]) ans++;
        }
    }
    cout<<ans;
}
