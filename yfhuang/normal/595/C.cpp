//
//  main.cpp
//  C
//
//  Created by  on 15/11/9.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200000+10;
const int INF=0x3fffffff;
int x[maxn];
int n;

int main(int argc, const char * argv[]) {
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        sort(x+1,x+n+1);
        int ans=INF;
        for(int i=1;i<=n/2;i++){
            if(x[i+n/2]-x[i]<ans) ans=x[i+n/2]-x[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}