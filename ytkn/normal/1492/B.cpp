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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        set<int> st;
        for(int i = 1; i <= n; i++) st.insert(i);
        vector<int> ans;
        int r = n-1;
        while(!st.empty()){
            auto ptr = st.end();
            ptr--;
            int mx = *ptr; 
            for(int j = r; j >= 0; j--){
                if(p[j] == mx){
                    for(int i = j; i <= r; i++){
                        ans.push_back(p[i]);
                        st.erase(p[i]);
                    }
                    r = j-1;
                    break;
                }
            }
        }
        for(int x : ans) cout << x << ' ';
        cout << endl;
        assert(ans.size() == n);
    }
}