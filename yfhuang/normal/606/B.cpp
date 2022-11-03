//
//  main.cpp
//  B
//
//  Created by  on 15/12/10.
//  Copyright  2015 . All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t,i,n,m,xx0,yy0,x,y,z;
char ss[100005];
int ans[100005];
int a[1000][1000];
int main() {
    int sum=0;
    cin>>n>>m>>x>>y;
    scanf("%s",ss);
    t=strlen(ss);
    sum=1;
    a[x][y]=1;
    ans[0]=1;
    for(i=0;i<t-1;i++)
    {
        xx0=x; yy0=y;
        if(ss[i]=='D') xx0=x+1;
        if (ss[i]=='U') xx0=x-1;
        if (ss[i]=='L') yy0=y-1;
        if (ss[i]=='R')  yy0=y+1;
        if (xx0>=1&&xx0<=n&&yy0>=1&&yy0<=m) {x=xx0;y=yy0;if(a[x][y]==0) {a[x][y]=1;ans[i+1]=1;sum++;} else ans[i+1]=0; }
        else ans[i+1]=0;
    }
    ans[t]=n*m-sum;
    for(i=0;i<t;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[t]);
}