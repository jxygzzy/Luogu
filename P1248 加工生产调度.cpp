#include <iostream>
#include <algorithm>
#define maxn 1005

using namespace std;

int n, ans, path[maxn];
struct node
{
    int min, index;
} in[maxn];
bool cmp(node a, node b)
{
    return a.min < b.min;
}
int a[maxn], b[maxn], t[maxn];
int cf, cm, cs, cp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        in[i].index = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        in[i].min = min(a[i], b[i]);
    }
    sort(in + 1, in + 1 + n, cmp);
    cf = 0;
    cm = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (in[i].min == a[in[i].index])
        {
            path[++cf] = in[i].index;
        }
        else
        {
            path[--cm] = in[i].index;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = t[i - 1] + a[path[i]];
    }
    int sum = t[1] + b[path[1]];
    for (int i = 2; i <= n; i++)
    {
        sum = max(t[i], sum) + b[path[i]];
    }
    cout << sum << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << path[i] << ' ';
    }
    return 0;
}
