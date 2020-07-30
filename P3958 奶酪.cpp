#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[1001];//并查集
int find(int x){
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}
ll dis(ll x,ll y,ll z,ll x1,ll y1,ll z1){
    return (x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1);
}
ll x[100001],y[100001],z[100001];
int f1[100001];//顶面洞口序号
int f2[100001];//底面洞口序号
int t,n;
ll r,h;
int main(){
    //freopen("a.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>h>>r;
        int cot1=0;//顶面洞口个数
        int cot2=0;//底面洞口个数
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i]>>z[i];
            if(z[i]+r>=h){
                cot1++;
                f1[cot1]=i;
            }
            if(z[i]-r<=0){
                cot2++;
                f2[cot2]=i;
            }
            for(int j=1;j<=i;j++){
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])>4*r*r) continue;
                if(dis(x[i],y[i],z[i],x[j],y[j],z[j])<=4*r*r){
                    int a=find(i);
                    int b=find(j);
                    if(a!=b) f[a]=b;
                }
            }
        }
        int flag=0;
        for(int i=1;i<=cot1;i++){
            for(int j=1;j<=cot2;j++){
                if( find(f1[i])==find(f2[j]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
