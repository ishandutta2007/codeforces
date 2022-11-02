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

int tri(int n){
    return (n*(n+1))/2;
}

vector<int> count(string &s){
    vector<int> ans(26);
    for(char c: s) ans[c-'a']++;
    return ans;
}

vector<vector<int>> diff(vector<vector<int>> u, vector<vector<int>> v){
    assert(u.size() > v.size());
    map<vector<int>, int> mpu, mpv;
    for(auto w: u){
        if(mpu.count(w)) mpu[w]++;
        else mpu[w] = 1;
    }
    for(auto w: v){
        if(mpv.count(w)) mpv[w]++;
        else mpv[w] = 1;
    }
    vector<vector<int>> ans;
    for(auto [w, cnt]: mpu){
        if(mpv.count(w) == 0) ans.push_back(w);
        else if(mpv[w] != cnt) ans.push_back(w);
    }
    return ans;
}

#define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    auto ask = [&](int l, int r){
        cout << "? " << l+1 << ' ' << r+1 << endl;
        vector<vector<int>> v;
        for(int i = 0; i < tri(r-l+1); i++){
            string s; cin >> s;
            v.push_back(count(s));
        }
        return v;
    };
    auto verify = [&](string s){
        cout << "! " << s << endl;
    };
    auto u = ask(0, n-1);
    if(n == 1){
        string ans;
        for(int i = 0; i < 26; i++){
            if(u[0][i] == 1) ans += 'a'+i;
        }
        verify(ans);
        return 0;
    }
    auto v = ask(1, n-1);
    auto d = diff(u, v);
    string ans;
    assert(d.size() == n);
    vector<int> idx(n+1, -1);
    for(int i = 0; i < n; i++){
        int sum = accumulate(d[i].begin(), d[i].end(), 0);
        assert(idx[sum] == -1);
        idx[sum] = i;
    }
    for(int i = 1; i <= n; i++){
        vector<int> pre = i == 1 ? vector<int>(26, 0): d[idx[i-1]];
        vector<int> cur = d[idx[i]];
        for(int j = 0; j < 26; j++){
            if(pre[j] != cur[j]){
                ans += 'a'+j;
            }
        }
    }
    verify(ans);
}