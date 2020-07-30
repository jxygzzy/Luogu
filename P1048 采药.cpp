#include<bits/stdc++.h>
using namespace std;
int w[105],v[105];
int f[1005];
int m,C;
int main(){
    cin>>C>>m;
    for(int i=1;i<=m;i++)
        cin>>w[i]>>v[i];
    f[0]=0;
     for(int i=1;i<=m;i++) 
    {
        for(int c=C;c>=0;c--) 
        {
            if(c>=w[i]) 
            {
                f[c]=max(f[c-w[i]]+v[i], f[c]);
            }
        }
    }
    cout<<f[C]; 
    return 0;
}