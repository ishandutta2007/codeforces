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

int h[100], nh[100];
int t;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        memset(h, 0, sizeof(h));
        memset(nh, 0, sizeof(nh));
        int n;
        cin >> n;
        vector<ll> x(n, 0);
        for(int i = 0;i < n;i++){
            cin >> x[i];
            for(int j = 0;j < 60;j++){
                if((x[i] >> j) & 1){
                    h[j]++;
                }else{
                    nh[j]++;
                }
            }
        }
        ll ans = 0;
        for(int j = 0;j < n;j++){
            ll tmp = x[j] % mod * n % mod;
            for(int i = 0;i < 60;i++){
                if(((x[j] >> i) & 1) == 0){
                    tmp = (tmp + 1LL * (1LL << i) % mod * h[i]) % mod;
                } 
            }
            ll tmp1 = 0;
            for(int i = 0;i < 60;i++){
                if((x[j] >> i) & 1){
                    tmp1 = (tmp1 + 1LL * (1LL << i) % mod * h[i]) % mod;
                }
            }
            ans = (ans + tmp * tmp1) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}