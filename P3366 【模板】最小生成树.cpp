#include<bits/stdc++.h>
using namespace std;
struct node{
    int start;
    int to;
    int val;
}edge[200005];
int n,m,u,v,ans,cnt;
int f[5005];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(struct node a,struct node b){
    return a.val<b.val;
}
void kruskal(){
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++){
        u=find(edge[i].start);
        v=find(edge[i].to);
        if(u==v) continue;
        ans+=edge[i].val;
        f[v]=u;
        if(++cnt==n-1) break;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<m;i++)
        cin>>edge[i].start>>edge[i].to>>edge[i].val;
    kruskal();
    if(cnt==n-1) cout<<ans;
    else cout<<"orz";
    return 0;
}