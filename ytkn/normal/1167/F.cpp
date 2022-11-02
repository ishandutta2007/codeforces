#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

//1-indexed
template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};


map<ll, int> mp;
const ll MOD = 1000000007;
ll N;
ll a[500000];
ll b[500000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+N);
    for(int i = 0; i < N; i++){
        mp[b[i]] = i;
    }
    vector<ll> v(N, 0);
    bit<ll> bt(N);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ans += (((i+1)*(N-i)%MOD)*a[i])%MOD;
        ans %= MOD;
    }
    for(ll i = 0; i < N; i++){
        int idx = mp[a[i]]+1;
        ll tmp = bt.sum(idx)%MOD;
        ans += (((a[i]*tmp)%MOD)*(N-i))%MOD;
        bt.add(idx, i+1);
        ans %= MOD;
    }
    bit<ll> bt2(N);
    for(ll i = N-1; i >= 0; i--){
        int idx = mp[a[i]]+1;
        ll tmp = bt2.sum(idx)%MOD;
        ans += (((a[i]*tmp)%MOD)*(i+1))%MOD;
        bt2.add(idx, N-i);
        ans %= MOD;
    }
    cout << ans << endl;
}