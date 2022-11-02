#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const int INF = 1e9;

string inv(string s){
    string ans;
    for(char c : s) ans += (c == '0' ? '1' : '0');
    return ans;
}

void solve_small(int n, int k, string s){
    string t = inv(s);
    set<int> st;
    int hash = 0;
    for(int i = 0; i < k; i++){
        hash *= 2;
        hash += t[i]-'0';
    }
    int mask = (1<<k)-1;
    st.insert(hash);
    for(int i = 1; i+k <= n; i++){
        hash = (hash*2+(t[i+k-1]-'0'))&mask;
        st.insert(hash);
    }
    if(st.size() == (1<<k)){
        cout << "NO" << endl;
        return;
    }
    int prev = -1;
    st.insert(INF);
    for(int x : st) {
        if(x != prev+1){
            cout << "YES" << endl;
            int hash = prev+1;
            for(int i = k-1; i >= 0; i--) {
                cout << (hash&(1<<i) ? 1 : 0);
            }
            cout << endl;
            return;
        }
        prev = x;
    }
}

void solve(int n, int k, string s){
    auto t = inv(s);
    vector<int> cumsum(n+1);
    for(int i = 0; i < n; i++){
        if(t[i] == '1') cumsum[i+1] = cumsum[i]+1;
        else cumsum[i+1] = cumsum[i];
    }
    int l = k-20;
    // t[i..i+k-1]l0
    auto ok = [&](int i){
        return (cumsum[i+l]-cumsum[i]) == 0;
    };
    int mask = (1<<20)-1;
    set<int> st;
    for(int i = 0; i+k <= n; i++){
        int hash = 0;
        if(ok(i)){
            // s[i+l, i+l+19]
            for(int j = i+l; j <= i+l+19; j++){
                hash = (hash*2+(t[j]-'0'))&mask;
            }
            st.insert(hash);
        }
    }
    st.insert(INF);
    int prev = -1;
    for(int x : st) {
        if(x != prev+1){
            cout << "YES" << endl;
            int hash = prev+1;
            for(int i = 0; i < l; i++) cout << 0;
            for(int i = 19; i >= 0; i--) {
                cout << (hash&(1<<i) ? 1 : 0);
            }
            cout << endl;
            return;
        }
        prev = x;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int q; cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if(k <= 20){
            solve_small(n, k, s);
        }else{
            solve(n, k, s);
        }
    }
}