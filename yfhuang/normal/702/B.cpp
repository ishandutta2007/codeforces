//
//  main.cpp
//  B
//
//  Created by  on 7/30/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<long long,int> mp;

int n;

const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    mp.clear();
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        for(int j = 1;j <= 30;j++) ans += mp[(1 << j) - a[i]];
        mp[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}