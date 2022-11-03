//
//  main.cpp
//  B
//
//  Created by  on 10/18/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ans[105];

int n,k;

const int maxn = 105;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    int mx = 1000;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mx = min(mx,a[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= mx;j++){
            ans[i].push_back(k);
        }
        a[i] -= mx;
    }
    for(int i = 1;i <= n;i++){
        if(a[i] > 0){
            ans[i].push_back(k);
            a[i]--;
        }
    }
    int m = 0;
    for(int i = 1;i <= n;i++) if(a[i] > 0) m++;
    k--;
    for(int t = k;t > 0;t--){
        for(int i = 1;i <= n;i++){
            if(a[i] > 0){
                ans[i].push_back(t);
                a[i]--;
                if(a[i] == 0) m--;
            }
        }
    }
    if(m == 0){
        printf("YES\n");
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < ans[i].size();j++){
                printf("%d%c",ans[i][j],j == ans[i].size() - 1 ? '\n' : ' ');
            }
        }
    }else{
        printf("NO\n");
    }
    return 0;
}