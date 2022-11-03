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

void cari(vector<pair<int, int>> &ans, vector<int> ve){
    if(sz(ve) == 1) return;
    int mid = sz(ve) / 2;
    vector<int> kiri, kanan;
    for(int i = 0; i < mid; i++){
        ans.push_back({ve[i], ve[i + mid]});
        kiri.push_back(ve[i]);
        kanan.push_back(ve[i + mid]);
    }
    cari(ans, kiri);
    cari(ans, kanan);
}

void solve(int tc){
    int n;
    cin >> n;
    if(n <= 2){
        cout <<  0 << endl;
        return;
    }
    if(n == 3){
        cout << 1 << endl;
        cout << 1 << ' ' << 2 << endl;
        return;
    }
    vector<pair<int, int>> ans;
    int besar = 0;
    for(int i = 0; i < 20; i++){
        if(n >= (1 << i)){
            besar = 1 << i;
        }
    }
    vector<int> kiri, kanan;
    for(int i = 1; i <= n; i++){
        if(sz(kiri) < besar){
            kiri.push_back(i);
        }
    }
    for(int i = n; i > 0; i--){
        if(sz(kanan) < besar){
            kanan.push_back(i);
        }
    }
    cari(ans, kiri);
    cari(ans, kanan);
    cout << sz(ans) << endl;
    for(auto x : ans) cout << x.f << ' ' << x.s << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}