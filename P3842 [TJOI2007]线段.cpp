#include <iostream>
#include <algorithm>
#define maxn 20005

using namespace std;
int n;
int f[maxn][2];
int l[maxn], r[maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    f[1][0] = 2 * r[1] - l[1] - 1;
    f[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][1] = min(f[i - 1][1] + abs(l[i] - r[i - 1]) + r[i] - l[i] + 1, f[i - 1][0] + abs(l[i] - l[i - 1]) + r[i] - l[i] + 1);
        f[i][0] = min(f[i - 1][1] + abs(r[i] - r[i - 1]) + r[i] - l[i] + 1, f[i - 1][0] + abs(r[i] - l[i - 1]) + r[i] - l[i] + 1);
    }
    cout << min(f[n][1] + n - r[n], f[n][0] + n - l[n]);
    return 0;
}
