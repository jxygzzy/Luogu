#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[101];
int f[1001][1001];
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=b[i];j--){
            for(int k=x;k>=c[i];k--){
                f[j][k]=max(f[j][k],f[j-b[i]][k-c[i]]+a[i]);    
            }
        }
    }
    cout<<f[m][x];
    return 0;
}