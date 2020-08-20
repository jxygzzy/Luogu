#include <iostream>
#include <algorithm>
#include <string.h>
#define maxn 55

using namespace std;

int n;
char ans[5][9] = {{'*', '*', '*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*', '*', '*'}};
char in[maxn][maxn * 2];
char last[maxn * 2];
char temp;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    cin >> last;
    int len = strlen(last);
    for (int i = 0; i < n; i++)
    {
        if (strncmp(in[i], last, len) == 0)
        {
            temp = in[i][len];
            if (temp >= 'A' && temp <= 'E')
            {
                ans[0][temp - 'A' + 3] = temp;
            }
            if (temp >= 'F' && temp <= 'M')
            {
                ans[1][temp - 'F'] = temp;
            }
            if (temp >= 'N' && temp <= 'U')
            {
                ans[2][temp - 'N'] = temp;
            }
            if (temp >= 'V' && temp <= 'Z')
            {
                ans[3][temp - 'V'] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
