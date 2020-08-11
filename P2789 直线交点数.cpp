/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-05 13:20:23
 * @LastEditTime: 2020-08-09 19:59:53
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2789 直线交点数.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 30

using namespace std;

int n;
int ans;
int vis[maxn * maxn];

void dfs(int n, int l)
{
    if (n == 0 && !vis[l])
    { //当没有平行线的时候，标记交点数，答案加一
        ans++;
        vis[l] = 1;
        return;
    }
    //当分隔成n-i个平行线，交点数为n*(n-i) + l  l为以前的交点数
    //n-i条平行线与分割出来的i条线形成的交点数为(n-i)*i
    for (int i = n; i >=1; i--)
    {
        dfs(n - i, (n - i) * i + l);
    }
}

int main()
{
    cin >> n;
    dfs(n, 0); //n条平行线，0个交点
    cout << ans;
}