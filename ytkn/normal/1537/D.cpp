#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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
vector<bool> win(1000, false);

void init(){
    for(int i = 2; i <= 1000; i++){
        for(int j = 2; j < i; j++){
            if(i%j != 0) continue;
            if(!win[i-j]) win[i] = true;
        }
    }
}

int popcount(int n){
    int ans = 0;
    for(int i = 0; i < 30; i++){
        if(n&(1<<i)) ans++;
    }
    return ans;
}

int msb(int n){
    int ans = 0;
    for(int i = 30; i >= 0; i--){
        if(n&(1<<i)) return i;
    }
}

void solve(int n){
    if(n == 1){
        cout << "Bob" << endl;
    }else if(popcount(n) == 1){
        if(msb(n)%2 == 0) cout << "Alice" << endl;
        else cout << "Bob" << endl; 
    }else{
        if(n%2 == 0){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // init();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        solve(n);
    }
    // for(int i = 1; i <= 300; i++) {
    //     if(win[i]) cout << "Alice ";
    //     else cout << "Bob ";
    //     solve(i);
    // }
}