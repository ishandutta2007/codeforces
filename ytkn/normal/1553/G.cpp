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

class Eratosthenes{
    public:
    int m;
    vector<bool> is_prime;
    vector<int> primes;
    Eratosthenes(int m_){
        m = m_;
        init();
    }
    private:
    void init(){
        is_prime.assign(m+1, true);
        is_prime[0] = false, is_prime[1] = false;
        for(int i = 2; i <= m; i++){
            if(is_prime[i]){
                primes.push_back(i);
                for(int j = 2; i*j <= m; j++) is_prime[i*j] = false;
            }
        }
    }
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

const int N = 1000010;

auto et = Eratosthenes(N);
vector<int> prime_facs[N+1];

void init(){
    for(int p: et.primes){
        for(int i = 1; i*p <= N; i++){
            prime_facs[i*p].push_back(p);
        }
    }
}

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    UnionFind uf(N+1);
    for(int i = 0; i < n; i++){
        int m = prime_facs[a[i]].size();
        for(int j = 0; j < m-1; j++){
            uf.unionSet(prime_facs[a[i]][j], prime_facs[a[i]][j+1]);
        }
    }
    auto get_root = [&](int x){
        if(x == 1) return uf.root(1);
        return uf.root(prime_facs[x][0]);
    };
    set<P> edges;
    for(int i = 0; i < n; i++){
        int p = prime_facs[a[i]][0];
        int r = uf.root(p);
        for(int q: prime_facs[a[i]+1]){
            int qr = uf.root(q);
            if(r != qr){
                edges.insert(P(r, qr));
                edges.insert(P(qr, r));
            }
        }
        for(int j = 0; j < prime_facs[a[i]+1].size(); j++){
            for(int k = j+1; k < prime_facs[a[i]+1].size(); k++){
                int p = prime_facs[a[i]+1][j];
                int q = prime_facs[a[i]+1][k];
                int pr = uf.root(p);
                int qr = uf.root(q);
                if(pr != qr){
                    edges.insert(P(pr, qr));
                    edges.insert(P(qr, pr));
                }
            }
        }
    }
    while(q--){
        int s, t; cin >> s >> t; s--; t--;
        int rs = get_root(a[s]);
        int rt = get_root(a[t]);
        if(rs == rt){
            cout << 0 << endl;
        }else if(edges.count(P(rs, rt))){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
}