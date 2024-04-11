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

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

istream & operator >> (istream &in,  __int128_t &m){
    string s; cin >> s;
    m = parse(s);
    return in;
}


ostream &operator<<(std::ostream &dest, __int128_t value) {
    ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = end(buffer);
        do {
        --d;
        *d = "0123456789"[tmp % 10];
        tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
        --d;
        *d = '-';
        }
        int len = end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
        dest.setstate(ios_base::badbit);
        }
    }
    return dest;
}


template <typename T>
T gcd(T a, T b) {
	if (a < b) swap(a, b);
		while (b != 0) {
			T tmp = b;
			b = a % b;
			a = tmp;
		}
	return a;
}

using ll = __int128_t;

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
class frac{
    public:
    T n, d;
    frac(T _n, T _d){
        T g = gcd(_n, _d);
        n = _n/g;
        d = _d/g;
        if(d < 0) {
            d *= -1;
            n *= -1;
        }
    }
    frac operator+(frac f){
        return frac(n*f.d+d*f.n, f.d*d);
    }
    frac operator-(frac f){
        return frac(n*f.d-d*f.n, f.d*d);
    }
    frac operator*(frac f){
        return frac(f.n*n, f.d*d);
    }
    frac inv(){
        return frac(d, n);
    }
    bool operator<(frac f){
        if(d*f.d < 0) return n*f.d-d*f.n > 0;
        else return n*f.d-d*f.n < 0;
    }
    bool operator>(frac f){
        if(d*f.d < 0) return n*f.d-d*f.n < 0;
        else return n*f.d-d*f.n > 0;
    }
    bool operator==(frac f){
        return n*f.d-d*f.n == 0;
    }
    void operator+=(frac f){
        n = n*f.d+d*f.n, d = f.d*d;
        reduction();
    }
    void operator-=(frac f){
        n = n*f.d-d*f.n, d = f.d*d;
        reduction();
    }
    void reduction(){
        T g = gcd(n, d);
        n /= g, d /= g;
    }
};

template <typename T>
bool operator<(const frac<T> f1, const frac<T> f2){
    if(f1.d*f2.d < 0) return f1.n*f2.d-f1.d*f2.n > 0;
    else return f1.n*f2.d-f1.d*f2.n < 0;
}

template <typename T>
bool operator>(const frac<T> f1, const frac<T> f2){
    if(f1.d*f2.d < 0) return f1.n*f2.d-f1.d*f2.n > 0;
    else return f1.n*f2.d-f1.d*f2.n > 0;
}

template <typename T>
bool operator==(const frac<T> f1, const frac<T> f2){
    return f1.n*f2.d-f1.d*f2.n == 0;
}

template <typename T>
ostream& operator<<(ostream& os, const frac<T>& f){
    os << f.n << '/' << f.d;
    return os;
}

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

struct edge{
    int to, idx;
    bool used;
};

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

using F = frac<ll>;
using P = pair<int, int>;

vector<P> ans;

void dfs_depth(int v, vector<vector<edge>> &g, vector<bool> &seen, int d, vector<int> &depth){
    seen[v] = true;
    depth[v] = d;
    for(edge e: g[v]){
        if(!seen[e.to]) dfs_depth(e.to, g, seen, d+1, depth);
    }
}

int dfs(int v, vector<vector<edge>> &g, vector<bool> &seen, vector<int> &depth){
    seen[v] = true;
    int m = g[v].size();
    vector<bool> used(m);
    vector<int> u;
    for(int i = 0; i < m; i++){
        edge &e = g[v][i];
        if(depth[e.to] < depth[v]) continue;
        if(!seen[e.to]) {
            int x = dfs(e.to, g, seen, depth);
            if(x != -1){
                ans.push_back(P(x, e.idx));
                used[i] = true;
            }
        }
        if(!used[i]) u.push_back(i);
    }
    for(int i = 0; i+1 < u.size(); i+=2){
        ans.push_back(P(g[v][u[i]].idx, g[v][u[i+1]].idx));
    }
    if(u.size()%2 == 0) return -1;
    int idx = u.back();
    return g[v][idx].idx;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<F> x, y;
    vector<F> f;
    for(int i = 0; i < n; i++){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        x.push_back(F(a, b));
        y.push_back(F(c, d));
        f.push_back((y[i]+F(1, 1))*(x[i].inv()));
        f.push_back((y[i])*((x[i]+F(1, 1)).inv()));
    }
    auto cp = Compress<F>(f);
    int m = cp.size();
    vector<vector<edge>> g(m);
    for(int i = 0; i < n; i++){
        F p1 = (y[i]+F(1, 1))*(x[i].inv());
        F p2 = (y[i])*((x[i]+F(1, 1)).inv());
        // p1 > p2;
        // assert(p1 > p2);
        int i1 = cp[p1];
        int i2 = cp[p2];
        g[i2].push_back(edge{i1, i, false});
        g[i1].push_back(edge{i2, i, false});
        // cout << i1 << ' ' << i2 << ' ' << i << endl;
    }
    vector<bool> seen(m);
    vector<bool> seen_depth(m);
    vector<int> depth(m);
    for(int i = 0; i < m; i++){
        if(!seen[i]) {
            dfs_depth(i, g, seen_depth, 0, depth);
            dfs(i, g, seen, depth);
        }
    }
    cout << ans.size() << endl;
    for(auto [i, j]: ans) cout << i+1 << ' ' << j+1 << endl;
}