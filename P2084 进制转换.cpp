/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-05 10:54:50
 * @LastEditTime: 2020-08-05 11:38:25
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2084 进制转换.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int m;
string n;
int i;
string ans;
char* temp=(char*)malloc(1000000);
int main()
{
    cin >> m >> n;
    for ( i = 0; i < n.size(); i++)
    {
        if(n[i]!='0')
        {
            sprintf(temp,"%c*%d^%d+",n[i],m,n.size()-i-1);
            ans+=temp;
        }    

        
    }
    if(ans[ans.size()-1]=='+')
        ans=ans.substr(0,ans.size()-1);
    cout<<ans;
}