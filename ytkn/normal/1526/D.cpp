#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a <= b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

string ANTO = "ANTO";
inline int to_idx(char c){
    if(c == 'A') return 0;
    if(c == 'N') return 1;
    if(c == 'T') return 2;
    if(c == 'O') return 3;
}

using P = pair<int, int>;

ll count_inv(string s, string t){

    // cout << t << endl;
    int n = s.size();
    map<P, int> mp;
    vector<int> cnt(4);
    for(int i = 0; i < n; i++){
        char c = s[i];
        int idx = to_idx(c);
        cnt[idx]++;
        mp[P(idx, cnt[idx])] = i+1;
    }
    cnt.assign(4, 0);
    ll ans = 0;
    bit<ll> bt(n);
    for(int i = 0; i < n; i++){
        char c = t[i];
        int idx = to_idx(c);
        cnt[idx]++;
        int j = mp[P(idx, cnt[idx])];
        ans += i-bt.sum(j);
        bt.add(j, 1);
    }
    return ans;
}

void solve(){
    string s; cin >> s;
    vector<int> cnt(4);
    for(char c : s){
        cnt[to_idx(c)]++;
    }
    vector<int> v = {0, 1, 2, 3};
    string ans;
    ll mx = 0;
    do{
        string t;
        for(int i : v){
            for(int j = 0; j < cnt[i]; j++) t += ANTO[i];
        }
        if(chmax(mx, count_inv(s, t))){
            ans = t;
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

void test(){
    vector<string> s = {
        "ANTON",
        "NAAN",
        "AAAAAA",
        "OAANTTON"
    };
    vector<string> t = {
        "NNOTA",
        "AANN",
        "AAAAAA",
        "TNNTAOOA"
    };
    for(int i = 0; i < s.size(); i++){
        cout << count_inv(s[i], t[i]) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
    // test();
}