#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);




const int mx = 1e5 + 10;


void solve(int tc){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b * c){
        cout << -1 << '\n';
        return;
    }
    if(c <= d){
        cout << a << '\n';
        return;
    }
    long long lo = 1, hi = 5e6, mid, ans = -1;
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(a - b * (mid - 1) * d >= 0){
            ans = mid;
            lo = mid + 1;
            // debug(a, b, c, d, d, a - b * (mid - 1) * d);
        }
        else hi = mid - 1;
    }
    // debug(ans);
    assert(ans != -1);
    long long banyak = ans;
    long long awal = a;
    long long akhir = a - b * (ans - 1) * d;
    long long jaw = (awal + akhir) * banyak / 2;
    cout << jaw << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}