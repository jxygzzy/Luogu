#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define maxn 10005

using namespace std;

string in;
map<string, int> vis;
int n, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> in;
        sort(in.begin(), in.end());
        if (!vis[in])
        {
            ans++;
            vis[in]++;
        }
    }
    cout << ans;
    return 0;
}
