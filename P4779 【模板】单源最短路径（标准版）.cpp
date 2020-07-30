#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
const int maxn=100010;
const int maxm=500010;
int n,m,s,cnt=0;
int dis[maxn],vis[maxn],h[maxn];
struct Node{
    int to,nt,dis;
}edge[maxm];
struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};
void add(int a,int to ,int dis){
    edge[++cnt].nt=h[a];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    h[a]=cnt;
}
void dijkstra(){
    priority_queue<node> q;
    dis[s]=0;
    q.push((node{0,s}));
    while(!q.empty()){
        node temp=q.top();
        q.pop();
        int u=temp.pos,d=temp.dis;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=h[u];i;i=edge[i].nt){
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].dis){
                dis[v]=dis[u]+edge[i].dis;
                if(!vis[v])
                    q.push((node){dis[v],v});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) dis[i]=INF;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<' ';
    return 0;
}