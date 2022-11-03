//
//  main.cpp
//  B
//
//  Created by  on 16/1/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=105;

int c[maxn][maxn];

int a[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&c[i][j]);
        }
    }
    memset(a,0x3f3f3f3f,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i]=min(a[i],c[i][j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,a[i]);
    cout<<ans<<endl;
    return 0;
}