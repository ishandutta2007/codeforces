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


template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

using P = pair<int, int>;
P NG(-1, -1);

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(char c: s){
            if(c == 'B') x[i]++;
            else y[i]++;
        }
    }
    auto f = [&](int l) -> P{
        int x_min = *min_element(x.begin(), x.end());
        int x_max = *max_element(x.begin(), x.end());
        int mx = x_min+l;
        int m = max({abs(x_min-l), abs(x_min+l), abs(x_max), abs(x_min)});
        OffsetVec<vector<int>> adds(m), changes(m);
        for(int i = 0; i < n; i++){
            adds[x[i]-l].push_back(i);
            changes[x[i]].push_back(i);
        }
        int l_max = -inf, r_min = inf;
        int l_diag_max = -inf, r_diag_min = inf;
        auto add = [&](int i){
            chmax(l_max, y[i]-l);
            chmin(r_diag_min, y[i]+l-x[i]);
        };
        auto change = [&](int i){
            chmax(l_diag_max, y[i]-l-x[i]);
            chmin(r_min, y[i]+l);
        };
        for(int x = x_min-l; x <= mx; x++){
            if(x > mx) continue;
            for(int i: adds[x]) add(i);
            for(int i: changes[x]) change(i);
            if(x < 0) continue;
            if(x < x_max-l) continue;
            int lm = max(l_max, l_diag_max+x);
            int rm = min(r_min, r_diag_min+x);
            if(lm > rm) continue;
            if(x == 0 && rm <= 0) continue;
            return P(x, rm);
        }
        return NG;
    };

    P f0 = f(0);
    if(f0 != NG){
        cout << 0 << endl;
        string ans;
        for(int i = 0; i < f0.first; i++) ans += 'B';
        for(int i = 0; i < f0.second; i++) ans += 'N';
        cout << ans << endl;
        return 0;
    }
    int x_max = *max_element(x.begin(), x.end());
    int y_max = *max_element(y.begin(), y.end());
    int l = 0, r = x_max+y_max+1;
    while(r-l > 1){
        int c = (l+r)/2;
        auto fc = f(c);
        if(fc == NG){
            l = c;
        }else{
            r = c;
        }
    }
    auto ff = f(r);
    string ans;
    for(int i = 0; i < ff.first; i++) ans += 'B';
    for(int i = 0; i < ff.second; i++) ans += 'N';
    cout << r << endl;
    cout << ans << endl;
}