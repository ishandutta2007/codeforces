//
//  main.cpp
//  A
//
//  Created by  on 15/12/24.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=105;

int f[maxn],s[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    int maxx=m;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&f[i],&s[i]);
        maxx=max(maxx,f[i]+s[i]);
    }
    printf("%d\n",maxx);
    return 0;
}