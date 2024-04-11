//
//  main.cpp
//  B
//
//  Created by  on 8/29/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 505;

int n;
typedef long long ll;
ll a[maxn][maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    ll sum = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        printf("1\n");
    }else{
        for(int i = 1;i <= n;i++){
            sum = 0;
            bool flag = true;
            for(int j = 1;j <= n;j++){
                if(a[i][j] == 0) flag = false;
            }
            if(flag){
                for(int j = 1;j <= n;j++){
                    sum += a[i][j];
                }
                break;
            }
        }
        ll ans = 0;
        for(int i = 1;i <= n;i++){
            bool flag = false;
            for(int j = 1;j <= n;j++){
                if(a[i][j] == 0) flag = true;
            }
            if(flag){
                ll tmp = 0;
                for(int j = 1;j <= n;j++){
                    tmp += a[i][j];
                }
                for(int j = 1;j <= n;j++){
                    if(a[i][j] == 0) a[i][j] = sum - tmp,ans = a[i][j];
                }
                break;
            }
        }
        bool flag = true;
        for(int i = 1;i <= n;i++){
            ll x = 0;
            ll y = 0;
            for(int j = 1;j <= n;j++){
                x += a[i][j];
                y += a[j][i];
            }
            if(x != sum) flag = false;
            if(y != sum) flag = false;
        }
        ll x = 0,y = 0;
        for(int i = 1;i <= n;i++){
            x += a[i][i];
            y += a[n + 1 - i][i];
        }
        if(x != sum || y != sum) flag = false;
        if(flag){
            if(ans > 0)
            cout << ans << endl;
            else cout << -1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}