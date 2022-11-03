//
//  main.cpp
//  B
//
//  Created by  on 16/1/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

const int maxn=55;

int a[maxn][maxn];

struct node{
    int p,id;
}b[maxn];

int c[maxn];

bool cmp(node a,node b){
    return a.p<b.p;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
        for(int j=2;j<=n;j++){
            a[i][1]+=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        b[i].p=a[i][1];
        b[i].id=i;
    }
    sort(b+1,b+1+n,cmp);
    int sum=0;
    memset(c,0,sizeof(c));
    for(int i=1;i<n;i++){
        c[b[i].id]=(b[i].p-sum)/(n-i);
        sum+=c[b[i].id];
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0) c[i]=n;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",c[i]);
    return 0;
}