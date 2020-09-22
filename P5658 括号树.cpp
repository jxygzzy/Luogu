#include <iostream>
#include <algorithm>
#define maxn 500005
#define ll long long

using namespace std;

int n;
ll fa[maxn], f[maxn], ans, last[maxn], line[maxn];
char w[maxn];

int main()
{
    cin >> n;
    cin >> w + 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
    }
    for (int u = 1; u <= n; u++)
    {
        int x = fa[u];
        f[u] = f[x];
        last[u] = last[x];
        if (w[u] == '(')
        {
            last[u] = u;
        }
        else if (w[u] == ')' && last[u])
        {
            line[u] = line[fa[last[u]]] + 1;
            last[u] = last[fa[last[u]]];
            f[u] += line[u];
        }
        ans ^= u * f[u];
    }
    cout << ans;
    return 0;
}
