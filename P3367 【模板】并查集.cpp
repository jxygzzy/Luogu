/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-04-18 20:30:57
 * @LastEditTime: 2020-07-25 10:56:09
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3367 【模板】并查集.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>

using namespace std;
struct node
{
    int parent;
    int cnt;
    int value;
} Set[10005];
int n, m;
int z, x, y;
int Find(int x)
{
    int y = x;
    while (Set[y].parent != y)
        y = Set[y].parent;
    while (x != y)
    {
        int temp = Set[x].parent;
        Set[x].parent = y;
        x = temp;
    }
    return y;
}
void Union(int x, int y)
{
    x = Find(x), y = Find(y);
    if (x == y)
        return;
    if (Set[x].cnt > Set[y].cnt)
    {
        Set[y].parent = x;
        Set[x].cnt += Set[y].cnt;
    }
    else
    {
        Set[x].parent = y;
        Set[y].cnt += Set[x].cnt;
    }
}
void Init(int cnt)
{
    for (int i = 1; i <= cnt; i++)
    {
        Set[i].parent = i;
        Set[i].cnt = 1;
        Set[i].value = 0;
    }
}

int main()
{
    cin >> n >> m;
    Init(n);
    while (m--)
    {
        cin >> z >> x >> y;
        if (z == 1)
            Union(x, y);
        if (z == 2)
        {
            if (Find(x) == Find(y))
                cout << 'Y';
            else
                cout << 'N';
            cout << endl;
        }
    }
    return 0;
}