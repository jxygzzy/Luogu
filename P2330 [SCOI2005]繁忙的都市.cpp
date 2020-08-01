/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-01 09:24:42
 * @LastEditTime: 2020-08-01 09:42:24
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2330 [SCOI2005]繁忙的都市.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int s, ans, cnt;
int f[100005];
struct node
{
    int u, v, w;
} e[100005];
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int find(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = find(f[x]);
}

void kruskal()
{
    for (int i = 1; i <= m; i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u == v)
            continue;
        s++;
        cnt++;
        f[u]=v;
        if (e[i].w > ans)
            ans = e[i].w;
        if (cnt == n - 1)
            break;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + 1 + m, cmp);
    kruskal();
    cout<<s<<' '<<ans;
    return 0;
}