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
    int a, b, c; cin >> a >> b >> c;
    if(a == b && b == c){
        for(int i = 0; i < a; i++) cout << 1;
        cout << ' ';
        for(int i = 0; i < a; i++) cout << 1;
        cout << endl;
    }else if(a > b){
        cout << 1; for(int i = 0; i < a-c-1; i++) cout << 0;
        cout << 1; for(int i = 0; i < c-1; i++) cout << 0;
        cout << ' ';
        cout << 1; for(int i = 0; i < b-1; i++) cout << 0;
        cout << endl;
    }else{
        cout << 1; for(int i = 0; i < a-1; i++) cout << 0;
        cout << ' ';
        cout << 1; for(int i = 0; i < b-c-1; i++) cout << 0;
        cout << 1; for(int i = 0; i < c-1; i++) cout << 0;
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--){
        solve();
    }
}