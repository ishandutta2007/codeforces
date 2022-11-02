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
#include <bitset>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

inline int pos(char c){
    return c-'a';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> cnt(26);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(i != n-2) sum += (ll)(1<<pos(s[i]));
        else sum -= (ll)(1<<pos(s[i]));
        if(i < n-2) cnt[pos(s[i])]++;
    }
    ll dif = sum-t;
    // cout << dif << endl;
    if(dif < 0){
        cout << "No" << endl;
        return 0;
    }
    for(int x = 25; x >= 0; x--){
        if((ll)cnt[x]*(ll)(1<<(x+1)) >= dif){
            dif %= (ll)(1<<(x+1));
        }else{
            dif -= (ll)cnt[x]*(ll)(1<<(x+1));
        }
    }
    if(dif == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}