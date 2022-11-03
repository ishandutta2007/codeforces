//
//  main.cpp
//  c
//
//  Created by  on 16/3/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;

const int maxn=200000+5;
int a[maxn];
int b[maxn];
int que[maxn];
int t[maxn],r[maxn];
int rear=0;

void inque(int i){
    while(rear>=1&&r[i]>=r[que[rear]])
        rear--;
    //if(rear>=1&&t[que[rear]]==t[i]) return;
    que[++rear]=i;
}

bool cmp(int a,int b){
    return a>b;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    //int rear=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(que,0,sizeof(que));
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t[i],&r[i]);
        inque(i);
    }
    r[m+1]=0;
    que[++rear]=m+1;
    sort(a+1,a+r[que[1]]+1);
    int head=1,end=r[que[1]];
    //printf("%d%d%d\n",que[1],que[2],rear);
    for(int i=1;i<=rear;i++){
        if(r[que[i]]==0) break;
        if(t[que[i]]==1){
            for(int j=r[que[i]];j>r[que[i+1]];j--){
                b[j]=a[end];
                end--;
                //printf("%d ",b[j]);
            }
        }else{
            for(int j=r[que[i]];j>r[que[i+1]];j--){
                b[j]=a[head];
                head++;
               // printf("%d ",b[j]);
            }
        }
    }
    for(int i=1;i<=r[que[1]];i++){
        a[i]=b[i];
    }
    for(int i=1;i<=n;i++){
        printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}