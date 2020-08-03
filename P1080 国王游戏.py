# -*- coding: utf-8 -*-
# @Time    : 2020/8/3 15:17
# @Author  : P19Y0UN9
# @File    : P1080 国王游戏.py
# @Software: PyCharm
def cmp(data):
    return data[0]*data[1]

n=int(input())
k=input().split()
k1=int(k[0])
k2=int(k[1])#没啥用
a=[]
for i in range(1,n+1):
    s=input().split()
    a.append((int(s[0]),int(s[1])))#加入元组
a.sort(key=cmp)
ans=0
for data in a:
    if ans<(k1//data[1]):
        ans=k1//data[1]
    k1*=data[0]
print(ans)