//
//  main.cpp
//  B
//
//  Created by  on 8/4/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int n,k;

bool vis[maxn];

int b[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    cin >> k;
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++){
        scanf("%d",b + i);
    }
    for(int i = 1;i <= k;i++){
        int id;
        scanf("%d",&id);
        vis[id] = true;
    }
    int sum = 0;
    for(int i = 1;i <= n;i++) sum += b[i];
    int s1 = 0;
    for(int i = 1;i <= n;i++) if(vis[i]) s1+= b[i];
    long long ans = 0;
    b[0] = b[n],vis[0] = vis[n];
    b[n + 1] = b[1],vis[n + 1] = vis[1];
    for(int i = 1;i <= n;i++){
        if(vis[i]){
            ans += (long long) (sum - b[i]) * (long long)b[i];
        }else{
            long long c = s1;
            if(!vis[i - 1]) c += b[i - 1];
            if(!vis[i + 1]) c += b[i + 1];
            ans += (long long) b[i] * c;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}