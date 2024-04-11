//
//  main.cpp
//  691E
//
//  Created by  on 16/7/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 105;


typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9 + 7;

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

ll n;
ll k;

ll a[maxn];



bool check(long long n){
    int cnt = 0;
    while(n > 0){
        if(n & 1) cnt++;
        n >>= 1;
    }
    if(cnt % 3 == 0) return true;
    return false;
}




int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    mat A(n,vec(n));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(check(a[i] ^ a[j])){
                A[i - 1][j - 1] = 1;
            }
        }
    }
    A = pow(A,k - 1);
    ll ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ans = (ans + A[i][j]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}