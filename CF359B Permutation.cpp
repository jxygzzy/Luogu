#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        if (k > 0)
            cout << i * 2 << " " << i * 2 - 1 << " ";
        else
            cout << i * 2 - 1 << " " << i * 2 << " ";
    }
    return 0;
}