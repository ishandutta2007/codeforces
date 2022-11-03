//
//  main.cpp
//  C
//
//  Created by  on 16/2/5.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n,m;

const int maxn=505;

char str[maxn];

bool con[maxn][maxn];

int main(int argc, const char * argv[]) {
    memset(con,false,sizeof(con));
    memset(str,0,sizeof(str));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        con[v][u]=con[u][v]=true;
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!con[i][j]) flag=false;
        }
        if(flag) str[i]='b';
    }
    int i;
    for( i=1;i<=n;i++){
        if(str[i]==0) break;
    }
    if(i==n+1){
        printf("Yes\n%s\n",str+1);
    }else{
        str[i]='a';
        for(int j=1;j<=n;j++){
            if(str[j]==0){
                if(con[i][j]) str[j]='a';
                else str[j]='c';
            }
        }
        bool flag=true;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(k==j) continue;
                if(con[j][k] && str[j]!=str[k] && abs(str[j]-str[k])!=1)
                    flag=false;
                if(!con[j][k]&&(str[j]==str[k]||abs(str[j]-str[k])==1))
                    flag=false;
            }
        }
        if(flag) printf("Yes\n%s\n",str+1);
        else printf("No\n");
    }
    return 0;
}