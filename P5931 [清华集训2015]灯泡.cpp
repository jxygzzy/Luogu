/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-28 11:14:36
 * @LastEditTime: 2020-07-28 12:48:42
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5931 [清华集训2015]灯泡.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <stdio.h>
#include <algorithm>
#define eps 1e-10

//1.d=x+(D*h-x*H)/(D-x)
//2.d=h*D/H  边界

double H, h, D;

double f(double x)
{
    return x + (D * h - x * H) / (D - x);
}

int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf", &H, &h, &D);
        double l = 0, r = h / H * D;
        while (r - l > eps)
        {
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            if (f(mid1) > f(mid2))
                r = mid2;
            else
                l = mid1;
        }
        printf("%.3f\n",f(l));
    }
}
