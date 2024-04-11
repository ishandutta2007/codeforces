//
//  main.cpp
//  C
//
//  Created by  on 10/13/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int maxn = 6e5 + 5;

typedef long long LL;

const LL mod = 1000000000007LL;

char s[maxn];
int n,m;
set<LL> h;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%s",s);
        LL x = 0;
        for(int j = 0; s[j]; j++) x = (x * 4 + s[j] - 'a' + 1) % mod;
        h.insert(x);
    }
    for(int i = 0;i < m;i++){
        scanf("%s",s);
        int j = 0;
        LL x = 0,b = 1;
        for(;s[j];j++) x = (x * 4 + s[j] - 'a' + 1) % mod;
        bool ok = 0;
        for(j--;j >= 0;j--) {
            s[j] -= 'a' - 1;
            LL t = ((x - b * s[j]) % mod + mod) % mod;
            for(int k = 1;k < 4;k++){
                if(k != s[j] && h.find((t + b * k) % mod) != h.end()) ok = 1;
            }
            b = (b * 4) % mod;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}