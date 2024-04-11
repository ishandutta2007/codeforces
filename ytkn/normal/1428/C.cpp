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
    string s; cin >> s;
    int ans = s.size();
    int cnta = 0, cntb = 0;
    int rem = 0;
    for(char c : s){
        if(c == 'A') cnta++;
        else{
            cntb++;
            if(cnta > 0) {
                ans -= 2;
                cnta--;
            }
            else rem++;
        }
    }
    ans -= (rem/2)*2;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}