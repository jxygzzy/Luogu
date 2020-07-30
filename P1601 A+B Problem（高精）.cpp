#include <iostream>
#include <string>

using namespace std;

string str1, str2;

string add(string str1, string str2)
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = "0" + str1;
    }
    else
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = "0" + str2;
    }
    len1 = str1.length();
    int temp = 0;
    int carry = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        temp = str1[i] - '0' + str2[i] - '0' + carry;
        temp = temp % 10;
        carry = temp / 10;
        str = char(temp + '0') + str;
    }
    if (carry != 0)
        str = char(carry + '0') + str;
    return str;
}

int main()
{
    string ans;
    cin >> str1 >> str2;
    ans = add(str1, str2);
    cout << ans << endl;
    return 0;
}