#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define N_MAX 200002

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

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


ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

int N;
int p[200000];
vector<int> v;
bool used[200001];
int cnt[200001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        used[p[i]] = true;
        if(i == 0){
            if(p[i] == -1) cnt[i] = 1;
        }else{
            if(p[i] == -1) cnt[i] = cnt[i-1]+1;
            else cnt[i] = cnt[i-1];
        }
    }
    for(int i = 1; i <= N; i++){
        if(!used[i]) v.push_back(i);
    }
    ll ans = 0;
    ll n = v.size();
    ans = ((((n*(n-1))/2)%MOD)*inv[2])%MOD;
    bit<int> bt(N);
    int c = 0;
    for(int i = 0; i < N; i++){
        if(p[i] != -1) {
            ans += (c-bt.sum(p[i]));
            bt.add(p[i], 1);
            c++;
        }
    }
    for(int i = 0; i < N; i++){
        if(p[i] != -1){
            ll l = cnt[i];
            ll r = v.size()-l;
            auto ptr = lower_bound(v.begin(), v.end(), p[i]);
            ll s = ptr-v.begin();
            ll t = v.size()-s;
            ans += ((((s*r)%MOD+t*l)%MOD)*inv[l+r])%MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}