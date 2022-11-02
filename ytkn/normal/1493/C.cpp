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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(n%k != 0){
        cout << -1 << endl;
        return;
    }
    vector<int> cnt(26);
    for(auto c : s) cnt[c-'a']++;
    bool ok = true;
    for(int i = 0; i <  26; i++){
        if(cnt[i]%k != 0) ok = false;
    }
    if(ok){
        cout << s << endl;
        return;
    }
    // is
    for(int i = n-1; i >= 0; i--){
        int p = s[i]-'a';
        cnt[p]--;
        for(int j = p+1; j < 26; j++){
            cnt[j]++;
            vector<int> rem(26);
            for(int l = 0; l < 26; l++){
                rem[l] = (k-cnt[l]%k)%k;
            }
            int sum_rem = accumulate(rem.begin(), rem.end(), 0);
            if(i+1+sum_rem <= n){
                rem[0] += n-(i+sum_rem+1);
                for(int x = 0; x < i; x++) cout << s[x];
                cout << (char)('a'+j);
                for(int x = 0; x < 26; x++){
                    for(int y = 0; y < rem[x]; y++) cout << (char)('a'+x);
                }
                cout << endl;
                return;
            }
            cnt[j]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}