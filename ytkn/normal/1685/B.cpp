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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    string s; cin >> s;
    int cnt_a = 0, cnt_b = 0;
    for(char c: s){
        if(c == 'A') cnt_a++;
        if(c == 'B') cnt_b++;
    }
    if(cnt_a != a+c+d){
        cout << "NO" << '\n';
        return;
    }
    if(cnt_b != b+c+d){
        cout << "NO" << '\n';
        return;
    }
    int n = s.size();
    string t;
    t += s[0];
    int p = 0;
    vector<int> va, vb;
    auto add = [&](string t){
        if(t.size()%2 == 1){
            p += t.size()/2;
            return;
        }
        if(t[0] == 'A'){
            va.push_back(t.size()/2);
        }else{
            vb.push_back(t.size()/2);
        }
    };
    for(int i = 1; i < n; i++){
        if(t.back() == s[i]){
            if(t.size() > 1) add(t);
            t.clear();
        }
        t += s[i];
    }
    if(t.size() > 1) add(t);
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    auto ca = Cumsum<int>(va);
    auto cb = Cumsum<int>(vb);
    int ma = va.size();
    int mb = vb.size();
    auto count_rem_a = [&](int x){
        assert(ca.sum(0, ma) >= x);
        if(ca.sum(0, ma) == x) return 0;
        int l = 0, r = ma;
        while(r-l > 1){
            int c = (l+r)/2;
            if(ca.sum(0, c) > x){
                r = c;
            }else{
                l = c;
            }
        }
        int c_rem = ma-r;
        return ca.sum(0, ma)-x-c_rem-1;
    };

    auto count_rem_b = [&](int x){
        assert(cb.sum(0, mb) >= x);
        if(cb.sum(0, mb) == x) return 0;
        int l = 0, r = mb;
        while(r-l > 1){
            int c = (l+r)/2;
            if(cb.sum(0, c) > x){
                r = c;
            }else{
                l = c;
            }
        }

        int c_rem = mb-r;
        return cb.sum(0, mb)-x-c_rem-1;
    };
    for(int aa = p; aa >= 0; aa--){
        int bb = p-aa;
        if(aa + ca.sum(0, ma) >= c){
            if(bb + cb.sum(0, mb) >= d){
                cout << "YES" << endl;
                return;
            }
            int rem = d - (bb + cb.sum(0, mb));
            if(count_rem_a(c-aa) >= rem){
                cout << "YES" << endl;
                return;
            }
        }else if(bb + cb.sum(0, mb) >= d){
            if(aa + ca.sum(0, ma) >= c){
                cout << "YES" << endl;
                return;
            }
            int rem = c - (aa + ca.sum(0, ma));
            if(count_rem_b(d-bb) >= rem){
                cout << "YES" << endl;
                return;
            }
        }else{
            continue;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}