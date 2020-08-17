#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int from[27];
int to[27];

map<char, char> m;

string f, t, a, ans;

int main()
{
    cin >> f >> t >> a;
    if (f.size() < 26)
    {
        cout << "Failed";
        return 0;
    }
    for (int i = 0; i < f.size(); i++)
    {
        if (to[t[i] - 'A'] && !from[f[i] - 'A'])
        {
            cout << "Failed";
            return 0;
        }
        m[f[i]] = t[i];
        to[t[i] - 'A'] = 1;
        from[f[i] - 'A'] = 1;
    }
    if (m.size() < 26)
    {
        cout << "Failed";
        return 0;
    }
    for (int i = 0; i < a.size(); i++)
    {
        ans += m[a[i]];
    }
    cout << ans;
    return 0;
}