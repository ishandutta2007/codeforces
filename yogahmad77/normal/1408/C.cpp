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
    int n;
    double l;
    cin >> n >> l;
    vector<double> a(n);
    for(double &i : a) cin >> i;
    auto b = a;
    reverse(ALL(b));
    double lo = 0.0, hi = l, mid, ans;
    for(int i = 0; i < 100; i++){
        mid = (lo + hi) / 2.0;
        double las = 0.0;
        double speed = 1.0;
        double time1 = 0.0;
        for(double x : a){
            if(x > mid) break;
            time1 += (x - las) / speed;
            speed += 1;
            las = x;
        }
        time1 += (mid - las) / speed;

        
        las = l;
        speed = 1.0;
        double time2 = 0.0;
        for(double x : b){
            if(x < mid) break;
            time2 += (las - x) / speed;
            speed += 1;
            las = x;
        }
        time2 += (las - mid) / speed;

        // debug(mid, time1, time2);

        if(time1 < time2){
            ans = time1;
            lo = mid;
        }
        else hi = mid;
    }
    cout << fixed << setprecision(9) << ans << '\n';
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