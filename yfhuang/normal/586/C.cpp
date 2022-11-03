//
//  main.cpp
//  C
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N=4005;

int n;

int v[N],d[N],p[N];
bool vis[N];
bool a[N];
int q[N];

int main(int argc, const char * argv[]) {
    cin>>n;
    memset(v,0,sizeof(v));
    memset(d,0,sizeof(d));
    memset(p,0,sizeof(p));
    memset(a,false,sizeof(a));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&v[i],&d[i],&p[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        a[i]=true;
        cnt++;
        int c=0;
        int left=0,right=0;
        for(int j=i+1;c<=v[i]&&j<=n;j++){
            if(vis[j]) continue;
            p[j]-=v[i]-c;
            c++;
            if(p[j]<0){
                vis[j]=true;
                q[++right]=j;
            }
        }
        while(left<right){
            left++;
            for(int k=q[left]+1;k<=n;k++){
                if(vis[k]) continue;
                p[k]-=d[q[left]];
                if(p[k]<0){
                    vis[k]=true;
                    q[++right]=k;
                }
            }
        }
        
    }
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)
        if(a[i])
            printf("%d ",i);
    return 0;
}