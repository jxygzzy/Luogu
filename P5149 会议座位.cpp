#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define maxn 100005

using namespace std;

map<string, int> m;
int n;
long long ans;
int a[maxn], b[maxn];
string s;

void mergesort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++], ans += mid - i + 1; //增加逆序对
    }

    while (i <= mid)
        b[k++] = a[i++];
    while (j <= right)
        b[k++] = a[j++];
    for (int i = left; i <= right; i++)
        a[i] = b[i];
}
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        m[s] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        a[m[s]] = i;
    }
    mergesort(1, n);
    cout << ans;
}