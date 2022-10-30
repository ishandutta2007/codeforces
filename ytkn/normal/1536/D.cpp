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

void solve(){
    int n; cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    set<int> st;
    st.insert(b[0]);
    for(int i = 1; i < n; i++){
        auto p = st.find(b[i-1]);
        if(b[i] == b[i-1]) continue;
        if(b[i] > b[i-1]){
            p++;
            if(p == st.end()){
                st.insert(b[i]);
                continue;
            }
            if(*p < b[i]){
                cout << "No" << endl;
                return;
            }
            st.insert(b[i]);
        }else{
            if(p == st.begin()){
                st.insert(b[i]);
                continue;
            }
            p--;
            if(*p > b[i]){
                cout << "No" << endl;
                return;
            }
            st.insert(b[i]);
        }
    }
    cout << "Yes" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}