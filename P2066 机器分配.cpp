/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-25 11:01:02
 * @LastEditTime: 2020-07-25 12:01:18
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 总公司拥有高效设备M台，准备分给下属的N个分公司。
 * 各分公司若获得这些设备，可以为国家提供一定的盈利。
 * 问：如何分配这M台设备才能使国家得到的盈利最大？求出最大盈利值。
 * 其中M≤15，N≤10。分配原则：每个公司有权获得任意数目的设备，但总台数不超过设备数M。
 * 输入格式
 * 第一行有两个数，第一个数是分公司数N，第二个数是设备台数M。
 * 接下来是一个N*M的矩阵，表明了第 I个公司分配 J台机器的盈利。
 * 输出格式
 * 第1行为最大盈利值
 * 第2到第n为第i分公司分x台
 * P.S.要求答案的字典序最小
 * @FilePath: \Luogu\P2066 机器分配.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 20

using namespace std;

int ans[maxn][maxn];
int v[maxn][maxn];
int pre[maxn][maxn];
int n, m;
int maxl;

void show(int i,int j)
{
    if(i==0) return;
    for(int k=0;k<=j;k++)
        if(maxl==ans[i-1][k]+v[i][j-k])
        {
            maxl=ans[i-1][k];
            show(i-1,k);
            cout<<i<<" "<<j-k<<endl;
            break;
        }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            maxl=0;
            for(int k=0;k<=j;k++){
                if(maxl<ans[i-1][k]+v[i][j-k]){
                    maxl=ans[i-1][k]+v[i][j-k];
                    ans[i][j]=ans[i-1][k]+v[i][j-k];
                }
            }
        }
    }
    cout<<ans[n][m]<<endl;
    show(n,m);
}

