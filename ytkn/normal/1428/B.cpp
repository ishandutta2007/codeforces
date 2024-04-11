#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    for(auto c : s) st.insert(c);
    if(st.size() == 3){
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '-' || s[(n+i-1)%n] == '-') ans++;
        }
        cout << ans << endl;
    }else if(st.size() == 2){
        if(st.count('-') > 0){
            cout << n << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        cout << n << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}