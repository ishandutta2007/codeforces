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

const int N_MAX = 1000000;
int norm[N_MAX+1];
bool used[N_MAX+1];
vector<int> facs[N_MAX+1];
auto et = Eratosthenes(N_MAX);

void init(){
    for(int i = 1; i <= N_MAX; i++) norm[i] = i;
    for(int i = 2; i*i <= N_MAX; i++){
        int x = i*i;
        for(int j = 1; x*j <= N_MAX; j++){
            while(norm[x*j]%x == 0) norm[x*j] /= x;
        }
    }
    for(int p: et.primes){
        for(int j = 1; j*p <= N_MAX; j++){
            facs[p*j].push_back(p);
        }
    }
}

const int inf = 1e9;

vector<int> make_input(int n){
    vector<int> ans;
    set<int> used;
    for(int x = 1; ans.size() < n; x++){
        if(norm[x] == 1) continue;
        if(used.count(norm[x])) continue;
        ans.push_back(x);
        used.insert(norm[x]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n; cin >> n;
    vector<int> a(n);
    // a = make_input(n);
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        // int x = a[i];
        a[i] = norm[x];
    }
    for(int x: a){
        if(x == 1){
            cout << 1 << endl;
            return 0;
        }
    }
    vector<int> ps;
    for(int x: a){
        if(used[x]){
            cout << 2 << endl;
            return 0;
        }
        used[x] = true;
        for(int p: facs[x]) ps.push_back(p);
    }
    auto cp = Compress<int>(ps, 1);
    int m = cp.size()+1;
    vector<vector<int>> g(m);
    auto add_edge = [&](int i, int j){
        g[i].push_back(j);
        g[j].push_back(i);
    };
    for(int x: a){
        if(facs[x].size() == 1){
            int p = facs[x][0];
            add_edge(0, cp[p]);
        }else{
            int p = facs[x][0];
            int q = facs[x][1];
            add_edge(cp[p], cp[q]);
        }
    }
    int ans = inf;
    vector<int> dist(m, inf);
    for(int i = 0; i < m; i++){
        ll p = i == 0 ? 1 : cp.data[i-1];
        if(p*p > N_MAX) continue;
        dist.assign(m, inf);
        queue<int> que;
        que.push(i);
        dist[i] = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int u: g[v]){
                if(chmin(dist[u], dist[v]+1)){
                    que.push(u);
                }else{
                    if(dist[u] == dist[v]+1 || dist[u] == dist[v]) chmin(ans, dist[u]+dist[v]+1);
                }
            }
        }
        // debug_value(i);
        // debug_value(ans);
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}