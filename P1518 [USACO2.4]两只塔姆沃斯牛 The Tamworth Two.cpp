#include<bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};//N,E,S,W
const int dy[4]={0,1,0,-1};
int cx,cy,cd;
int fx,fy,fd;
int f[21][21],v[21][21][4][21][21][4];
void dfs(int cnt){
    if(cx==fx&&cy==fy){
        cout<<cnt<<endl;
        return;
    }
    if(v[fx][fy][fd][cx][cy][cd]){
        cout<<"0"<<endl;
        return;
    }
    v[fx][fy][fd][cx][cy][cd]=1;
    if(!f[cx+dx[cd]][cy+dy[cd]]) cd=(cd+1)%4;
    else cx=cx+dx[cd],cy=cy+dy[cd];
    if(!f[fx+dx[fd]][fy+dy[fd]]) fd=(fd+1)%4;
    else fx=fx+dx[fd],fy=fy+dy[fd];
    dfs(cnt+1);
}
int main()
{
    int i,j;char map[21];
    memset(f,0,sizeof(f));
    for(i=1;i<=10;i++)
    {
        scanf("%s",map+1);
        for(j=1;j<=10;j++)
        {
            if(map[j]=='.') f[i][j]=1;
            if(map[j]=='F') fx=i,fy=j,f[i][j]=1;
            if(map[j]=='C') cx=i,cy=j,f[i][j]=1;
        }
    }
    cd=fd=0;
    memset(v,0,sizeof(v)); 
    dfs(0);
    return 0;
}