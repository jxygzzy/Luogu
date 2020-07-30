#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
const int maxn=10005;
const int maxm=500005;
int n,m,s,cnt=0;
int dis[maxn],vis[maxn],h[maxn];
struct node{
    int to,nt,dis;
}edge[maxm];
void add(int a,int to ,int dis){
    edge[++cnt].nt=h[a];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    h[a]=cnt;
}
void spfa(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        dis[i]=INF;
        vis[i]=0;
    }
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=h[u];i;i=edge[i].nt){
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].dis){
                dis[v]=dis[u]+edge[i].dis;
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    spfa();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<' ';
    return 0;
}