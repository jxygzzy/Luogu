/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-30 11:22:05
 * @LastEditTime: 2020-07-30 15:18:17
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\CF910C Minimum Sum.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string str[1005];
struct node
{
    int num, flag, w;
} word[11]; //记录下标可通过下标找到字母与str[i][j]-'a'+1相等，是否为首字母，字母的权重，用于排序

bool cmp(node a, node b)
{
    return a.w > b.w;
}

bool visit[11];
int p[11]; //从a开始的字母代表的数字
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        word[i].num = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        word[str[i][0] - 'a' + 1].flag = 1; //首字母标记
        for (int j = 0; j < str[i].size(); j++)
        {
            word[str[i][j] - 'a' + 1].w += pow(10, str[i].size() - j);
        }
    }
    sort(word + 1, word + 11, cmp);
    for (int i = 1; i <= 10; i++)
    {
        if (word[i].flag)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (!visit[j])
                {
                    visit[j] = 1;
                    p[word[i].num] = j;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j <= 9; j++)
            {
                if (!visit[j])
                {
                    visit[j] = 1;
                    p[word[i].num] = j;
                    break;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<str[i].size();j++){
            cnt=cnt*10+p[str[i][j]-'a'+1];
        }
        ans+=cnt;
    }
    cout<<ans;
}
