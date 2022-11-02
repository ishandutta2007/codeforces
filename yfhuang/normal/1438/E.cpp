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

int n;
const int maxn = 2e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        int bit = 31 - __builtin_clz(a[i]);
        ll up = (1LL << (bit + 1));
        ll sum = 0;
        int j = i;
        while(j < n){
            sum += a[++j];
            if(sum >= up)
                break;
            if(j < n and ((a[i] ^ a[j + 1]) == sum)){
                ans++;
                int bit1 = 31 - __builtin_clz(a[j + 1]);
                if(bit1 == bit)
                    ans--;
            }
        }
    }
    for(int i = n;i >= 1;i--){
        int bit = 31 - __builtin_clz(a[i]);
        ll up = (1LL << (bit + 1));
        ll sum = 0;
        int j = i;
        while(j > 1){
            sum += a[--j];
            if(sum >= up)
                break;
            if(j > 1 and ((a[i] ^ a[j - 1]) == sum)){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}