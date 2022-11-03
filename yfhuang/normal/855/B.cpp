#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int maxn = 1e5 + 5;
int n,p,q,r;
long long a[maxn];
long long pre[maxn];
long long pre1[maxn];
int main(){
    cin >> n >> p >> q >> r;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    pre[1] = p * a[1];
    for(int i = 2;i <= n;i++){
        pre[i] = p * a[i];
        pre[i] = max(pre[i - 1],pre[i]);
    }
    pre1[1] = p * a[1] + q * a[1];
    for(int i = 2;i <= n;i++){
        pre1[i] = q * a[i] + pre[i];
        pre1[i] = max(pre1[i - 1],pre1[i]);
    }
    long long ans = -3e18 - 5;
    for(int i = 1;i <= n;i++){
        ans = max(ans,r * a[i] + pre1[i]);
    }
    cout << ans << endl;
    return 0;
}