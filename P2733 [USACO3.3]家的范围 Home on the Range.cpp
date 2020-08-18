#include <iostream>
#include <algorithm>
#define maxn 255

using namespace std;

int f[maxn][maxn][maxn]; //边长，右下角坐标
int g[maxn][maxn];
int ans[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char temp[maxn];
        cin >> temp;
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = temp[j - 1] - '0';
            if (g[i][j])
                f[1][i][j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = i; k <= n; k++)
            {
                if (f[i - 1][j - 1][k] && f[i - 1][j][k - 1] && f[i - 1][j - 1][k - 1] && g[j][k])
                {
                    f[i][j][k] = 1;
                    ans[i]++;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (ans[i])
            cout << i << ' ' << ans[i] << endl;
    }
    return 0;
}
