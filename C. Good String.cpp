/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 22:39:26
 * @LastEditTime: 2020-07-29 23:08:23
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\C. Good String.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <string>
#include <iostream>

using namespace std;

int t;
string in;
int num;
int maxnum;
string ok;

int fun(string str, string sub)
{
    int num = 0;
    size_t len = sub.length();
    if (len == 0)
        len = 1; //应付空子串调用
    for (size_t i = 0; (i = str.find(sub, i)) != string::npos; num++, i += len)
        ;
    return num;
}

int main()
{
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        cin >> in;
        if (in[0] == in[in.size() - 2] && in[1] == in[in.size() - 1])
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < in.size(); i++)
        {
            for (int j = i + 1; j < in.size(); j++)
            {
                int num = fun(in, in.substr(i, j));
                if (maxnum < num)
                {
                    maxnum = num;
                    ok = in.substr(i, j);
                }
            }
        }
        cout << in.size() - maxnum * ok.size() - 1 << endl;
    }
}