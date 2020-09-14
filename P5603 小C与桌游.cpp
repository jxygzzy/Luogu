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
    int maxn=0,ans=0;
    
}