//
//  main.cpp
//  C
//
//  Created by  on 16/7/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int a[105];

int check(bool flag,int now){
    int d = n + 1;
    if(flag){//
        for(int i = now;i <= n;i++){
            if((i - now + 1) & 1){
                if(a[i] != 2 && a[i] != 3){
                    d = i;
                    break;
                }
            }else{
                if(a[i] != 1 && a[i] !=  3){
                    d = i;
                    break;
                }
            }
        }
    }else{
        for(int i = now;i <= n;i++){
            if((i - now + 1) & 1){
                if(a[i] != 1 && a[i] != 3){
                    d = i;
                    break;
                }
            }else{
                if(a[i] != 2 && a[i] != 3){
                    d = i;
                    break;
                }
            }
        }
    }
    return d;
}

bool vis[105];

int main(int argc, const char * argv[]) {
    cin >> n;
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 1e9 + 7;
    int pre = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] == 2){
            if(pre != 2){
                vis[i] = true;
                pre = 2;
            }else pre = 0;
        }else if(a[i] == 1){
            if(pre != 1){
                vis[i] = true;
                pre = 1;
            }else pre = 0;
        }else if(a[i] == 3){
            if(pre == 2){
                vis[i] = true;
                pre = 1;
            }else if(pre == 1){
                vis[i] = true;
                pre = 2;
            }else{
            int x = max(check(true,i),check(false,i));
            for(int j = i;j < x;j++) vis[j] = true;
            i = x;
            pre = 0;
            }
        }
        else pre = 0;
    }
    ans = 0;
    for(int i = 1;i <= n;i++){
        if(!vis[i])  ans++;
    }
    cout << ans << endl;
    return 0;
}