//
//  main.cpp
//  E
//
//  Created by  on 16/3/24.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

set<pair<int, int>> forbidden;

bool ok(int a, int b){
    if(a > b) swap(a, b);
    return forbidden.find(make_pair(a, b))==forbidden.end();
}

set<int> remaining;

void dfs(int a){
    vector<int> memo;
    for(int b:remaining)if(ok(a,b)){
        memo.push_back(b);
    }
    for(int b:memo){
        remaining.erase(b);
    }
    for(int b:memo) dfs(b);
}

void No(){
    puts("impossible");
    exit(0);
}

int main(int argc, const char * argv[]) {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;i++) remaining.insert(i);
    int allow_degree=n-1;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        if(a==1) allow_degree--;
        forbidden.insert(make_pair(a, b));
    }
    if(allow_degree<k) No();
    int components=0;
    for(int i=2;i<=n;i++) if(ok(1,i)&&remaining.find(i)!=remaining.end()){
        dfs(i);
        components++;
    }
    if(!remaining.empty()) No();
    if(components>k) No();
    puts("possible");
    return 0;
    return 0;
}