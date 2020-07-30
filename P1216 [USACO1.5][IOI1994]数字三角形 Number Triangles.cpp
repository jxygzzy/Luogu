#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int f[1005][1005];
int n;
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    f[1][1]=a[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
            ans=max(ans,f[i][j]);
        }       
    cout<<ans;
    return 0;
}