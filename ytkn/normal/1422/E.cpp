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

using P = pair<char, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s; cin >> s;
    int n = s.size();
    vector<P> p;
    int cnt = 1;
    char pre = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] != pre){
            p.push_back(P(pre, cnt));
            cnt = 1;
            pre = s[i];
        }else{
            cnt++;
        }
    }
    p.push_back(P(pre, cnt));
    vector<int> pos(n);
    int m = p.size();
    vector<int> l(m), r(m);
    int idx = 0;
    for(int i = 0; i < m; i++){
        l[i] = idx;
        r[i] = idx+p[i].second;
        for(int j = idx; j < r[i]; j++) pos[j] = i;
        idx = r[i];
    }
    assert(idx == n);
    string nx(2, '#');
    vector<bool> should_erase(m);
    auto update_nx = [&](char c){
        if(c == nx[0]) return;
        nx[1] = nx[0];
        nx[0] = c;
    };
    for(int i = m-1; i >= 0; i--){
        auto [c, cnt] = p[i];
        if(c == nx[0]){
            should_erase[i] = nx[1] < c;
        }else{
            should_erase[i] = nx[0] < c;
        }
        if(cnt%2 == 0){
            if(should_erase[i]){

            }else{
                update_nx(c);
            }
        }else{
            update_nx(c);
        }
    }
    vector<int> ans_len(n);
    vector<string> ans(n);
    string t;
    // print_vector(should_erase);
    auto make_ans = [&](){
        if(t.size() > 10){
            int m = t.size();
            string prefix = t.substr(m-5, 5);
            string suffix = t.substr(0, 2);
            reverse(prefix.begin(), prefix.end());
            reverse(suffix.begin(), suffix.end());
            return prefix+"..."+suffix;
        }
        string ans = t;
        reverse(ans.begin(), ans.end());
        return ans;
    };
    for(int i = n-1; i >= 0; i--){
        int p = pos[i];
        if(!should_erase[p]){
            t += s[i];
        }
        if(should_erase[p] && (r[p]-i)%2 == 1){
            t += s[i];
        }
        ans[i] = make_ans();
        ans_len[i] = t.size();
        if(should_erase[p] && (r[p]-i)%2 == 1){
            t.pop_back();
        }
        if(i == l[p] && should_erase[p]){
            int len = (r[p]-l[p])%2;
            if(len == 1) t += s[i];
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans_len[i] << ' ' << ans[i] << "\n";
    }
}