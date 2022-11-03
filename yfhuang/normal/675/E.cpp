//
//  main.cpp
//  E
//
//  Created by  on 16/5/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int maxv[maxn << 2];
int a[maxn];

void build(int o,int L,int R){
    int M = L + (R - L) / 2;
    if(L == R) maxv[o] = L;
    else{
        build(o << 1,L,M);
        build((o << 1) | 1,M + 1,R);
        if(a[maxv[o << 1]] > a[maxv[(o << 1) | 1]]){
            maxv[o] = maxv[o * 2];
        }
        else maxv[o] = maxv[o * 2 + 1];
    }
}
int ql,qr;
int query(int o,int L,int R){
    int M = L + (R - L) / 2,ans = ql;
    if(ql <= L && R <= qr) return maxv[o];
    if(ql <= M){
        int p = query(o * 2,L,M);
        if(a[p] > a[ans]){
            ans = p;
        }
    }
    if(qr > M){
        int p = query(o * 2 + 1,M + 1,R);
        if(a[p] > a[ans]){
            ans = p;
        }
    }return ans;
}

int n;

long long dp[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i < n;i++){
        scanf("%d",a + i);
    }
    a[n] = n;
    build(1,1,n);
    int j;
    for( j = n;j >= 1 && a[j] == n;j--){
        dp[j] = (n - j);
    }
    for(int i = j;i >= 1;i--){
        ql = i + 1;
        qr = a[i];
        int p = query(1,1,n);
        dp[i] = dp[p] + (long long)(n - p) - (long long)(a[i] - p);
        dp[i] += (long long)p - i;
    }
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        sum += dp[i];
    }
    cout << sum << endl;
    return 0;
}