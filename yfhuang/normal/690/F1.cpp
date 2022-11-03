//
//  main.cpp
//  F(easy)
//
//  Created by  on 16/7/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;

const int maxn = 10005;

vector<int > G[maxn];


int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i < n;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        int s = G[i].size();
        ans += (long long)s *(long long) (s - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}