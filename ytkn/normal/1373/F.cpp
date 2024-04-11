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

template<typename T>
void print_vec(vector<T> v){
    for(int x : v) cout << x << ' ';
    cout << endl;
}

const ll INF = 1e15;

bool judge(vector<ll> a, vector<ll> b, ll x){
    int n = a.size();
    b[0] -= x;
    a[1] -= x;
    for(int i = 1; i < n; i++){
        if(i != 0){
            if(a[i] > b[i]){
                return false;
            }
            ll d = min(a[i], b[i]);
            b[i] -= d;
            a[i] -= d;   
        } 
        int nx = (i+1)%n;        
        ll d = min(b[i], a[nx]);
        a[nx] -= d;
        b[i] -= d;
    }
    return true;
}

bool ok(vector<ll> a, vector<ll> b, ll x){
    int n = a.size();
    b[0] -= x;
    a[1] -= x;
    for(int i = 1; i < n; i++){
        if(i != 0){
            if(a[i] > b[i]){
                return false;
            }
            ll d = min(a[i], b[i]);
            b[i] -= d;
            a[i] -= d;   
        } 
        int nx = (i+1)%n;        
        ll d = min(b[i], a[nx]);
        a[nx] -= d;
        b[i] -= d;
    }
    return a[0] <= b[0]+b[n-1];
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int l = 0, r = min(a[1], b[0]);
    if(judge(a, b, l)){
        r = 0;
    }else if(!judge(a, b, r)){
        cout << "NO" << endl;
        return;
    }else{
        while(r-l > 1){
            int c = (l+r)/2;
            if(judge(a, b, c)) r = c;
            else l = c;
        }
    }
    if(ok(a, b, r)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}