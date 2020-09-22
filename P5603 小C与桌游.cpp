#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 5e5 + 5;
int n, m;
queue<int> st;
priority_queue<int, vector<int>, greater<int>> s1;
priority_queue<int, vector<int>, less<int>> s2;
vector<int> g[N];
int in1[N], in2[N];

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        in1[v]++;
        in2[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!in1[i])
        {
            s1.push(i);
            s2.push(i);
        }
    }
    int maxn = 0, ans = 0;
    while (!s1.empty())
    {
        int x = s1.top();
        s1.pop();
        if (x > maxn)
            ans++;
        maxn = max(maxn, x);
        for (int i = 0; i < g[x].size(); i++)
        {
            int y = g[x][i];
            in1[y]--;
            if (!in1[y])
            {
                s1.push(y);
            }
        }
    }
    cout << ans << endl;
    maxn = 0;
    ans = 0;
    while (!s2.empty())
    {
        int x = s2.top();
        if (x > maxn)
            ans++;
        while (!s2.empty())
        {
            st.push(s2.top());
            s2.pop();
        }
        while (!st.empty())
        {
            int nx = st.front();
            st.pop();
            maxn = max(maxn, nx);
            for (int i = 0; i < g[nx].size(); i++)
            {
                int y = g[nx][i];
                in2[y]--;
                if (!in2[y])
                {
                    if (y > maxn)
                    {
                        s2.push(y);
                    }
                    else
                    {
                        st.push(y);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}