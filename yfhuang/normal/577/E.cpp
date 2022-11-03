//
//  main.cpp
//  E
//
//  Created by  on 16/1/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+5;

struct point{
    int x,y,sum,id;
}p[maxn];

bool cmp(point a,point b){
    if(a.x/1000!=b.x/1000) return a.x/1000<b.x/1000;
    else{
        if(a.x/1000%2==0){
            return a.y<b.y;
        }
        else return a.y>b.y;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].sum=p[i].x+p[i].y;
        p[i].id=i;
    }
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++){
        printf("%d ",p[i].id);
    }
    return 0;
}