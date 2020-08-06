/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-06 11:09:36
 * @LastEditTime: 2020-08-06 14:48:29
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3915 树的分解.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 100005

using namespace std;

int t, n, k;
struct node
{
    int to, next;
} e[maxn * 2];
int head[maxn];
int cnt;
int f[maxn];
int ans;

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int x, int pre)
{
    f[x] = 1;
    for (int i = head[x]; i; i = e[i].next)
    {
        if (e[i].to != pre)
        {
            dfs(e[i].to, x);
            f[x] += f[e[i].to];
        }
    }
    if (f[x] == k)
    {
        ans++;
        f[x] = 0;
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        memset(head, 0, sizeof(head));
        cnt = ans = 0;
        cin >> n >> k;
        int u, v;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        if (n % k != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        dfs(1, 0);
        if (ans == n / k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
