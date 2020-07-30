#include<bits/stdc++.h>
using namespace std;
int f[201][201];
int e[201];
int n,maxs;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>e[i];
        e[i+n]=e[i];
    }
    for(int p=1;p<n;p++){
        for(int i=1,j=i+p;i<n+n&&j<n+n;i++,j=i+p){
            for(int k=i;k<j;k++){
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+e[i]*e[k+1]*e[j+1]);
                maxs=max(maxs,f[i][j]);
            }
        }
    }
    cout<<maxs;
    return 0;
}