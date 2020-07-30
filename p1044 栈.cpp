/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-23 10:02:56
 * @LastEditTime: 2020-07-23 13:45:48
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\p1044 栈.cpp
 * @居居 <jxygzzy@163.com>
 */
#include<iostream>
#define maxn 20

using namespace std;

int ans[maxn][maxn];

int solve(int i,int j){
    if(ans[i][j]) return ans[i][j];//有值直接返回
    if(i==0) return 1;//序列无数据，只能出栈1种情况
    if(j==0) ans[i][j]+=solve(i-1,j+1);//只能进栈
    else{
        ans[i][j]+=solve(i,j-1);//直接出栈
        ans[i][j]+=solve(i-1,j+1);//先进栈后出栈
    }
    return ans[i][j];
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n,0);
}