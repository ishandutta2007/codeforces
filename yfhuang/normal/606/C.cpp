//
//  main.cpp
//  C1
//
//  Created by  on 15/12/10.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1e5+10;

int a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d",&n)==1){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int x;
        a[0]=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            a[x]=1;
            b[x]=1;
            if(a[x-1]==1) b[x]=b[x-1]+1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,b[i]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}