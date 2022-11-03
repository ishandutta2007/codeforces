//
//  main.cpp
//  A
//
//  Created by  on 16/5/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

const int maxn = 100;

int t[maxn];

int vis[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++){
        scanf("%d",t + i);
        vis[t[i]] = true;
    }
    int ans = 90;
    for(int i = 15;i <= 90;i++){
        bool flag = false;
        for(int j = i;j > i - 15;j--){
            if(vis[j]) flag = true;
        }
        if(!flag){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}