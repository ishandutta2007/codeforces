//
//  main.cpp
//  C
//
//  Created by  on 16/3/13.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e7+5;
pair<pair<int,int>,int> p[105];
bool vis[maxn];

int n;
int ans[105];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].first.second,&p[i].first.first);
        p[i].second=i;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        while(vis[p[i].first.second]) p[i].first.second++;
        ans[p[i].second]=p[i].first.second;
        vis[p[i].first.second]=true;
    }
    for(int i=0;i<n;i++){
        printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
    return 0;
}