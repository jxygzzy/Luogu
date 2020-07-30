/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 10:03:43
 * @LastEditTime: 2020-07-29 11:23:47
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P4047 [JSOI2010]部落划分.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

struct node
{
    int u, v;
    double w;
} a[1000000];

bool cmp(node a, node b)
{
    return a.w < b.w;
}

int f[10005];
int x[10005], y[10005];
int n, k;
int num;
int cnt;

int find(int x)
{
    if (f[x] == x)
        return x;
    else
        return f[x] = find(f[x]);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double w = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            a[++cnt].u = i;
            a[cnt].v = j;
            a[cnt].w = w;
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        int u = find(a[i].u);
        int v = find(a[i].v);
        if (u == v)
            continue;
        f[u] = v;
        num++;
        if (num == n - k + 1)
        {
            printf("%.2f", a[i].w);
            break;
        }
    }
}