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
vector<vector<vector<vector<T>>>> vec4d(int n, int m, int k, int l, T v){
    return vector<vector<vector<vector<T>>>>(n, vector<vector<vector<T>>>(m, vector<vector<T>>(k, vector<T>(l, v))));
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

const ll MOD = 1000000007;

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

    ModInt &operator+=(ll n){
        v = (v+n)%MOD;
        return *this;
    }
    ModInt &operator-=(ll n){
        v = (v-n+MOD)%MOD;
        return *this;
    }
    ModInt &operator*=(ll n){
        v = (v*n+MOD)%MOD;
        return *this;
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

    ModInt &operator+=(ModInt n){
        v = (v+n.v)%MOD;
        return *this;
    }
    ModInt &operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
        return *this;
    }
    ModInt &operator*=(ModInt n){
        v = (v*n.v)%MOD;
        return *this;
    }

    bool operator==(ModInt n){
        return v == n.v;
    }
    bool operator!=(ModInt n){
        return v != n.v;
    }
    ModInt &operator=(ll n){
        v = n%MOD;
        return *this;
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
    while (n > 0) {
        if (n&1) ans = ans*a;
        a = a*a;
        n >>= 1;
    }
	return ans;
}

using mint = ModInt;
const int inf = 1e9;

void solve(){
    int n, m, rb, cb, rd, cd, p; cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    rb--; cb--; rd--; cd--;
    auto dist = vec4d(n, m, 2, 2, inf);
    int cnt = 0;
    int dr = 1, dc = 1;
    vector<int> idx;
    if(rb == rd || cb == cd){
        idx.push_back(cnt);
    }
    auto correct_direction = [&](){
        if(rb+dr >= n){
            dr *= -1;
        }else if(rb+dr < 0){
            dr *= -1;
        }
        if(cb+dc >= m){
            dc *= -1;
        }else if(cb+dc < 0){
            dc *= -1;
        }
    };
    int start_rb = rb;
    int start_cb = cb;
    correct_direction();
    int start_dr = dr;
    int start_dc = dc;
    while(true){
        cnt++;
        rb += dr;
        cb += dc;
        // cout << rb << ' ' << cb << ' ' << dr << ' ' << dc << endl;
        correct_direction();
        if(rb == start_rb && cb == start_cb && dr == start_dr && dc == start_dc){
            break;
        }
        dist[rb][cb][(dr+1)/2][(dc+1)/2] = cnt;
        if(rb == rd || cb == cd){
            idx.push_back(cnt);
        }
    }
    int cycle = cnt;
    // debug_value(cycle);
    // print_vector(idx);
    mint prob = mint(p)/mint(100);
    mint rem_prob = mint(1) - prob;
    int mm = idx.size();
    mint ans = 0;
    for(int i = 0; i < mm; i++){
        mint pm = pow(rem_prob, mm);
        mint C = pow(rem_prob, i)*prob;
        ans += C*idx[i]/(mint(1)-pm);
        ans += C*cycle*pm/((mint(1)-pm)*(mint(1)-pm));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}