#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct node{
    ll w; //边权
    ll h; //路径长度
};
bool operator < (node a,node b) {
    if(a.w!=b.w) return a.w>b.w;
    else return a.h>b.h;
}priority_queue<node> q;
ll ans,n,k;
int main(){
    cin>>n>>k;
    ll w;
    for(int i=1;i<=n;i++){
        cin>>w;
        q.push((node){w,1});
    }
    while((q.size()-1)%(k-1)!=0)
        q.push((node){0,1});
    while(q.size()>=k){
        ll h=0,w=0;
        for(int i=1;i<=k;i++){
            node tmp=q.top();
            q.pop();
            h=max(h,tmp.h);
            w+=tmp.w;
        }
        ans+=w;
        q.push((node){w,h+1});
    }
    cout<<ans<<'\n'<<q.top().h-1<<endl;
    return 0;
}
