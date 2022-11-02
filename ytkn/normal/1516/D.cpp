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

const int N_MAX = 100000;
vector<int> prime_facs[100001];

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

auto et = Eratosthenes(N_MAX);

void init(){
    for(int p: et.primes){
        for(int i = 1; i*p <= N_MAX; i++){
            prime_facs[i*p].push_back(p);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, q; cin >> n >> q;
    vector<vector<int>> indices(N_MAX+1);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int p: prime_facs[a[i]]) indices[p].push_back(i);
    }
    vector<int> pos(N_MAX+1, -1);
    for(int p: et.primes){
        if(!indices[p].empty()){
            pos[p] = indices[p].size()-1;
        }
    }
    auto nx = vec2d(20, n+1, n);
    for(int i = n-2; i >= 0; i--){
        nx[0][i] = nx[0][i+1];
        for(int p: prime_facs[a[i]]) {
            while(indices[p][pos[p]] != i) pos[p]--;
            if(pos[p]+1 != indices[p].size()){
                chmin(nx[0][i], indices[p][pos[p]+1]);
            }
        }
    }
    for(int i = 1; i < 20; i++){
        for(int j = 0; j < n; j++){
            nx[i][j] = nx[i-1][nx[i-1][j]];
        }
    }
    auto go = [&](int i, int cnt){
        int cur = i;
        for(int j = 0; j < 20; j++){
            if(cnt&(1<<j)) cur = nx[j][cur]; 
        }
        return cur;
    };
    auto solve = [&](int l, int r) -> int{
        if(go(l, 1) > r) return 1;
        int lb = 1, rb = n;
        while(rb-lb > 1){
            int c = (lb+rb)/2;
            if(go(l, c) <= r) lb = c;
            else rb = c;
        }
        return rb;
    };
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        cout << solve(l, r) << endl;
    }
    // for(int i = 0; i < n; i++) cout << nx[0][i] << ' ';
    // cout << endl;
}