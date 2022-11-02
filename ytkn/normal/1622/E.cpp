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
        cout << "\n";
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << "\n";
}

using P = pair<int, int>;
using T = tuple<int, int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<int> pcnt(1<<n);
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            if(i&(1<<j)) pcnt[i]++;
        }
    }
    vector<int> cnt(1<<n);
    vector<int> tt(m);
    for(int i = 0; i < m; i++){
        int t = 0;
        for(int j = 0; j < n; j++){
            if(s[j][i] == '1') {
                t += 1<<j;
            }
        }
        tt[i] = t;
        cnt[t]++;
    }
    ll ans = -1;
    vector<int> ans_v(m);
    int all_student = (1<<n)-1;
    for(int s = 0; s < (1<<n); s++){
        // s: r > x
        int others = all_student-s;
        vector<P> vp;
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) tmp -= x[i];
            else tmp += x[i];
        }
        // debug_value(tmp);
        for(int i = 0; i < m; i++){ // t
            int t = tt[i];
            int correct_pos = pcnt[s&t];
            int correct_neg = pcnt[others&t];
            vp.push_back(P(correct_pos-correct_neg, i));
        }
        sort(vp.begin(), vp.end(), greater<P>());
        int cur = m;
        for(auto [cnt_pos, _]: vp){
            tmp += cur*cnt_pos;
            cur -= 1;
        }
        if(chmax(ans, tmp)){
            int cur = m;
            for(auto [cnt_pos, i]: vp){
                ans_v[i] = cur;
                cur--;
            }
        }
        // debug_value(tmp);
        assert(cur == 0);
    }
    // debug_value(ans)
    // cout << ans << endl;
   
    print_vector(ans_v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}