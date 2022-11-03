//
//  main.cpp
//  C
//
//  Created by  on 16/1/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Point{
    int x,y,id;
}p[100005];

bool cmp(Point a,Point b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}

bool b[100005];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p+1,p+1+n,cmp);
    memset(b,false,sizeof(b));
    bool flag=false;
    for(int i=1;i<n;i++){
        if(p[i].x==p[i+1].x){
            b[i]=true; flag=true;
        }
    }
    if(flag){
        int i;
        for( i=1;i<n;i++){
            if(p[i].x==p[i+1].x){
                break;
            }
        }
        if(i!=1){
            printf("%d %d %d\n",p[i-1].id,p[i].id,p[i+1].id);
        }else{
            while(p[i].x==p[i+1].x) i++;
            if(i!=n) printf("%d %d %d\n",p[i-1].id,p[i].id,p[i+1].id);
        }
    }
    else {
        for(int i=1;i<=n-2;i++){
            if((long long)(p[i].y-p[i+1].y)*(p[i+1].x-p[i+2].x)==(long long)(p[i+1].y-p[i+2].y)*(p[i].x-p[i+1].x)) continue;
            printf("%d %d %d\n",p[i].id,p[i+1].id,p[i+2].id);
            return 0;
        }
    }
    return 0;
}