//
//  main.cpp
//  A
//
//  Created by  on 16/3/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1005;

int p[maxn],t[maxn];
int n,c;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&c);
    for(int i = 1; i <= n; i++){
        scanf("%d",&p[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d",&t[i]);
    }
    long long ans1 = 0, ans2 = 0;
    int T = 0;
    for(int i = 1; i <= n; i++){
        T += t[i];
        ans1 += max(0, p[i] - T * c);
    }
    T = 0;
    for(int i = n; i >= 1; i--){
        T += t[i];
        ans2 +=max(0, p[i] - T * c);
    }
    if(ans1 > ans2)puts("Limak");
    else if (ans1 < ans2) puts("Radewoosh");
    else puts("Tie");
    return 0;
}