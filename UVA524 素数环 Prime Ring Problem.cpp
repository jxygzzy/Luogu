/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int cnt=0;
    while(cin>>n&&n!=EOF){
        cnt++;
        if(cnt>=2) printf("\n");
        printf("Case %d:\n",cnt);
        int A[50],isp[50]={0};
        isp[2]=isp[3]=isp[5]=isp[7]=isp[11]=isp[13]=isp[17]=isp[19]=isp[23]=isp[29]=isp[31]=1;
        for(int i=0;i<n;i++)    A[i]=i+1;
        do{
            int ok=1;
            for(int i=0;i<n;i++)
                if(!isp[A[i]+A[(i+1)%n]]){
                    ok=0;
                    break;
                }
            if(ok){
                printf("%d",A[0]);
                for(int i=1;i<n-1;i++)
                    printf(" %d",A[i]);
                printf("\n");
            }
        }while(next_permutation(A+1,A+n));//next_permutation时间复杂度为o(n!),超时严重。
    }
    return 0;
}*/
#include<bits/stdc++.h>//搜索：回溯法
using namespace std;
int n,A[50],cnt=1;
int isp[50];
bool book[50];
void dfs(int x){
    if(x==n&&isp[A[n-1]+A[0]]){
        for(int i=0;i<n-1;i++)
            cout<<A[i]<<" ";
        cout<<A[n-1]<<endl;
        return;
    }
    for(int i=2;i<=n;i++){
        if(!book[i]&&isp[i+A[x-1]]){
            A[x]=i;
            book[i]=1;
            dfs(x+1);
            book[i]=0;
        }
    }
}
int main(){
    isp[2]=isp[3]=isp[5]=isp[7]=isp[11]=isp[13]=isp[17]=isp[19]=isp[23]=isp[29]=isp[31]=1;
    while(cin>>n&&n!=EOF){
        if(cnt>1) cout<<endl;
        cout<<"Case "<<cnt<<":"<<endl;
        cnt++;
        A[0]=1;
        book[1]=1;
        dfs(1);
        memset(book,false,sizeof(book));
    }
    return 0;
}
