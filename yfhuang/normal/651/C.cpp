//
//  main.cpp
//  C
//
//  Created by  on 16/3/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N=200005;

struct point{
    int x,y;
}p[N];

bool cmp1(point a,point b){
    if(a.x!=b.x)
    return a.x<b.x;
    else return a.y<b.y;
}

bool cmp2(point a,point b){
    if(a.y!=b.y)
        return a.y<b.y;
    else return a.x<b.x;
}

long long ans=0;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p+1,p+1+n,cmp1);
    long long num=0;
    for(int i=1;i<n;i++){
        int j=i;
        while(p[i+1].x==p[i].x&&p[i+1].y==p[i].y){
            i++;
            if(i==n) break;
        }
        num+=(long long)(i-j+1)*(long long)(i-j)/2;
    }
    
    for(int i=1;i<n;i++){
        int j=i;
        while(p[i+1].x==p[i].x){
            i++;
            if(i==n) break;
        }
        ans+=(long long)(i-j+1)*(long long)(i-j)/2;
    }
    sort(p+1,p+1+n,cmp2);
    for(int i=1;i<n;i++){
        int j=i;
        while(p[i+1].y==p[i].y){
            i++;
            if(i==n) break;
        }
        ans+=(long long)(i-j+1)*(long long)(i-j)/2;
    }
    cout<<ans-num<<endl;
    return 0;
}