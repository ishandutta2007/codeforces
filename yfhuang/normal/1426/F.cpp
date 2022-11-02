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
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int qpow(int a, int n){
    if(n < 0)
        return 0;
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

string s;

int pre[4][maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(s[i - 1] == '?'){
            pre[3][i]++;
            cnt++;
        }else{
            pre[s[i - 1] - 'a'][i]++;
        }
        for(int j = 0;j < 4;j++){
            pre[j][i] += pre[j][i - 1];
        }
    } 
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        if(s[i - 1] == 'b'){
            ans = (ans + 1LL * pre[0][i - 1] * (pre[2][n] - pre[2][i]) % mod * qpow(3, cnt)) % mod;
            ans = (ans + 1LL * pre[0][i - 1] * (pre[3][n] - pre[3][i]) % mod * qpow(3, cnt - 1)) % mod;
            ans = (ans + 1LL * pre[3][i - 1] * (pre[2][n] - pre[2][i]) % mod * qpow(3, cnt - 1)) % mod;
            ans = (ans + 1LL * pre[3][i - 1] * (pre[3][n] - pre[3][i]) % mod * qpow(3, cnt - 2)) % mod;
        }else if(s[i - 1] == '?'){
            ans = (ans + 1LL * pre[0][i - 1] * (pre[2][n] - pre[2][i]) % mod * qpow(3, cnt - 1)) % mod;
            ans = (ans + 1LL * pre[0][i - 1] * (pre[3][n] - pre[3][i]) % mod * qpow(3, cnt - 2)) % mod;
            ans = (ans + 1LL * pre[3][i - 1] * (pre[2][n] - pre[2][i]) % mod * qpow(3, cnt - 2)) % mod;
            ans = (ans + 1LL * pre[3][i - 1] * (pre[3][n] - pre[3][i]) % mod * qpow(3, cnt - 3)) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}