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

string solve(string s){
    int n = s.size();
    reverse(s.begin(), s.end());
    while(!s.empty() && s.back() == '0'){
        s.pop_back();
    }
    if(s.empty()){
        return "0";
    }
    reverse(s.begin(), s.end());
    bool all_one = true;
    for(char c: s){
        if(c == '0') all_one = false;
    }
    if(all_one){
        return s;
    }
    n = s.size();
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            idx = i;
            break;
        }
    }
    vector<int> candidate;
    for(int i = 0; i < idx; i++) candidate.push_back(i);
    string ans = string(idx+1, '1');
    for(int i = idx+1; i < n; i++){
        if(candidate.empty()){
            ans += s[i];
            continue;
        }
        int x = s[i]-'0';
        int offset = i-idx;
        vector<int> nx;
        for(int j: candidate){
            int y = s[j+offset]-'0';
            if((x|y) == 1) nx.push_back(j);
        }
        if(nx.empty()) {
            ans += '0';
        }else{
            ans += '1';
            candidate = nx;
        }
    }
    return ans;
}

int to_int(string s){
    // reverse(s.begin(), s.end());
    int ans = 0;
    for(char c: s){
        int x = c-'0';
        ans = ans*2+x;
    }
    return ans;
}

int or_str(string s, string t){
    int x = to_int(s)|to_int(t);
    return x;
}

string naive(string s){
    int n = s.size();
    vector<string> v;
    for(int l = 0; l < n; l++){
        for(int len = 1; l+len <= n; len++){
            v.push_back(s.substr(l, len));
        }
    }
    int mx = 0;
    for(string s: v){
        for(string t: v){
            auto x = or_str(s, t);
            chmax(mx, x);
        }
    }
    if(mx == 0) return "0";
    string ans;
    while(mx){
        ans += '0'+(mx%2);
        mx /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void test(int n){
    for(int s = 0; s < (1<<n); s++){
        string t;
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) t += '1';
            else t += '0';
        }
        if(solve(t).size() > 1) assert(solve(t)[0] != '0');
        if(solve(t) != naive(t)){
            debug(t)
            cout << t << ' ' << solve(t) << ' ' << naive(t) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // test(10);
    // debug('H')
    int n; cin >> n;
    string s; cin >> s;
    cout << solve(s) << endl;
}