#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(s[0] == '0' || s[n-1] == '0'){
        cout << "NO" << endl;
        return;
    }
    int cnt = 0;
    for(char c : s){
        if(c == '1') cnt++;
    }
    if(cnt%2 != 0){
        cout << "NO" << endl;
        return;
    }
    vector<int> c(2);
    cout << "YES" << endl;
    cout << "(";
    for(int i = 1; i < n-1; i++){
        if(s[i] == '0'){
            if(c[0]%2 == 0) cout << '(';
            else cout << ')';
            c[0]++;
        }else{
            if(c[1]+1 < cnt/2) cout << '(';
            else cout << ')';
            c[1]++;
        }
    }
    cout << ")" << endl;

    c[0] = 0; c[1] = 0;
    cout << "(";
    for(int i = 1; i < n-1; i++){
        if(s[i] == '0'){
            if(c[0]%2 == 0) cout << ')';
            else cout << '(';
            c[0]++;
        }else{
            if(c[1]+1 < cnt/2) cout << '(';
            else cout << ')';
            c[1]++;
        }
    }
    cout << ")" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}