#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct node{
    int x,y;
}c[maxn];
char fz[maxn][maxn];
char stand[]="yizhong";
int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int visit[maxn][maxn]={0};
void dfs(int x,int y,node c[],int k,int cot){
    if(cot==7)
        for(int i=0;i<7;i++)
            visit[c[i].x][c[i].y]=1;
    else{
        c[cot].x=x;c[cot].y=y;
        int dx=x+dir[k][0];
        int dy=y+dir[k][1];
        if(cot==6||fz[dx][dy]==stand[cot+1])    
            dfs(dx,dy,c,k,cot+1);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%s",fz[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fz[i][j]=='y'){
                for(int k=0;k<8;k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(fz[x][y]=='i')
                        dfs(i,j,c,k,0);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j])
                printf("%c",fz[i][j]);
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}
