/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-03 12:45:18
 * @LastEditTime: 2020-08-03 14:41:19
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1575 正误问题.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> s;
stack<int> num;

void check()
{
    if (num.size() < 2)
    {
        cout << "error";
        exit(0);
    }
}

void doexpr()
{
    int a, b;
    if (s.top() == 1) //or
    {
        check();
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a || b);
    }
    if (s.top() == 2) //and
    {
        check();
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a && b);
    }
    if (s.top() == 3) //not
    {
        if (num.empty())
        {
            cout << "error";
            exit(0);
        }
        a = num.top();
        num.pop();
        num.push(!a);
    }
    s.pop();
}

int main()
{
    string in;
    while (cin >> in)
    {
        if (in == "true")
        {
            num.push(1);
        }
        if (in == "false")
        {
            num.push(0);
        }
        if (in == "not")
        {
            s.push(3);
        }
        if (in == "and")
        {
            while (!s.empty() && s.top() > 1)
                doexpr();
            s.push(2);
        }
        if (in == "or")
        {
            while (!s.empty())
                doexpr();
            s.push(1);
        }
    }
    while (!s.empty())
    {
        doexpr();
    }
    if (num.size() == 1)
    {
        if (num.top() == 1)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
    else
    {
        cout << "error";
    }
    return 0;
}
