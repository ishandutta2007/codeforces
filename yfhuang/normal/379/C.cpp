//
//  main.cpp
//  C
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=3e5+10;

struct user{
    int id,v,a;
}u[maxn];

int n;

bool cmp(user a,user b){
    return a.id<b.id;
}

bool cmp1(user a,user b){
    return a.a<b.a;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&u[i].a);
        u[i].id=i;
    }
    sort(u+1,u+1+n,cmp1);
    int cur=1;
    for(int i=1;i<=n;i++){
        if(cur>=u[i].a){
            u[i].v=cur;
            cur++;
        }
        else{
            u[i].v=u[i].a;
            cur=u[i].v+1;
        }
    }
    sort(u+1,u+1+n,cmp);
    for(int i=1;i<=n;i++)
        printf("%d ",u[i].v);
    return 0;
}