#include <stdio.h>
#include <stack>
#define ll long long

using namespace std;

typedef pair<int, int> pii;
stack<pii> s;
ll ans;
int n;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        pii p = make_pair(x, 1);
        while (!s.empty() && x >= s.top().first)
        {
            if (x == s.top().first)
                p.second += s.top().second;
            ans += s.top().second;
            s.pop();
        }
        if (!s.empty())
            ans++;
        s.push(p);
    }
    printf("%lld\n", ans);
    return 0;
}