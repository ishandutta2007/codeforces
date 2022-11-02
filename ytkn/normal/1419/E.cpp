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

auto et = Eratosthenes(33000);
using P = pair<int, int>;

vector<P> factorize(int n){
    int m = n;
    vector<P> ans;
    for(int p: et.primes){
        if(p*p > n) break;
        int cnt = 0;
        while(m%p == 0){
            cnt++;
            m /= p;
        }
        if(cnt > 0) ans.push_back(P(p, cnt));
    }
    if(m != 1) ans.push_back(P(m, 1));
    return ans;
}

vector<int> list_facs(int n){
    vector<int> ans;
    for(int x = 1; x*x <= n; x++){
        if(n%x == 0){
            if(x != 1) ans.push_back(x);
            if(x*x != n) ans.push_back(n/x);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int n; cin >> n;
    auto facs = list_facs(n);
    auto vp = factorize(n);
    if(vp.size() == 1){
        print_vector(facs);
        cout << 0 << endl;
        return;
    }
    int m = vp.size();
    vector<int> end(m);
    set<int> bounds;
    // print_vector(facs);
    // for(int i = 0; i < m; i++) cout << vp[i].first << '^' << vp[i].second << ' ';
    // cout << endl;
    if(vp.size() == 2){
        if(vp[0].second == 1) swap(vp[0], vp[1]);
        auto [p1, c1] = vp[0];
        auto [p2, c2] = vp[1];
        if(c1 == 1){
            cout << p1 << ' ' << p2 << ' ' << p1*p2 << endl;
            cout << 1 << endl;
            return;
        }else{
            end[0] = p1*p2;
            end[1] = p1*p1*p2;
            bounds.insert(p1*p2);
            bounds.insert(p1*p1*p2);
        }
    }else{
        for(int i = 0; i < m; i++){
            int p1 = vp[i].first;
            int p2 = vp[(i+1)%m].first;
            bounds.insert(p1*p2);
            end[i] = p1*p2;
        }
    }
    vector<vector<int>> v(m);
    for(int x: facs){
        if(bounds.count(x)) continue;
        for(int i = 0; i < m; i++){
            int p = vp[i].first;
            if(x%p == 0){
                v[i].push_back(x);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int x: v[i]) cout << x << ' ';
        cout << end[i] << ' ';
    }
    cout << endl;
    cout << 0 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}