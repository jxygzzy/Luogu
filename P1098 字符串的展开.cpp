#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int p1, p2, p3;
string in, ans, temp;

bool is(int i)
{
    if ((isdigit(in[i - 1]) && isdigit(in[i + 1])) || (isalpha(in[i - 1]) && isalpha(in[i + 1])))
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> p1 >> p2 >> p3 >> in;
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == '-')
        {
            if (is(i) && in[i - 1] >= in[i + 1])
                continue;
            if (is(i))
            {
                for (int j = in [i - 1] + 1; j < in[i + 1]; j++)
                {
                    for (int k = 1; k <= p2; k++)
                    {
                        temp += j;
                    }
                }
                if (p1 == 2&&isalpha(temp[0]))
                {
                    for (int j = 0; j < temp.size(); j++)
                    {
                        temp[j] = temp[j]-'a'+'A';
                    }
                }
                if (p1 == 3)
                {
                    for (int j = 0; j < temp.size(); j++)
                    {
                        temp[j] = '*';
                    }
                }
                if (p3 == 2)
                {
                    string temp1;
                    for (int j = temp.size() - 1; j >= 0; j--)
                    {
                        temp1 += temp[j];
                    }
                    temp = temp1;
                }
                in.replace(i, 1, temp);
                temp = "";
            }
        }
    }
    cout << in;
}