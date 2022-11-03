//
//  main.cpp
//  B
//
//  Created by  on 16/5/24.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 19;

int a[maxn];int n;
int qu[maxn];
int sz;
int lef[maxn],rig[maxn];
int ans[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++) scanf("%d",a + i);
    sz = 0;
    
    for(int i = 1;i <= n;i++){
        while(sz > 0 && a[i] <= a[qu[sz]]) sz--;
        if(sz == 0) lef[i] = 1;
        else lef[i] = qu[sz] + 1;
        qu[++sz] = i;
    }
    sz = 0;
    for(int i = n;i >= 1;i--){
        while(sz > 0 && a[i] <= a[qu[sz]]) sz--;
        if(sz == 0) rig[i] = n;
        else rig[i] = qu[sz] - 1;
        qu[++sz] = i;
    }
    memset(ans,0,sizeof(ans));
    for(int i = 1;i <= n;i++){
        int len = rig[i] - lef[i] + 1;
        ans[len] = max(ans[len],a[i]);
    }
    for(int i = n;i > 1;i--){
        ans[i - 1] = max(ans[i - 1],ans[i]);
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c",ans[i],i == n ? '\n' : ' ');
    }
    return 0;
}