/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-12 10:59:57
 * @LastEditTime: 2020-08-12 19:18:49
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1470 [USACO2.3]最长前缀 Longest Prefix.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

set<string> o;
typedef set<string>::iterator it;
string s;

void BuidMatch(string pattern, int *match)
{
    int i, j;
    int m = pattern.length();
    match[0] = -1;
    for (j = 1; j <= m; j++)
    {
        i = match[j - 1];
        while (i >= 0 && pattern[i + 1] != pattern[j])
        {
            i = match[i];
        }
        if (pattern[i + 1] == pattern[j])
        {
            match[j] = i + 1;
        }
        else
        {
            match[j] = -1;
        }
    }
}

int KMP(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();
    int s, p, *macth;
    if (n < m)
        return -1;
    macth = (int *)malloc(sizeof(int) * m);
    BuidMatch(pattern, macth);
    s = p = 0;
    while (s < n && p < m)
    {
        if (str[s] == pattern[p])
        {
            s++;
            p++;
        }
        else if (p > 0)
        {
            p = macth[p - 1] + 1;
        }
        else
            s++;
    }
    return (p == m) ? (s - m) : -1;
}

int main()
{
    string in;
    while (cin >> in && in != ".")
    {
        o.insert(in);
    }
    cin >> s;
    int ans = 0;
    for (int j = 1; j < s.length(); j++)
    {
        string t = s.substr(0, j);
        for (it i = o.begin(); i != o.end(); i++)
        {
            if (KMP(t, *i) != -1)
            {
                ans = j;
                break;
            }
        }
    }
    cout << ans;
}