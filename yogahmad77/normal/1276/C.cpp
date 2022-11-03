#include "bits/stdc++.h"
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

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), ada(n + 1, 0);
    map<int, int> cnt;

    for(int i = 0; i < n; i++) cin >> a[i], cnt[a[i]] += 1;
    for(auto i : cnt) ada[i.s] += i.s;
    for(int i = 1; i <= n; i++) ada[i] += ada[i - 1];
    for(auto i : cnt){
        for(int j = 1; j < i.s; j++) ada[j] += j;
    }
    int jaw = 0;
    int x, y;
    for(int i = 1; i <= n; i++){
        if(1LL * i * i > n) break;
        int j = ada[i] / i;
        if(j < i) continue;
        jaw = max(jaw, i * j);
        if(jaw == i * j){
            x = i;
            y = j;
        }
    }
    vector<int> apa;
    vector<pair<int, int>> isi;
    vector<vector<int>> ans(y, vector<int> (x));
    for(auto i : cnt){
        isi.push_back({i.f, min(i.s, x)});
    }
    sort(ALL(isi), [&](pair<int, int> i, pair<int, int> j){
        return i.s > j.s;
    });
    for(auto i : isi){
        for(int j = 0; j < i.s; j++) apa.pb(i.f);
    }
    cout << x * y << endl << y << ' ' << x << endl;
    for(int i = 0; i < y; i++){
        int I = i, J = 0;
        for(int j = 0; j < x; j++){
            ans[I][J] = apa[i * x + j];
            I = (I + 1) % y;
            J = (J + 1) % x;
        }
    }
    for(int i = 0; i < y; i++){
        
        for(int j = 0; j < x; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}