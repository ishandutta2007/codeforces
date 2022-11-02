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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> cnt_elm(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_elm[a[i]]++;
    }
    auto cumsum = Cumsum<int>(cnt_elm);
    int xx = 1, yy = n;
    auto ok = [&](int x, int y){
        int sum = cumsum.sum(x, y+1);
        return sum-(n-sum) >= k;
    };
    auto change_ans = [&](int x, int y){
        if(yy-xx > y-x){
            xx = x;
            yy = y;
        }
    };
    for(int x = 1; x <= n; x++){
        if(ok(x, x)){
            change_ans(x, x);
            continue;
        }
        if(!ok(x, n)) continue;
        int l = x, r = n;
        while(r-l > 1){
            int y = (l+r)/2;
            if(ok(x, y)) r = y;
            else l = y;
        }
        change_ans(x, r);
    }
    cout << xx << ' ' << yy << endl;
    int l = 0;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(xx <= a[i] && a[i] <= yy) sum++;
        else sum--;
        if((sum == 1 && cnt+1 <k) || i+1 == n){
            cnt++;
            sum = 0;
            cout << l+1 << ' ' << i+1 << endl;
            l = i+1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}