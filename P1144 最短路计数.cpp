#include<bits/stdc++.h>
using namespace std;
const int maxa=0x3fffffff;
const int maxn=1000010;
vector<int>G[maxn];
queue<int>q;
int inqueue[maxn],dis[maxn],ans[maxn];
int n,m,x,y;
void spfa(){
    for(int i=1;i<=n;i++) dis[i]=maxa;
    q.push(1);
    inqueue[1]=1;
    ans[1]=1;
    dis[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inqueue[u]=0;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                ans[v]=ans[u];
                if(!inqueue[v]){
                    q.push(v);
                    inqueue[v]=1;
                }
            }else if(dis[v]==dis[u]+1)
                ans[v]=(ans[v]+ans[u])%100003; 
        }
    }

}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    spfa();
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}