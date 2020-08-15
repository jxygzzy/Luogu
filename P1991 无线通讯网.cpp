#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#define maxn 100001

using namespace std;

int f[maxn];
int x[maxn], y[maxn];
struct node
{
    int u, v;
    double w;
} e[maxn * 100];

bool cmp(node a, node b)
{
    return a.w < b.w;
}

int s, p;
int cnt;
double ans;

int find(int x)
{
    if (x == f[x])
        return f[x];
    return f[x] = find(f[x]);
}
int main()
{
    cin >> s >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++)
        {
            e[++cnt].w = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            e[cnt].u = i;
            e[cnt].v = j;
        }
    }
    for (int i = 1; i <= p; i++)
    {
        f[i] = i;
    }
    sort(e + 1, e + 1 + cnt, cmp);
    int k = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int uu = find(e[i].u);
        int vv = find(e[i].v);
        if (uu == vv)
            continue;
        f[uu] = vv;
        ans = e[i].w;
        k++;
        if (k == p - s)
            break;
    }
    printf("%.2lf", ans);
    return 0;
}
