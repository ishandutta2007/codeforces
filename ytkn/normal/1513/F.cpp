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
using P = pair<int, int>;

int max_overwrap(vector<P> p1, vector<P> p2){
    int ans = 0;
    set<int> str;
    int idx2 = 0;
    int n1 = p1.size(), n2 = p2.size();
    for(auto [l1, r1]: p1){
        while(idx2 < n2 && p2[idx2].first <= l1) {
            str.insert(p2[idx2].second);
            idx2++;
        }
        auto p = str.upper_bound(r1);
        if(p != str.begin()){
            p--;
            int r2 = *p;
            chmax(ans, r2-l1);
        }
    }
    return ans;
}

int max_inclusion(vector<P> p1, vector<P> p2){
    int ans = 0;
    set<int> str;
    int idx2 = 0;
    int n1 = p1.size(), n2 = p2.size();
    for(auto [l1, r1]: p1){
        while(idx2 < n2 && p2[idx2].first <= l1) {
            str.insert(p2[idx2].second);
            idx2++;
        }
        auto p = str.lower_bound(r1);
        if(p != str.end()){
            chmax(ans, r1-l1);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    vector<P> p1, p2;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) p1.push_back(P(b[i], a[i]));
        if(a[i] < b[i]) p2.push_back(P(a[i], b[i]));
        ans += abs(a[i]-b[i]);
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    int max_gain = 0;
    chmax(max_gain, max_overwrap(p1, p2));
    chmax(max_gain, max_overwrap(p2, p1));
    chmax(max_gain, max_inclusion(p1, p2));
    chmax(max_gain, max_inclusion(p2, p1));
    cout << ans-max_gain*2 << endl;
}