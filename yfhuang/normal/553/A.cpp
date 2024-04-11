//
//  main.cpp
//  A
//
//  Created by  on 16/5/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int k;

int n;

const int maxn = 2000 + 5;

int c[maxn];
const int mod = 1e9 + 7;

int C[maxn][maxn];

void table(){
    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;
    for(int i = 2;i <= 2000;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0 || j == i) C[i][j] = 1;
            else{
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> k;
    table();
    for(int i = 1;i <= k;i++){
        scanf("%d",c + i);
    }
    int sum = 0;
    long long ans = 1;
    for(int i = 2;i <= k;i++){
        sum += c[i - 1];
        ans = ans * (long long) C[sum + c[i] - 1][c[i] - 1] % mod;
    }
    ans = ans % mod;
    while(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}