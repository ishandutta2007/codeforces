//
//  main.cpp
//  D
//
//  Created by  on 10/13/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
int x;
const int maxn = 1e5 + 5;
int d[maxn];
int cnt[105];

typedef long long LL;
typedef vector<LL> vec;
typedef vector<vec> mat;

const LL mod = 1e9 + 7;

mat mul(mat & A,mat & B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0;i < A.size();i++){
        for(int k = 0;k < A[0].size();k++) if(A[i][k] != 0){
            for(int j = 0;j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

LL dp[105];

mat pow(mat A,LL n){
    mat C(A.size(),vec(A[0].size()));
    for(int i = 0;i < A.size();i++){
        C[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) C = mul(C,A);
        A = mul(A,A);
        n >>= 1;
    }
    return C;
}

int main(int argc, const char * argv[]) {
    cin >> n >> x;
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i <= n;i++){
        scanf("%d",d + i);
        cnt[d[i]]++;
    }
    memset(dp,0,sizeof(dp));
    if(x <= 100){
        dp[0] = 1;
        for(int i = 1;i <= x;i++){
            for(int j = i - 1;j >= 0;j--){
                dp[i] = (dp[i] + dp[j] * (LL) cnt[i - j]) % mod;
            }
        }
        LL ans = 0;
        for(int i = 0;i <= x;i++){
            ans = (ans + dp[i]) % mod;
        }
        cout << ans << endl;
    }else{
        dp[0] = 1;
        for(int i = 1;i <= 100;i++){
            for(int j = i - 1;j >= 0;j--){
                dp[i] = (dp[i] + dp[j] * (LL) cnt[i - j]) % mod;
            }
        }
//        for(int i = 0;i <= 100;i++){
//            cout << dp[i] << endl;
//        }
        mat B(1,vec(101));
        for(int i = 0;i < 100;i++){
            B[0][i] = dp[i + 1];
            //cout << B[0][i] << endl;
        }
        LL sum = 0;
        for(int i = 0;i <= 100;i++){
            sum = (sum + dp[i]) % mod;
        }
        B[0][100] = sum;
        //cout << B[0][100] << endl;
        mat A(101,vec(101));
        for(int i = 0;i < 99;i++){
            A[i + 1][i] = 1;
        }
        for(int i = 0;i < 100;i++){
            A[i][99] = cnt[100 - i];
            A[i][100] = cnt[100 - i];
        }
        A[100][100] = 1;
//        for(int i = 0;i <= 100;i++){
//            for(int j = 0;j <= 100;j++){
//                cout << A[i][j] << " ";
//            }
//            cout << endl;
//        }
       // mat C(101,vec(101));
      //  mat D(1,vec(101));
        A = pow(A,x - 100);
        B = mul(B,A);
        cout << B[0][100] << endl;
    }
    return 0;
}