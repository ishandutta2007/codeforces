//
//  main.cpp
//  B
//
//  Created by  on 16/2/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
const int maxn=1e5+5;

struct point{
    int x,l,r;
}p[1000005];

int a[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    memset(p,0,sizeof(p));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[a[i]].x++;
        if(p[a[i]].l==0) p[a[i]].l=i;
        p[a[i]].r=i;
    }
    int ans=0,ansl=0,ansr=0;
    for(int i=1;i<=1000000;i++){
        if(p[i].x>ans){
            ans=p[i].x;
            ansl=p[i].l;
            ansr=p[i].r;
        }else if(p[i].x==ans){
            if(p[i].r-p[i].l<ansr-ansl){
                ansr=p[i].r;
                ansl=p[i].l;
            }
        }
    }
    printf("%d %d\n",ansl,ansr);
    return 0;
}