//
//  main.cpp
//  B
//
//  Created by  on 16/3/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n,b;

const int maxn = 200005;

struct event{
    long long t,d;
}E[maxn];

long long t[maxn];
long long ans[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d",&E[i].t,&E[i].d);
        t[i]=E[i].t;
    }
    long long in=false;
    long long inid=0;
    long long due=0;
    t[n+1]=1e18;
    queue <pair<long long,long long> > q;
    for(long long i=1;i<=n;i++){
        if(!in){//
            in=true;
            inid=i;
            due=E[i].t+E[i].d;
        }else{//
            if(q.size()<b){
                q.push(make_pair(E[i].d,i));
            }else{
                ans[i]=-1;
            }
        }
        while(due<=t[i+1]){
            ans[inid]=due;
            if(q.size()){
                due=due+q.front().first;inid=q.front().second;q.pop();
            }else{
                in=false;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%I64d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}