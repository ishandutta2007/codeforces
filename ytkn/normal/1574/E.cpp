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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    auto v = vec2d(n, 2, 0);
    auto u = vec2d(m, 2, 0);
    map<P, int> mp;
    int ngv = 0, ngu = 0;
    int occupiedv = 0, occupiedu = 0;
    vector<int> sum(2);
    auto clear = [&](int i, int j){
        P p(i, j);
        if(mp.count(p)){
            int x = mp[p];
            int parity = (i+j+x)%2;
            if(v[i][parity] == 1 && v[i][parity^1] > 0) ngv--;
            v[i][parity]--;
            if(u[j][parity] == 1 && u[j][parity^1] > 0) ngu--;
            u[j][parity]--;
            mp.erase(p);
            if(v[i][0]+v[i][1] == 0) occupiedv--;
            if(u[j][0]+u[j][1] == 0) occupiedu--;
            sum[parity]--;
        }
    };
    auto add = [&](int i, int j, int x){
        P p(i, j);
        if(mp.count(p)) clear(i, j);
        mp[p] = x;
        int parity = (i+j+x)%2;
        if(v[i][parity] == 0 && v[i][parity^1] > 0) ngv++;
        v[i][parity]++;
        if(u[j][parity] == 0 && u[j][parity^1] > 0) ngu++;
        u[j][parity]++;
        sum[parity]++;
        if(v[i][0]+v[i][1] == 1) occupiedv++;
        if(u[j][0]+u[j][1] == 1) occupiedu++;
    };
    auto print_field = [&](){
        auto f = vec2d(n, m, -1);
        for(auto [p, x]: mp) f[p.first][p.second] = x;
        cout << "=====" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << f[i][j] << ' ';
            }
            cout << endl;
        }
        cout << ngv << ' ' << ngu << endl;
        cout << occupiedv << ' ' << occupiedu << endl;
    };
    for(int i = 0; i < k; i++){
        int x, y, t; cin >> x >> y >> t; x--; y--;
        if(t == -1){
            clear(x, y);
        }else{
            add(x, y, t);
        }
        // print_field();
        mint ans = 0;
        if(ngv == 0){
            ans += pow(mint(2), n-occupiedv);
        }
        if(ngu == 0){
            ans += pow(mint(2), m-occupiedu);
        }
        if(sum[0] == 0) ans -= 1;
        if(sum[1] == 0) ans -= 1;
        cout << ans << endl;
    }
}