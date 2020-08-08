/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-08 12:17:52
 * @LastEditTime: 2020-08-08 12:37:28
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2820 局域网.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int from, to, val;
} e[1010];
bool cmp(node a, node b)
{
    return a.val < b.val;
}
int f[110];
int n, k;
int u, v, w;
int ans, cnt, sum;

int find(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = find(f[x]);
}

void kruskal()
{
    for (int i = 1; i <= k; i++)
    {
        int u = find(e[i].from);
        int v = find(e[i].to);
        if (u == v)
            continue;
        f[u] = v;
        ans += e[i].val;
        if (++cnt == n - 1)
            break;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= k; i++)
    {
        cin >> e[i].from >> e[i].to >> e[i].val;
        sum += e[i].val;
    }
    sort(e + 1, e + 1 + k, cmp);
    kruskal();
    cout << sum - ans;
}