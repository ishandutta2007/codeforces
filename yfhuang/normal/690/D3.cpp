//
//  main.cpp
//  D(hard)
//
//  Created by  on 16/7/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const long long mod = 1e6 + 3;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat & A,mat & B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0;i < A.size();i++){
        for(int k = 0;k < B.size();k++) if(A[i][k]){
            for(int j = 0;j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n){
    mat B(A.size(),vec(A.size()));
    for(int i = 0;i < A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}

ll c;
int w,h;

ll dp[105][105];

int main(int argc, const char * argv[]) {
    cin >> c >> w >> h;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1;i <= min((int)c,w);i++){
        for(int j = 0;j < i;j++){
            dp[i][0] = (dp[i][0] + dp[i - 1][j]) % mod;
        }
        for(int j = 1;j <= i;j++){
            dp[i][j] =(dp[i][j] + dp[i - 1][j - 1] * h) % mod;
        }
    }
    //for(int i = 0;i <= w;i++) cout << dp[w][i] << endl;
    if(c <= w){
        ll ans = 0;
        for(int i = 0;i <= c;i++){
            ans = (ans + dp[c][i]) % mod;
        }
        cout << ans << endl;
    }else{
        mat A(w + 1,vec(w + 1));
        for(int i = 0;i <= w;i++){
            if(!i){
                for(int j = 0;j <= w;j++){
                    A[i][j] = 1;
                }
            }else{
                for(int j = 0;j <= w;j++) A[i][j] = 0;
                A[i][i - 1] = h;
            }
        }
        mat B(w + 1,vec(1));
        for(int i = 0;i <= w;i++){
            B[i][0] = dp[w][i];
        }
        mat C(w + 1,vec(1));
        mat D(w + 1,vec(w + 1));
        D = pow(A,c - w);
        C = mul(D , B);
        ll ans = 0;
        for(int i = 0;i <= w;i++){
            ans = (ans + C[i][0]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}