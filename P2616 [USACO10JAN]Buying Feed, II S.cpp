/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-25 12:04:48
 * @LastEditTime: 2020-07-25 13:05:15
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * FJ开车去买K份食物，如果他的车上有X份食物。每走一里就花费X元。
 * FJ的城市是一条线，总共E里路，有E+1个地方，标号0~E。 FJ从0开始走，到E结束（不能往回走），要买K份食物。 
 * 城里有N个商店，每个商店的位置是X_i（一个点上可能有多个商店），有F_i份食物，每份C_i元。 问到达E并买K份食物的最小花费
 * 
 * @FilePath: \Luogu\P2616 [USACO10JAN]Buying Feed, II S.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxe 355

using namespace std;

struct node
{
    int x, num, price;
} store[maxe];

int N, E, K;
int ans = 0;

bool cmp(node a, node b)
{
    return a.price < b.price;
}

int main()
{
    cin >> K >> E >> N;
    int x, y, z;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> z;
        store[i].x = x;
        store[i].num = y;
        store[i].price = E - x + z;
    }
    sort(store, store + N, cmp);
    int now = 0;
    for (int i = 0; i < N; i++)
    {
        if (now + store[i].num > K)
        {
            ans += store[i].price * (K - now);
            break;
        }
        else
        {
            ans += store[i].price * store[i].num;
            now += store[i].num;
        }
    }
    cout << ans;
}
