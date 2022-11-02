#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const int N_MAX = 200000;

const ll MOD = 1000000007;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        if(_v >= MOD) _v %= MOD;
        v = _v;
    }
    ModInt operator+(ll n){
        return ModInt((v+n)%MOD);
    }
    ModInt operator-(ll n){
        return ModInt((v-n+MOD)%MOD);
    }
    ModInt operator*(ll n){
        if(n >= MOD) n %= MOD;
        return ModInt((v*n)%MOD);
    }
    ModInt operator/(ll n){
        return ModInt((ModInt(n).inv()*v).v%MOD);
    }

    void operator+=(ll n){
        v = (v+n)%MOD;
    }
    void operator-=(ll n){
        v = (v-n+MOD)%MOD;
    }
    void operator*=(ll n){
        v = (v*n+MOD)%MOD;
    }
    
    
    ModInt operator+(ModInt n){
        return ModInt((v+n.v)%MOD);
    }
    ModInt operator-(ModInt n){
        return ModInt((v-n.v+MOD)%MOD);
    }
    ModInt operator*(ModInt n){
        return ModInt((v*n.v)%MOD);
    }
    ModInt operator/(ModInt n){
        return ModInt((n.inv()*v).v%MOD);
    }

    void operator+=(ModInt n){
        v = (v+n.v)%MOD;
    }
    void operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
    }
    void operator*=(ModInt n){
        v = (v*n.v)%MOD;
    }

    void operator=(ModInt n){
        v = n.v;
    }
    bool operator==(ModInt n){
        return v == n.v;
    }
    bool operator!=(ModInt n){
        return v != n.v;
    }
    void operator=(ll n){
        v = n%MOD;
    }

    ModInt inv(){
        if(v == 1) return ModInt(1);
        else return ModInt(MOD-ModInt(MOD%v).inv().v*(MOD/v)%MOD);
    }
};

ostream& operator<<(ostream& os, const ModInt& m){
    os << m.v;
    return os;
}

istream & operator >> (istream &in,  ModInt &m){
    in >> m.v;
    return in;
}

using P = pair<int, int>;

vector<P> fac[N_MAX+1];

void init(){
    vector<int> v(N_MAX+1);
    for(int i = 1; i <= N_MAX; i++) v[i] = i;
    for(int i = 2; i <= N_MAX; i++){
        for(int j = 1; i*j <= N_MAX; j++){
            int cnt = 0;
            while(v[i*j]%i == 0){
                cnt++;
                v[i*j] /= i;
            }
            if(cnt != 0) fac[i*j].push_back(make_pair(i, cnt));
        }
    }
}

ModInt pow(ModInt a, ll n) {
	ModInt ans = 1;
	ModInt tmp = a;
	for (int i = 0; i <= 60; i++) {
		ll m = (ll)1 << i;
		if (m & n) {
		ans *= tmp;
		}
		tmp *= tmp;
	}
	return ans;
}

using mint = ModInt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, q; cin >> n >> q;
    vector<map<int, int>> cnt(N_MAX+1);
    auto add = [&](int i, int p, int c){
        if(cnt[p].count(i)) cnt[p][i] += c;
        else cnt[p][i] = c;
    };

    auto sub = [&](int i, int p, int c){
        cnt[p][i] -= c;
        if(cnt[p][i] == 0) cnt[p].erase(i);
    };
    
    mint ans = 1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        for(auto [p, c] : fac[a]){
            add(i, p, c);
            if(cnt[p].size() == n){
                int mn = 1e9;
                for(auto it : cnt[p]){
                    chmin(mn, it.second);
                }
                ans *= pow(mint(p), mn);
                for(int i = 0; i < n; i++){
                    sub(i, p, mn);
                }
            }
        }
    }
    
    while(q--){
        int i, x; cin >> i >> x; i--;
        for(auto [p, c] : fac[x]){
            add(i, p, c);
            if(cnt[p].size() == n){
                int mn = 1e9;
                for(auto it : cnt[p]){
                    chmin(mn, it.second);
                }
                ans *= pow(mint(p), mn);
                for(int i = 0; i < n; i++){
                    sub(i, p, mn);
                }
            }
        }
        cout << ans << endl;
    }
}