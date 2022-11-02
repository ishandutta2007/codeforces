#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <numeric>
#include <functional>
#include <cassert>

// #define DEBUG

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

random_device rnd;

class Simulator{
    public:
    int n;
    int cnt = 0;
    vector<int> a;
    Simulator(int n): n(n){
        a = vector<int>(n);
        for(int i = 0; i < n; i++) a[i] = rnd()%n;
    }
    int query(string q, int i, int j){
        cnt++;
        assert(cnt <= n+1);
        assert(i < n);
        assert(j < n);
        if(q == "OR"){
            return a[i]|a[j];
        }else if(q == "XOR"){
            return a[i]^a[j];
        }else if(q == "AND"){
            return a[i]&a[j];
        }
        throw "invalid";
    }
    void answer(vector<int> ans){
        for(int x : a) cout << x << ' ';
        cout << endl;
        for(int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << endl;
        for(int i = 0; i < n; i++) assert(ans[i] == a[i]);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int m;
    for(int i = 0; i <= 16; i++){
        if(n&(1<<i)) m = i;
    }
    #ifdef DEBUG
    auto sim = Simulator(n);
    #endif
    auto query = [&](string q, int i, int j){
        #ifdef DEBUG
            return sim.query(q, i, j);
        #else
            cout << q << ' ' << i+1 << ' ' << j+1 << endl;
            int ans; cin >> ans;
            return ans;
        #endif
    };
    vector<int> xo(n);
    vector<int> used(n, -1);
    bool same = false;
    int l, r;
    for(int i = 1; i < n; i++) {
        int q = query("XOR", 0, i);
        if(!same && used[q] != -1){
            same = true;
            l = used[q], r = i;
        }
        used[q] = i;
        xo[i] = q;
    }
    vector<int> ans(n);
    if(!same){
        for(int i = 0; i < n; i++){
            if(used[i] > 0 && used[(n-1)^i] > 0){
                l = used[i], r = used[(n-1)^i];
                break;
            }
        }
    }
    if(same){
        int q = query("AND", l, r);
        ans[l] = q;
        ans[0] = xo[l]^ans[l];
        for(int i = 1; i < n; i++) ans[i] = ans[0]^xo[i]; 
    }else{
        int al = query("AND", 0, l);
        int ar = query("AND", 0, r);
        ans[0] = (al&((n-1)^xo[l])) + (ar&((n-1)^xo[r]));
        for(int i = 1; i < n; i++) ans[i] = ans[0]^xo[i]; 
    }
    #ifdef DEBUG
        sim.answer(ans);
    #else
        cout << "! ";
        for(int x : ans) cout << x << ' ';
        cout << endl;
    #endif
}