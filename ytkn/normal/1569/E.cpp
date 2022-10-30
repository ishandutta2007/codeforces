#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}


const ll MOD = 998244353;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        if(_v < 0) _v = (_v%MOD)+MOD;
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

ModInt pow(ModInt a, ll n) {
    assert(n >= 0);
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
using P = pair<int, int>;

template<typename T>
vector<T> merge(vector<T> u, vector<T> v){
    for(T x: v) u.push_back(x);
    return u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int k, a, h; cin >> k >> a >> h;
    int matches = (1<<k)-1;
    int m = matches/2;
    map<P, vector<int>> l_ord; // key = (winner, hash)
    map<P, vector<int>> r_ord;
    for(int s = 0; s < (1<<m); s++){
        int x = (1<<(k-1))+1;
        vector<vector<int>> rem(k);
        int n = 1<<(k-1);
        for(int i = 0; i < n; i++) rem[0].push_back(i);
        int l = 0;
        for(int i = 0; i < k-1; i++){
            int r = l+(1<<(k-2-i));
            for(int j = l; j < r; j++){
                int idx = (j-l)*2;
                bool win_left = (s&(1<<j)) > 0;
                rem[i+1].push_back(win_left ? rem[i][idx] : rem[i][idx+1]);
            }
            l = r;
        }
        vector<int> ord(n, -1);
        ord[rem[k-1][0]] = 0;
        for(int i = k-2; i >= 0; i--){
            for(int x: rem[i]) {
                if(ord[x] == -1) ord[x] = 2*rem[i+1].size()+1;
            }
        }
        int l_winner = rem[k-1][0];
        int l_hash = [&]() -> int{
            mint ans = 0;
            for(int i = 0; i < (1<<(k-1)); i++){
                if(ord[i] == 0) continue;
                ans += mint(i+1)*pow(mint(a), ord[i]);
            }
            return ans.v;
        }();
        int r_winner = rem[k-1][0]+(1<<(k-1));
        int r_hash = [&]() -> int{
            mint ans = 0;
            for(int i = 0; i < (1<<(k-1)); i++){
                if(ord[i] == 0) continue;
                ans += mint(i+1+(1<<(k-1)))*pow(mint(a), ord[i]);
            }
            return ans.v;
        }();
        // cout << l_winner << ' ' << l_hash << ' ' << r_winner << ' ' << r_hash << endl;
        l_ord[P(l_winner, l_hash)] = ord;
        r_ord[P(r_winner, r_hash)] = ord;
    }
    mint target = h;
    for(auto [p, ord]: l_ord){
        auto [l_winner, l_hash] = p;
        // cout << l_winner << ' ' << l_hash << endl;
        for(int r_winner = (1<<(k-1)); r_winner < (1<<k); r_winner++){
            // 
            mint hs = mint(l_hash) + mint(l_winner+1)*pow(mint(a), 1) + mint(r_winner+1)*pow(mint(a), 2);
            mint rem = target-hs;
            if(r_ord.count(P(r_winner, rem.v))){
                auto ans = merge(ord, r_ord[P(r_winner, rem.v)]);
                ans[l_winner] = 1;
                ans[r_winner] = 2;
                print_vector(ans);
                return 0;
            }
            // 
            hs = mint(l_hash) + mint(l_winner+1)*pow(mint(a), 2) + mint(r_winner+1)*pow(mint(a), 1);
            rem = target-hs;
            if(r_ord.count(P(r_winner, rem.v))){
                auto ans = merge(ord, r_ord[P(r_winner, rem.v)]);
                ans[l_winner] = 2;
                ans[r_winner] = 1;
                print_vector(ans);
                return 0;
            }
        }
    }
    cout << -1 << endl;
}