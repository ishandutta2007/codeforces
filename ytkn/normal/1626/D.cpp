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

int nx[200005];
int msb[200005];

void init(){
    nx[0] = 1;
    for(int i = 1; i <= 200000; i++){
        for(int j = 0; j < 20; j++){
            if(i&(1<<j)) msb[i] = j;
        }
        if(i == (1<<msb[i])) nx[i] = 1<<msb[i];
        else nx[i] = 1<<(msb[i]+1);
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n+2);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    auto cumsum = Cumsum<int>(cnt);
    int ans = 2+(nx[n]-n);
    vector<int> l(20, -1), r(20, -1);
    for(int x = 1; x <= n+1; x++){
        int cur_sum = cumsum.sum(0, x);
        int nx_sum = cumsum.sum(0, x+1);
        if(nx[cur_sum] != nx[nx_sum] || x == n+1){
            int m = msb[nx[cur_sum]];
            l[m] = cur_sum;
        }
    }
    for(int x = 1; x <= n; x++){
        int cur_sum = cumsum.sum(x, n+2);
        int nx_sum = cumsum.sum(x-1, n+2);
        if(nx[cur_sum] != nx[nx_sum] || x == 1){
            int m = msb[nx[cur_sum]];
            r[m] = cur_sum;
        }
    }
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(l[i] + r[j] > n) continue;
            if(l[i] == -1) continue;
            if(r[j] == -1) continue;
            int a = 1<<i;
            int c = 1<<j;
            int b = nx[n-l[i]-r[j]];
            chmin(ans, (a+b+c)-n);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}