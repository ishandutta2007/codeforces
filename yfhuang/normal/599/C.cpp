//
//  main.cpp
//  c
//
//  Created by  on 15/11/21.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int x[100000+16];

struct height{
    int h;
    int n;
    int rank;
}h[100000+16],h2[100000+16];

bool cmp(height a,height b){
    if(a.h!=b.h) return a.h<b.h;
    else return a.n<b.n;
}

int main(int argc, const char * argv[]) {
    int n;
    int h1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h1);
        h[i].h=h1;
        h[i].n=i;
        h2[i].h=h1;
        h2[i].n=i;
    }
    sort(h2+1,h2+n+1,cmp);
    for(int i=1;i<=n;i++){
        h[h2[i].n].rank=i;
    }
    //for(int i=1;i<=n;i++) cout<<h[i].rank;
    int minr=0,maxr=1,k=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        maxr=max(maxr,h[i].rank);
        k++;
        if(maxr-minr==k) {ans++;minr=i;maxr=i+1;k=0;}
    }
    cout<<ans<<endl;
    return 0;
}