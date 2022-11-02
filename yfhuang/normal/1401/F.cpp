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

int n, q;
int swp[20];
const int maxn = 1e6 + 5;
ll a[maxn * 2];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    int S = (1 << n);
    for(int i = 0; i < S; i++){
        cin >> a[i + S];
    }
    for(int i = S - 1;i > 0;i--){
        a[i] = a[i * 2] + a[i * 2 + 1];
    }
    int mask = 0;
    for(int i = 1;i <= q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            ll k;
            cin >> x >> k;
            x--;
            x ^= mask;
            int delta = k - a[S + x];
            for(int s = S + x; s; s >>= 1) a[s] += delta;
        }else if(t == 2){
            int k; cin >> k;
            mask ^= ((1 << k) - 1);
        }else if(t == 3){
            int k; cin >> k;
            mask ^= (1 << k);
        }else if(t == 4){
            int l, r;cin >> l >> r;
            l--;
            ll ans = 0;
            for(int L = S + l, R = S + r, m = mask;L < R;L >>=1, R >>=1, m >>=1){
                if(L & 1) ans += a[(L++)^m];
                if(R & 1) ans += a[(--R)^m];
            }
            cout << ans << endl;
        }
    } 
    return 0;
}