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

const string AGCT = "AGCT";

pair<int, vector<string>> solve(int n, int m, vector<string> &s){
    int ans = 1e9;
    vector<string> ans_s = s;
    vector<string> work = s;
    for(int t = 0; t < 16; t++){
        vector<string> a(2);
        for(int i = 0; i < 4; i++){
            if(t&(1<<i)) a[0] += AGCT[i];
            else a[1] += AGCT[i];
        }
        if(a[0].size() != a[1].size()) continue;
        int diff_sum = 0;
        for(int i = 0; i < n; i++){
            int idx = i%2;
            int min_diff = m;
            int min_k = 0;
            for(int k = 0; k < 2; k++){
                int cnt = 0;
                for(int j = 0; j < m; j++){
                    int pos = (j%2)^k;
                    if(a[idx][pos] != s[i][j]) cnt++;
                }
                if(chmin(min_diff, cnt)) min_k = k;
            }
            for(int j = 0; j < m; j++){
                int pos = (j%2)^min_k;
                work[i][j] = a[idx][pos];
            }
            diff_sum += min_diff;
        }
        if(chmin(ans, diff_sum)) ans_s = work;
    }
    return make_pair(ans, ans_s);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<string> t(m, string(n, 'A'));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            t[i][j] = s[j][i];
        }
    }
    auto [ans, ans_s] = solve(n, m, s);
    auto [ans1, ans_s1] = solve(m, n, t);
    if(chmin(ans, ans1)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans_s[i][j] = ans_s1[j][i];
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cout << ans_s[i] << '\n';
        for(int j = 0; j < m; j++){
            if(s[i][j] != ans_s[i][j]) cnt++;
        }
    }
    assert(cnt == ans);
}