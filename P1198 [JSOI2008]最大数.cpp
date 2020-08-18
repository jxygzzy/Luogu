#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5+5;
int d[N];
int sk[N];

int main()
{
    char s[2];
    int x, n, mod, t, len = 0, a = 0;
    cin >> n >> mod;
    int st = 0;
    while (n--)
    {
        cin >> s >> x;
        if (s[0] == 'A')
        {
            d[len] = (x + a) % mod;
            while (st > 0)
            {
                int temp = sk[st];
                if (d[temp] > d[len])
                    break;
                st--;
            }
            sk[++st] = len;
            len++;
        }
        else
        {
            int z = len - x;
            int l = 1;
            int r = st;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (sk[mid] < z)
                    l = mid + 1;
                else
                    r = mid;
            }
            a = d[sk[r]];
            cout << d[sk[r]] << endl;
        }
    }
    return 0;
}