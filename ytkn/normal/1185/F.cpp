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

const ll inf = 1e18;
using P = pair<ll, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> count_likes(1<<9);
    for(int i = 0; i < n; i++){
        int f; cin >> f;
        int s = 0;
        for(int j = 0; j < f; j++){
            int b; cin >> b; b--;
            s |= 1<<b;
        }
        count_likes[s]++;
    }
    vector<vector<P>> prices(1<<9);
    for(int i = 0; i < m; i++){
        ll c; cin >> c;
        int r; cin >> r;
        int s = 0;
        for(int j = 0; j < r; j++){
            int a; cin >> a; a--;
            s += 1<<a;
        }
        prices[s].push_back(P(c, i));
    }
    for(int s = 0; s < (1<<9); s++) sort(prices[s].begin(), prices[s].end());
    vector<int> cnt_subset(1<<9);
    for(int s = 0; s < (1<<9); s++){
        for(int t = 0; t < (1<<9); t++){
            if((s|t) == s) cnt_subset[s] += count_likes[t];
        }
    }
    int max_student = -1;
    ll min_price = inf;
    int ans_i = -1, ans_j = -1;
    for(int s = 0; s < (1<<9); s++) sort(prices[s].begin(), prices[s].end());
    for(int s = 0; s < (1<<9); s++){
        if(prices[s].empty()) continue;
        for(int t = s; t < (1<<9); t++){
            if(prices[t].empty()) continue;
            if(s == t && prices[s].size() == 1) continue;
            int u = s|t;
            ll p = 0;
            if(s == t){
                p = prices[s][0].first+prices[s][1].first;
            }else{
                p = prices[s][0].first+prices[t][0].first;
            }
            if(max_student < cnt_subset[u]){
                max_student = cnt_subset[u];
                min_price = p;
                if(s == t){
                    ans_i = prices[s][0].second;
                    ans_j = prices[s][1].second;
                }else{
                    ans_i = prices[s][0].second;
                    ans_j = prices[t][0].second;
                }
            }else if(max_student == cnt_subset[u]){
                if(chmin(min_price, p)){
                    if(s == t){
                        ans_i = prices[s][0].second;
                        ans_j = prices[s][1].second;
                    }else{
                        ans_i = prices[s][0].second;
                        ans_j = prices[t][0].second;
                    }
                }
            }
        }
    }
    cout << ans_i+1 << ' ' << ans_j+1 << endl;
}