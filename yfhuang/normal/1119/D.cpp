#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

long long s[maxn];
long long b[maxn];
int q;
int n;
long long pre[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &s[i]);
    }
    sort(s + 1, s + 1 + n);
    n = unique(s + 1, s + 1 + n) - s - 1;
    for(int i = 1;i < n;i++){
        b[i] = s[i + 1] - s[i];
    } 
    sort(b + 1, b + n);
    pre[0] = 0;
    for(int i = 1;i < n;i++){
        pre[i] = pre[i - 1] + b[i];
    }
    cin >> q;
    for(int i = 1;i <= q;i++){
        long long l, r;
        scanf("%lld%lld", &l, &r);
        long long len = r - l + 1;
        int p = upper_bound(b + 1, b + n, len) - b;
        p--;
        long long ans = 1LL * (n - p) * len + pre[p];
        printf("%lld%c", ans, i == q ? '\n' : ' ');
    }
    return 0;
}