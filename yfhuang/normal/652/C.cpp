//
//  main.cpp
//  C
//
//  Created by  on 16/3/26.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 3e5 + 5;

int p[maxn];

int Right[maxn];

int n,m;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        p[x]=i;
    }
    int l,r;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l,&r);
        Right[max(p[l],p[r])]=max(Right[max(p[l],p[r])],min(p[l],p[r]));
    }
    long long ans=0;
    for(int i=1,j=1;i<=n;i++){
        while(Right[j]<i&&j<=n) j++;
        ans+=(long long)j-i;
    }
    cout<<ans<<endl;
    return 0;
}