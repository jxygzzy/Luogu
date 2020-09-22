#include <iostream>
#include <algorithm>
#define maxn 300005
#define ll long long

using namespace std;

int n, m, a[maxn], b[maxn];
ll ans;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    ans = (long long)a[1] * (m - 1) + (long long)b[1] * (n - 1); //最小的行和列
    int cnt_a = 2, cnt_b = 2;
    int line = 1, row = 1;
    while (cnt_a <= n && cnt_b <= m)
    {
        if (a[cnt_a] <= b[cnt_b])
            ans += (long long)a[cnt_a++] * (m - row), line++;
        else
            ans += (long long)b[cnt_b++] * (n - line), row++;
    }
    cout << ans;
    return 0;
}