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
#include <unordered_set>

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

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    unordered_set<ll> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.insert((ll)a*n+b);
        edges.insert((ll)b*n+a);
    }
    vector<int> last_update(n);
    vector<int> salary(n);
    vector<int> v(n);
    iota(salary.begin(), salary.end(), 0);
    iota(v.begin(), v.end(), 0);
    iota(last_update.begin(), last_update.end(), 0);
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int x; cin >> x; x--;
        v.push_back(x);
    }
    vector<ll> small(n), large(n);
    ll ans = 0;
    auto count = [&](int i){
        return small[i]*large[i];
    };
    for(int i = 0; i < n; i++){
        for(int j: g[i]){
            if(salary[j] > salary[i]) large[i]++;
            else small[i]++;
        }
        ans += small[i]*large[i];
    }
    cout << ans << endl;
    for(int i = n; i < n+q; i++){
        int x = v[i];
        int deg = g[x].size();
        int time_passed = i-last_update[x];
        ans -= count(x);
        if(deg < time_passed){
            for(int y: g[x]){
                if(salary[y] > salary[x]){
                    ans -= count(y);
                    small[y]--;
                    large[y]++;
                    ans += count(y);
                }
            }
        }else{
            for(int t = last_update[x]+1; t < i; t++){
                int y = v[t];
                if(t != last_update[y]) continue;
                ll u = (ll)x*n+y;
                if(edges.count(u) == 0) continue;
                if(salary[y] > salary[x]){
                    ans -= count(y);
                    small[y]--;
                    large[y]++;
                    ans += count(y);
                }
            }
        }
        salary[x] = i;
        small[x] = deg;
        large[x] = 0;
        last_update[x] = i;
        cout << ans << endl;
    }
}