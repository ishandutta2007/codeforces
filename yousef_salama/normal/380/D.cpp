//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MOD = 1000000007;

int n, a[100005], b[100005];

long long pw2[100005], fact[100005];
long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p == 1)return x;
    if(p % 2 != 0)return (modpow(x, p - 1) * x) % MOD;
    
    long long ret = modpow(x, p / 2);
    ret = (ret * ret) % MOD;
    return ret;
}
long long modinv(long long a){
    return modpow(a, MOD - 2);
}
long long ncr(int a, int b){
    long long ret = fact[a];
    ret = (ret * modinv(fact[b])) % MOD;
    ret = (ret * modinv(fact[a - b])) % MOD;
    
    return ret;
}

vector <int> v;
long long solve(int L, int R, int i){
    //cout << i << ':' << L << ',' << R << endl;
    if(i == v.size()){
        int d = L + (n - R - 1);
        return ncr(d, L);
    }
    
    int d = v[i] - v[i - 1];
    if(L <= b[v[i]] && b[v[i]] <= R)return 0;
    
    if(b[v[i]] < L){
        int x = L - b[v[i]];
        if(x <= d && R + (d - x) < n)
             return solve(b[v[i]], R + (d - x), i + 1) * ncr(d - 1, x - 1) % MOD;
    }else{
        int x = b[v[i]] - R;
        if(x <= d && L - (d - x) >= 0)
             return solve(L - (d - x), b[v[i]], i + 1) * ncr(d - 1, x - 1) % MOD;
    }
    
    return 0;
}
int main(){
    scanf("%d", &n);
    
    pw2[0] = 1, fact[0] = 1;
    for(int i = 1; i <= n; i++){
        pw2[i] = (pw2[i - 1] * 2) % MOD;
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    memset(b, -1, sizeof b);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    
    for(int i = 1; i <= n; i++)
        if(b[i] != -1)v.push_back(i);
    
    long long res = 0;
    
    if(v.empty())res = pw2[n - 1];
    else{
        if(b[v[0]] >= v[0] - 1)
             res = (res + pw2[max(v[0] - 2, 0)] * solve(b[v[0]] - v[0] + 1, b[v[0]], 1)) % MOD;
        if(v[0] > 1 && n - b[v[0]] - 1 >= v[0] - 1)
             res = (res + pw2[max(v[0] - 2, 0)] * solve(b[v[0]], b[v[0]] + v[0] - 1, 1)) % MOD;
    }
    printf("%d\n", (int)res);    
    
    return 0;
}