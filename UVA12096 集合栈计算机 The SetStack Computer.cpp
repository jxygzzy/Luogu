/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-23 10:23:05
 * @LastEditTime: 2020-07-23 13:43:55
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 对于一个以集合为元素的栈，初始时栈为空。 
 * 输入的命令有如下几种： 
 *  PUSH：将空集{}压栈 
 *  DUP：将栈顶元素复制一份压入栈中 
 *  UNION：先进行两次弹栈，将获得的集合A和B取并集，将结果压栈
 *  INTERSECT：先进行两次弹栈，将获得的集合A和B取交集，将结果压栈 
 *  ADD：先进行两次弹栈，将获得的集合A和B中，先出栈的集合（如A先）加入到后出栈的集合，将结果压栈
 *  输出每一步操作后栈顶集合的元素的个数。
 * @FilePath: \Luogu\UVA12096 集合栈计算机 The SetStack Computer.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
typedef set<int>::iterator it;
set<int> st, sA, sB; //临时存储变量

const int maxn = 2003;
const int mod = 100000007;

int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    string order;
    int n;
    cin >> n;
    while (n--)
    {
        stack<set<int>> s;
        int count;
        cin >> count;
        while (count--)
        {
            cin >> order;
            if (order == "PUSH")
            {
                st.clear();
                s.push(st);
                cout << "0" << endl;
            }
            if (order == "DUP")
            {
                st = s.top();
                s.push(st);
                cout << st.size() << endl;
                st.clear();
            }
            if (order == "UNION")
            {
                it i, j;
                sA = s.top();
                s.pop();
                sB = s.top();
                s.pop();
                i = sA.begin();
                j = sB.begin();
                while (i != sA.end() && j != sB.end())
                {
                    if (*i != *j)
                        st.insert(*i), st.insert(*j), ++j, ++i;
                    else
                        st.insert(*i), ++i, ++j;
                }
                while (i != sA.end())
                    st.insert(*i), ++i;
                while (j != sB.end())
                    st.insert(*j), ++j;
                cout << st.size() << endl;
                s.push(st);
                st.clear();
            }
            if (order == "INTERSECT")
            {
                it i, j;
                sA = s.top();
                s.pop();
                sB = s.top();
                s.pop();
                i = sA.begin();
                j = sB.begin();
                while (i != sA.end() && j != sB.end())
                {
                    if (*i < *j)
                        ++i;
                    else if (*i > *j)
                        ++j;
                    else
                        st.insert(*i), ++i, ++j;
                }
                cout << st.size() << endl;
                s.push(st);
                st.clear();
            }
            if (order == "ADD")
            {
                int i = 1;
                it iter;
                sA = s.top();
                s.pop();
                sB = s.top();
                s.pop();
                if (sA.size() == 0)
                    i = 0;
                else
                    for (iter = sA.begin(); iter != sA.end(); ++iter)
                        i = (i * maxn % mod + *iter + 11) % mod;
                if (sB.find(i) == sB.end())
                    sB.insert(i);
                s.push(sB);
                cout << sB.size() << endl;
                st.clear();
            }
        }
        cout << "***" << endl;
    }
}