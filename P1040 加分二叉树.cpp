/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-29 15:16:30
 * @LastEditTime: 2020-07-29 16:42:12
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 在中序遍历中，若确定一个点为根节点，那么这个点左侧的点一定为该根节点左子树上的节点，
 * 这个点右侧的点一定为该根节点右子树上的节点
 * 因此这个题的关键就是确定某一区间(子树)的根节点
 * 状态转移方程:dp[i][j]=max(dp[i][k−1]∗dp[k+1][j]+dp[k][k],dp[i][j])
 * @FilePath: \Luogu\P1040 加分二叉树.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 35

using namespace std;

long long dp[maxn][maxn];
int root[maxn][maxn];
int n;
void print_first(int l, int r)
{
    if (l > r)
        return;
    cout << root[l][r] << " ";
    print_first(l, root[l][r] - 1);
    print_first(root[l][r] + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][i];
        dp[i][i - 1] = 1; //左子树，初始无子叶，分值为1
        dp[i + 1][i] = 1; //右子树
        root[i][i] = i;
    }
    for (int i = n; i >= 1; i--)
    { //i从大到小，如果从小到大,k-1, k+1，k比i大，而dp[i][k-1], dp[k+1][j]还没有推出来，所以不能推出dp[i][j]
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                if (dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + dp[k][k])
                {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                    root[i][j] = k; //记录路径
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    print_first(1, n);
}