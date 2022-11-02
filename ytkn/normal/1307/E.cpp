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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> s(n);
    vector<vector<int>> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
        pos[s[i]].push_back(i);
    }
    vector<vector<int>> h(n);
    for(int i = 0; i < m; i++){
        int f, x; cin >> f >> x; f--;
        h[f].push_back(x);
    }
    for(int i = 0; i < n; i++) sort(h[i].begin(), h[i].end());
    auto calc_max = [&](int c){
        int ans = 0;
        bool any_c = false;
        mint cnt = 1;
        for(int i = 0; i < n; i++){
            if(h[i].empty()) continue;
            if(pos[i].empty()) continue;
            bool contain_c = false;
            int cnt_l = 0, cnt_r = 0;
            for(int x: pos[i]){
                if(x == c) contain_c = true;
                if(x < c) cnt_l++;
                else cnt_r++;
            }
            int a = min(cnt_l, cnt_r);
            int b = max(cnt_l, cnt_r);
            int m = pos[i].size();
            int tmp = 0;
            if(h[i].size() == 1){
                int h1 = h[i][0];
                if(h1 <= b){
                    ans++;
                    tmp = 1;  
                }
            }else{
                int h1 = h[i][0], h2 = h[i][1];
                if(h1 <= a && h2 <= b){
                    ans += 2;
                    tmp = 2;
                }else if(h1 <= b){
                    ans++;
                    tmp = 1;
                }
            }
            auto count_less = [&](int x){
                int ans = 0;
                for(int a: h[i]) {
                    if(a <= x) ans++;
                }
                return ans;
            };
            if(tmp == 1){
                if(contain_c) {
                    for(int a: h[i]){
                        if(a == cnt_r) any_c = true;
                    }
                    continue;
                }
                int ca = count_less(a);
                int cb = count_less(b);
                cnt *= (ca+cb);
            }else if(tmp == 2){
                if(contain_c) {
                    int ca = count_less(cnt_l);
                    for(int a: h[i]){
                        if(a == cnt_r) any_c = true;
                    }
                    if(cnt_r <= cnt_l) ca--;
                    if(ca < 0) cnt = 0;
                    else cnt *= ca;
                }else{
                    int ca = count_less(a);
                    int cb = count_less(b);
                    if(ca > cb) swap(ca, cb);
                    cnt *= ca*(cb-1);
                }
            }
        }
        if(!any_c) cnt = 0;
        return make_pair(ans, cnt);
    };
    int mx = -1;
    mint cnt = 0;
    for(int i = 0; i <= n; i++) {
        auto [m, c] = calc_max(i);
        if(m == mx){
            cnt += c;
        }else if(m > mx){
            mx = m;
            cnt = c;
        }
    }
    auto calc_left = [&](){
        int ans = 0;
        mint cnt = 1;
        for(int i = 0; i < n; i++){
            if(h[i].empty()) continue;
            if(pos[i].empty()) continue;
            auto count_less = [&](int x){
                int ans = 0;
                for(int a: h[i]) {
                    if(a <= x) ans++;
                }
                return ans;
            };
            int cl = count_less(pos[i].size());
            if(cl > 0){
                ans++;
                cnt *= cl;
            }
        }
        return make_pair(ans, cnt);
    };
    auto [mm, cc] = calc_left();
    if(mm == mx){
        cnt += cc;
    }
    if(mx == 0){
        cout << 0 << ' ' << 1 << endl;
        return 0;
    }
    cout << mx << ' ' << cnt << endl;
}