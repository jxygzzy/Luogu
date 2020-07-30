/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-28 10:52:38
 * @LastEditTime: 2020-07-28 11:13:43
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3382 【模板】三分法.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#define eps 1e-10

using namespace std;

int n;
double a[14];
double l, r, mid;
double x;

double f(double x) //秦九韶算法求n次多项式
{
    double u[20];
    u[n] = a[n];
    for (int i = n - 1; i >= 0; --i)
        u[i] = u[i + 1] * x + a[i];
    return u[0];
}

double check(double x) //求导
{
    double dx = eps;
    double dy = f(x + dx) - f(x);
    return dy / dx;
}

int main()
{
    cin >> n >> l >> r;
    for (int i = n; i >= 0; i--)
        cin >> a[i];
    mid = (l + r) / 2;
    while (l < r - eps)
    {
        if(check(mid)>0) l=mid;
        else r=mid;
        mid=(l+r)/2;
    }
    printf("%.5f",mid);
    
}
