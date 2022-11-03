//
//  main.cpp
//  D
//
//  Created by  on 10/9/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

map<int,int> mp;

int n;
const int maxn = 1e6 + 5;
int b[maxn];

int lef[maxn];
int ri[maxn];

int c[maxn];

void add(int x){
    while(x < maxn){
        c[x]++;
        x += x & -x;
    }
}

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= x & -x;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++){
        scanf("%d",b + i);
    }
    mp.clear();
    for(int i = 1;i <= n;i++){
        mp[b[i]]++;
        lef[i] = mp[b[i]];
    }
    mp.clear();
    for(int i = n;i >= 1;i--){
        mp[b[i]]++;
        ri[i] = mp[b[i]];
    }
    long long ans = 0;
    for(int i = n;i >= 1;i--){
        ans += sum(lef[i] - 1);
        add(ri[i]);
    }
    cout << ans << endl;
    return 0;
}