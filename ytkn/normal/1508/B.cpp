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
#include <stack>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    if(n <= 60){
        ll m = (ll)1<<(n-1);
        if(m < k){
            cout << -1 << endl;
            return;
        }
    }
    k--;
    vector<bool> used(n, true);
    for(int i = 0; i < n-1 && i < 60; i++){
        if(k&((ll)1<<i)) used[n-2-i] = false;
    }
    stack<int> st;
    // cout << "====" << endl;
    // for(int i = 0; i < n; i++) cout << used[i] << ' ';
    // cout <<endl;
    for(int i = 0; i < n; i++){
        if(used[i]){
            cout << i+1 << ' ';
            while(!st.empty()){
                cout << st.top()+1 << ' ';
                st.pop();
            }
        }else{
            st.push(i);
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}