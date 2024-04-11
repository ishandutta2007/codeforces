#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>
#include <random>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

class Simulator{
    public:
    int n;
    int cnt;
    vector<int> p;
    Simulator(int _n){
        cnt = 0;
        n = _n;
        p.resize(n+1);
        random_device seed_gen;
        mt19937 engine(seed_gen());
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = i+1;
        shuffle(v.begin(), v.end(), engine);
        for(int i = 0; i < n; i++) p[i+1] = v[i];
    }
    int ask(int t, int i, int j, int x){
        assert(x >= 1);
        assert(x < n);
        cnt++;
        if(t == 1){
            return max(min(x, p[i]),min(x+1, p[i+1]));
        }else{
            return min(max(x, p[i]),max(x+1, p[i+1]));
        }
    }
    void verify(vector<int> ans){
        assert(ans.size() == n);
        if(cnt > (3*n)/2+30){
            cout << "asked more than " << (3*n)/2+30 << " times (" << cnt << ")" << endl; 
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(ans[i] != p[i+1]){
                ok = false;
                cout << i << "-th elements differ" << endl;
            }
        }
        if(ok) cout << "correct" << endl;
    }
};

// #define DEBUG

void solve(){
    int n; 
    #ifdef DEBUG
    n = 21;
    #else
    cin >> n;
    #endif
    #ifdef DEBUG
    auto sim = Simulator(n);
    #endif
    auto ask = [&](int t, int i, int j, int x){
        #ifdef DEBUG
        return sim.ask(t, i+1, j+1, x);
        #else
        cout << "? " << t << ' ' << i+1 << ' ' << j+1 << ' ' << x << endl;
        int ans; cin >> ans;
        return ans;
        #endif
    };
    auto verify = [&](vector<int> ans){
        #ifdef DEBUG
        sim.verify(ans);
        #else
        cout << "! ";
        for(int x : ans) cout << x << ' ';
        cout << endl;
        #endif
    };
    vector<int> ans(n);
    for(int i = 0; i+1 < n; i+=2){
        int s = ask(2, i, i+1, 1);
        if(s <= 2){
            if(ask(2, i, i+1, 1) == 1 || ask(2, i+1, i, 1) == 1) s = 1;   
        }
        int t = ask(1, i, i+1, n-1);
        if(t >= n-1){
            if(ask(2, i, i+1, n-1) == n || ask(2, i+1, i, n-1) == n) t = n;               
        }
        if(ask(2, i, i+1, s) == s){
            ans[i] = s;
            ans[i+1] = t;
        }else{
            ans[i] = t;
            ans[i+1] = s;
        }
    }

    if(n%2 == 1){
        vector<bool> used(n+1);
        for(int i = 0; i < n-1; i++) used[ans[i]] = true;
        for(int i = 1; i <= n; i++){
            if(!used[i]) {
                ans[n-1] = i;
            }
        }
    }
    verify(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}