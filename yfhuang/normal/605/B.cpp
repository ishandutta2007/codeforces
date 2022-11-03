//
//  main.cpp
//  D
//
//  Created by  on 15/12/10.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;

const int maxn=1e5+10;
const int maxm=1e5+10;

struct edge{
    int cost,num;
    int vis;
}a[maxm];

struct E{
    int u,v,num;
}e[maxm];

int b[maxn];

bool cmp(edge a,edge b){
    if(a.cost!=b.cost)
        return a.cost<b.cost;
    else return a.vis>b.vis;
}

bool cmp2(E a,E b){
    return a.num<b.num;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d%d",&n,&m)==2){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a[i].cost,&a[i].vis);
            a[i].num=i;
        }
        sort(a+1,a+m+1,cmp);
        bool ok=true;
        int cnt=1;
        int preu=1;int prev=3;
        //int chosend=0;
        for(int i=1;i<=m;i++){
            if(a[i].vis==1){
                e[i].u=cnt;
                cnt++;
                e[i].v=cnt;
                e[i].num=a[i].num;
            }
            //if(i>cnt*(cnt-1)/2) { ok=false; break;}
            if(a[i].vis==0){
                if(prev>cnt) {ok=false;break;}
                e[i].u=preu;
                e[i].v=prev;
                e[i].num=a[i].num;
                if(preu<prev-2) preu++;
                else{
                    preu=1;
                    prev++;
                }
            }
        }
        if(!ok) printf("-1\n");
        else{
            sort(e+1,e+1+m,cmp2);
            for(int i=1;i<=m;i++){
                printf("%d %d\n",e[i].u,e[i].v);
            }
        }
    }
    return 0;
}