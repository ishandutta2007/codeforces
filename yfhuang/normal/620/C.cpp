//
//  main.cpp
//  C
//
//  Created by  on 16/1/22.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int maxn=3e5+10;

int a[maxn];


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    set<int> s;
    vector<pair<int,int>> v;
    int l=0,r=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s.find(a[i])!=s.end()){
            l=r+1,r=i;
            v.push_back(make_pair(l, r));
            cnt++;
            s.clear();
        }
        else s.insert(a[i]);
    }
    if(cnt==0) {
        printf("-1\n");
        return 0;
    }
    int size=v.size();
    v[size-1].second=n;
    printf("%d\n",cnt);
    for(int i=0;i<size;i++)
        printf("%d %d\n",v[i].first,v[i].second);
    return 0;
}