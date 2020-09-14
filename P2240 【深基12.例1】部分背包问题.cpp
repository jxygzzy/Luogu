#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 110

using namespace std;

struct node
{
    double m, v;
} b[maxn];
bool cmp(node a, node b)
{
    return (a.v / a.m) > (b.v / b.m);
}

int n;
double ans, t;

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].m >> b[i].v;
    }
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (b[i].m <= t)
        {
            t -= b[i].m;
            ans += b[i].v;
        }
        else
        {
            ans += t * b[i].v / b[i].m;
            break;
        }
    }
    printf("%.2lf", ans);
}
