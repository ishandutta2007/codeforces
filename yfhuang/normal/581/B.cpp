//
//  main.cpp
//  B
//
//  Created by  on 15/12/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+6;

int a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int maxh=0;
    memset(b,0,sizeof(b));
    for(int i=n;i>=1;i--){
        if(maxh>=a[i]) b[i]=maxh+1-a[i];
        maxh=max(maxh,a[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}