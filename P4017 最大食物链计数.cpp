/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-06 10:30:15
 * @LastEditTime: 2020-08-06 11:08:42
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 *
 * @FilePath: \Luogu\P4017 最大食物链计数.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define MOD 80112002
#define maxm 500005
#define maxn 5005

using namespace std;

int n, m;

struct node
{
    int to, next;
} e[maxm];
int head[maxn];
int cnt;
int in[maxn];
int out[maxn];
int ans;
int s[maxn];

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int x)
{
    if (out[x] == 0)
    {
        return 1;
    }
    if (s[x])
        return s[x];
    int sum = 0;
    for (int i = head[x]; i; i = e[i].next)
    {
        sum = (sum + dfs(e[i].to)) % MOD;
    }
    return s[x] = sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        add(a, b);
        out[a]++;
        in[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            ans =(ans+dfs(i))%MOD;
        }
    }
    cout << ans;
}