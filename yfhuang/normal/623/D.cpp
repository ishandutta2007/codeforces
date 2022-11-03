//
//  main.cpp
//  div1d
//
//  Created by  on 16/2/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
double p[105];
int cnt[105];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&p[i]);
        p[i]/=100;
    }
    double now=1.0;
    priority_queue<pair<double,int> >pq;
    for(int i=1;i<=n;i++){
        now*=p[i];
        pq.push(make_pair((1-pow(1-p[i],2))/p[i],i));
        cnt[i]=1;
    }
    int tot=n;
    double res=now*tot,la=now;
    for(int _=1;_<=1000000;_++)
    {
        pair<double,int> u=pq.top();
        pq.pop();
        now*=u.first;
        tot++;
        res+=(now-la)*tot;
        la=now;
        int t=u.second;
        cnt[t]++;
        pq.push(make_pair((1-pow(1-p[t],cnt[t]+1))/(1-pow(1-p[t],cnt[t])),t));
    }
    printf("%.10f\n",res);
    return 0;
}