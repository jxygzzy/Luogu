/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-04-18 20:43:56
 * @LastEditTime: 2020-07-24 09:27:24
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1880 [NOI1995]石子合并.cpp
 * @居居 <jxygzzy@163.com>
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int INF=10000000;
int f1[300][300],f2[300][300];
int s[300],v[300];
int n;

inline int d(int i,int j) { return s[j]-s[i-1];}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i+n]=v[i];
    }
    for (int i=1;i<=n+n;i++) s[i]=s[i-1]+v[i];
    for(int p=1;p<=n;p++){
        for(int i=1,j=i+p;i<(n+n)&&j<(n+n);i++,j=i+p){
            f2[i][j]=INF;
            for(int k=i;k<j;k++){
                f1[i][j]=max(f1[i][j],f1[i][k]+f1[k+1][j]+d(i,j));
                f2[i][j]=min(f2[i][j],f2[i][k]+f2[k+1][j]+d(i,j));
            }
        }
    }
    int maxl=0,minl=INF;
    for(int i=1;i<=n;i++){
        maxl=max(maxl,f1[i][i+n-1]);
        minl=min(minl,f2[i][i+n-1]);
    }
    cout<<minl<<'\n'<<maxl;
}