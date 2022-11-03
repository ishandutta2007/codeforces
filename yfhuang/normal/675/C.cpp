//
//  main.cpp
//  C
//
//  Created by  on 16/5/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

long long a[maxn];
long long pre[maxn];

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
    }
    int m = 0;
    map<long long ,int> mp;
    for(int i = 1;i <= n;i++){
        mp[pre[i]] ++;
        if(mp[pre[i]] > m) m = mp[pre[i]];
    }
    cout << n - m << endl;
    return 0;
}