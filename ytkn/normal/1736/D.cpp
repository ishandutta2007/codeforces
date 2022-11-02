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

using P = pair<int, int>;

vector<P> run_length(string &s){
    int n = s.size();
    int pre = s[0]-'0';
    int cnt = 1;
    vector<P> ans;
    for(int i = 1; i < n; i++){
        int x = s[i]-'0';
        if(x == pre){
            cnt++;
        }else{
            ans.push_back(P(pre, cnt));
            pre = x;
            cnt = 1;
        }
    }
    ans.push_back(P(pre, cnt));
    return ans;
}

tuple<bool, vector<int>, vector<int>> solve(int n, string s){
    vector<int> u;
    for(char c: s) u.push_back(c-'0');
    vector<int> cnt(2);
    for(int i = 0; i < 2*n; i++) cnt[s[i]-'0']++;
    if(cnt[0]%2 == 1){
        return make_tuple(false, vector<int>(), vector<int>());
    }
    auto v = run_length(s);
    vector<int> b;
    int carry = 0;
    int idx = 0;
    for(auto [x, c]: v){
        if((c+carry)%2 == 1){
            bool ok = false;
            if(b.empty()) ok = true;
            else{
                if(u[b.back()] != x) ok = true;
            }
            if(ok){
                b.push_back(idx+c-1);
                carry = 1;
            }else{
                b.push_back(idx+c);
                carry = 1;
            }
        }else{
            carry = 0;
        }
        idx += c;
    }
    for(int idx: b){
        assert(idx < 2*n);
        if(s[idx] == '0') s[idx] = '1';
        else s[idx] = '0';
    }
    vector<int> p;
    idx = 0;
    for(auto [x, c]: run_length(s)){
        assert(c%2 == 0);
        for(int i = idx; i < idx+(c/2); i++){
            p.push_back(i);
        }
        idx += c;
    }
    return make_tuple(true, b, p);
}

void test(int n){
    for(int s = 0; s < (1<<(2*n)); s++){
        string t;
        for(int i = 0; i < 2*n; i++){
            if(s&(1<<i)) t += '1';
            else t += '0';
        }
        auto [f, b, p] = solve(n, t);
        if(f){
            int m = b.size();
            for(int i = 0; i < m; i++){
                int j = (i+1)%m;
                assert(t[b[i]] != t[b[j]]);
            }
            for(int i = 0; i < m; i++){
                if(t[b[i]] == '1') t[b[i]] = '0';
                else t[b[i]] = '1';
            }
            vector<bool> ff(2*n);
            for(int i: p) ff[i] = true;
            string sa, sb;
            for(int i = 0; i < 2*n; i++) {
                if(ff[i]) sa += t[i];
                else sb += t[i];
            }
            assert(sa == sb);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // int n; cin >> n;
    // test(n);
    // return 0;
    int t; cin >> t;
    while(t--) {
        int n; string s; cin >> n >> s;
        auto [f, b, p] = solve(n, s);
        if(!f){
            cout << -1 << "\n";
        }else{
            cout << b.size() << ' ';
            for(int x: b) cout << x+1 << ' ';
            cout << "\n";
            for(int x: p) cout << x+1 << ' ';
            cout << "\n";
        }
    }
}