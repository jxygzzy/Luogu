#include<bits/stdc++.h>
using namespace std;
int a[200],b[200],c[200],d[200];
int n,ans;
void dfs(int line){
    if(line>n){
        ans++;
        if(ans<=3){
            for(int i=1;i<=n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }else return;
    }
    for(int j=1;j<=n;j++){
        if(b[j]==0&&c[line+j]==0&&d[line-j+n]==0){
            a[line]=j;
            b[j]=1,c[line+j]=1,d[line-j+n]=1;
            dfs(line+1);
            b[j]=0,c[line+j]=0,d[line-j+n]=0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}