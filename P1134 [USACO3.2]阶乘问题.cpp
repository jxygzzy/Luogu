// #include <iostream>
// #include <algorithm>

// using namespace std;
// int n, ans = 1;
// int a[4] = {6, 8, 4, 2};

// int main()
// {
//     cin >> n;
//     while (n > 0)
//     {
//         for (int i = 1; i <= n % 10; i++)
//         {
//             if (i != 5)
//                 ans = ans * i % 10;
//         }
//         n = n / 5;
//         ans = ans * a[n % 4] % 10;
//     }
//     cout << ans;
// }
#include <iostream>
#include <algorithm>

using namespace std;
int n, ans = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i;
        while (ans % 10 == 0)
        {
            ans /= 10;
        }
        ans %= 1000000;
    }

    cout << ans % 10;
}