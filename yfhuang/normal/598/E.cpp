//
//  main.cpp
//  E
//
//  Created by  on 15/11/14.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=1<<29;
int sum[33][33][55];
int solve(int w,int h,int ned){
    if(w*h==ned) return 0;
    int &ans=sum[w][h][ned];
    if(ans!=-1) return ans;
    ans=INF;
    for(int nw=1;nw<w;nw++){
        if(nw*h>=ned) ans=min(ans,solve(nw,h,ned)+h*h);
        else ans=min(ans,solve(w-nw,h,ned-nw*h)+h*h);
    }
    for(int nh=1;nh<h;nh++){
        if(nh*w>=ned) ans=min(ans,solve(w,nh,ned)+w*w);
        else ans=min(ans,solve(w,h-nh,ned-nh*w)+w*w);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int t;
    int n,m,k;
    scanf("%d",&t);
    memset(sum,-1,sizeof(sum));
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",solve(n,m,k));
    }
    return 0;
}