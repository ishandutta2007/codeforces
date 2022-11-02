#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;
const int maxn = 1005;
int a[maxn];
const int mod = 1e9 + 7;

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

int solve(int a, int b){
    int ret = 1;
    int ret1 = 1;
    for(int i = a - b + 1;i <= a;i++){
        ret = 1LL * ret * i % mod;
    }
    for(int i = 1;i <= b;i++){
        ret1 = 1LL * ret1 * i % mod;
    }
    return 1LL * ret * qpow(ret1, mod - 2) % mod;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int l = n - k + 1;
        int r = n - k + 1;
        while(l > 1){
            if(a[l - 1] == a[n - k + 1])
                l--;
            else
                break;
        }
        while(r < n){
            if(a[r + 1] == a[n - k + 1])
                r++;
            else
                break;
        }
        int len = r - l + 1;
        int len1 = (r - (n - k));
        cout << solve(len, len1) << endl;
    }
    return 0;
}