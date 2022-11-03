//
//  main.cpp
//  B
//
//  Created by  on 16/3/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
const int maxn=1e5+5;

int a[maxn];
bool vis1[maxn];
bool vis2[maxn];
int b[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(vis1,false,sizeof(vis1));
    for(int i=1;i<=n;i++){
        if(a[i]<=n&&a[i]>=1) vis1[a[i]]=true;
    }
    memset(vis2,false,sizeof(vis2));
    int front=1;
    for(int i=1;i<=n;i++){
        if(vis1[a[i]]&&!vis2[a[i]]){
            b[i]=a[i];
            vis2[a[i]]=true;
        }else{
            while(front<=n&&vis1[front]) front++;
            b[i]=front;
            vis1[front]=true;
            vis2[front]=true;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}