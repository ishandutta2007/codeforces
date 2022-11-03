#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
const int maxn = (1 << 20) + 5;

void fwt(int x[],int l,int r){
    if(l + 1 == r) return;
    int mid = (l + r) >> 1;
    fwt(x,l,mid);
    fwt(x,mid,r);
    for(int i = l;i < mid;i++){
        int a = x[i],b = x[i - l + mid];
        x[i] = (a + b) % mod;
        x[i - l + mid] = (a - b + mod) % mod;
    }
}

void rfwt(int x[],int l,int r){
    if(l + 1 == r) return;
    int mid = (l + r) >> 1;
    for(int i = l;i < mid;i++){
        int a = x[i],b = x[i - l + mid];
        x[i] = (a + b) * 1LL * inv2 % mod;
        x[i - l + mid] = (a - b) * 1LL * inv2 % mod;
    }
    rfwt(x,l,mid);
    rfwt(x,mid,r);
}
int n,m;
char str[maxn];
int b[maxn];
int c[maxn];
int main(){
    cin >> n;
    m = (1 << n);
    scanf("%s",str);
    for(int i = 0;i < m;i++){
        b[i] = str[i] - '0';
        c[i] = n - __builtin_popcount(i);
    }
    fwt(b,0,m);
    for(int i = 0;i < m;i++){
        b[i] = 1LL * b[i] * b[i] % mod;
    }
    rfwt(b,0,m);
    long long ans = 0;
    for(int i = 0;i < m;i++){
        ans = (ans + b[i] * 1LL * (1 << c[i]) % mod) % mod;
    }
    cout << (ans * 3LL) % mod << endl;
    return 0;
}