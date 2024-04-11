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

string ss;
int n;

int score(int i){
    if(ss[i] == 'W') return 0;
    int ret = 1;
    if(i + 1 < n && ss[i + 1] == 'W') ret += 1;
    if(i > 0 && ss[i - 1] == 'W') ret += 1;
    return ret; 
}

void solve(int tc){
    int k;
    cin >> n >> k;
    cin >> ss;
    int tadi = -1;
    vector<pair<int, pair<int, int>>> ve;
    for(int i = 0; i < n; i++){
        if(ss[i] == 'W'){
            int x = i - tadi - 1;
            if(x > 0){
                ve.push_back({x, {tadi + 1, i - 1}});
            }
            tadi = i;
        }
    }
    int x = n - tadi - 1;
    if(x > 0){
        ve.push_back({x, {tadi + 1, n - 1}});
    }
    sort(ALL(ve));
        for(auto x : ve){
            if(x.s.f == 0 || x.s.s == n - 1) continue;
            for(int i = x.s.f; i <= x.s.s; i++){
                if(k){
                    ss[i] = 'W';
                    k -= 1;
                }
            }
        }
        for(auto x : ve){
            if(x.s.f == 0){
                for(int i = x.s.s; i >= 0; i--){
                    if(k){
                        ss[i] = 'W';
                        k -= 1;
                    }
                }
            }
            else if(x.s.s == n - 1){
                for(int i = x.s.f; i < n; i++){
                    if(k){
                        ss[i] = 'W';
                        k -= 1;
                    }
                }
            }
            
        }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(ss[i] == 'W'){
            if(i > 0 && ss[i - 1] == 'W') ans += 2;
            else ans += 1;
        }
    }
    cout << ans << '\n';
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