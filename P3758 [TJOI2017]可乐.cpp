#include <iostream>
#include <algorithm>
#define maxn 40
#define MOD 2017

using namespace std;

int n, m, ans;
int vis[maxn];

struct node
{
    int to, next;
} e[maxn * maxn];
int head[maxn * maxn];
int cnt;
void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int u)
{
    int sum = 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    ans = dfs(1) % MOD;
    cout << ans;
}
