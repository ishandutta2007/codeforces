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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

vector<int> gen_array(int n, int l, int r){
    int d = r-l;
    random_device rnd;
    mt19937 mt(rnd());
    vector<int> ans(n);
    int x = mt();
    for(int i = 0; i < n; i++) ans[i] = l+(mt()%d);
    return ans;
}
const int MAX_LEN = 2000;

class Simulator{
    public:
    int n, n_aksed;
    vector<int> l;
    Simulator(int n): n(n), n_aksed(0){
        l = gen_array(n, MAX_LEN, MAX_LEN+1);
    };
    int ask(int w){
        n_aksed++;
        for(int i = 0; i < n; i++){
            if(l[i] > w) return 0;
        }
        int sum = l[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(sum+1+l[i] > w){
                ans++;
                sum = l[i];
            }else{
                sum += 1+l[i];
            }
        }
        if(sum > 0) ans++;
        return ans;
    }
    void verify(int area){

        debug_value(n_aksed)
        debug_value(area)
        assert(n_aksed <= n+30);
    }
};


// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

const int inf = 1e9;
// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    map<int, int> memo;
    memo[n*MAX_LEN+(n-1)] = 1;
#ifdef DEBUG
    auto sim = Simulator(n);
#endif
    auto ask = [&](int w){
        if(memo.count(w)) return memo[w];
#ifdef DEBUG
        int ans = sim.ask(w);
#else
        cout << "? " << w << endl;
        int ans; cin >> ans;
#endif
        memo[w] = ans;
        return ans;
    };
    auto verify = [&](int area){
#ifdef DEBUG
        sim.verify(area);
#else
        cout << "! " << area << endl;
#endif
    };
    int l = 1, r = MAX_LEN;
    if(ask(1) == 0){
        while(r-l > 1){
            int w = (l+r)/2;
            if(ask(w) == 0) l = w;
            else r = w;
        }
    }else{
        l = 0;
    }
    int l_max = l+1;
    if(n == 1){
        verify(l_max);
        return 0;
    }
    l = l_max, r = n*MAX_LEN+(n-1);
    while(r-l > 1){
        int w = (l+r)/2;
        if(ask(w) == 1){
            r = w;
        }else{
            l = w;
        }
    }
    int ans = r;
    int sum_len = r-(n-1);
    for(int h = 2; h <= n-1; h++){
        int sum = sum_len+n-h;
        int w = ceil_div(sum, h);
        if(w < l_max) continue;
        if(h*w >= ans) continue;
        int hh = ask(w);
        chmin(ans, w*hh);
    }
    chmin(ans, l_max*n);
    verify(ans);
}