#include <bits/stdc++.h>

using namespace std;

int a[500005];
int t[500005];
long long cnt = 0;
int temp;
int i, j;

void MergeSort(int l, int r)
{
    if (r > l + 1)
    {
        int mid = (l + r) / 2;
        MergeSort(l, mid);
        MergeSort(mid, r);
        temp = l;
        for (i = l, j = mid; i < mid && j < r;)
        {
            if (a[i] > a[j])
            {
                t[temp++] = a[j++];
                cnt += (long long)mid - i;
            }
            else
                t[temp++] = a[i++];
        }
        if (j < r)
            for (; j < r; j++)
                t[temp++] = a[j];
        else if (i < mid)
            for (; i < mid; i++)
                t[temp++] = a[i];
        for (i = l; i < r; i++)
            a[i] = t[i];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(0, n);
    cout << cnt;
    return 0;
}