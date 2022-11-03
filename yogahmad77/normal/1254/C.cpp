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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int x[mx], y[mx];

long long tanya1(int i, int j, int k){
    cout << 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    // return abs(x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - y[i] * x[j] - y[j] * x[k] - y[k] * x[i]);
    long long ret;
    cin >> ret;
    return ret;
}

int tanya2(int i, int j, int k){
    cout << 2 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    // long long xa = x[j] - x[i], xb = x[k] - x[i], ya = y[j] - y[i], yb = y[k] - y[i];
    // if(xa * yb - xb * ya < 0) return -1;
    // return 1;
    int ret;
    cin >> ret;
    return ret;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // for(int i = 0; i < n; i++){
    //     cin >> x[i] >> y[i];
    // }
    vector<int> a(n);
    iota(ALL(a), 0);
    vector<int> kiri, kanan;
    vector<long long> val(n);
    for(int i = 2; i < n; i++){
        int sign = tanya2(0, 1, i);
        long long luas = tanya1(0, 1, i);
        if(sign == -1) kanan.pb(i);
        else kiri.pb(i);
        val[i] = luas;
    }
    int makskiri = -1, makskanan = -1;
    for(int i : kiri){
        if(makskiri == -1 || val[i] > val[makskiri]) makskiri = i;
    }
    for(int i : kanan){
        if(makskanan == -1 || val[i] > val[makskanan]) makskanan = i;
    }
    vector<int> kirikiri, kirikanan, kanankanan, kanankiri;
    for(int i : kiri){
        if(i == makskiri) continue;
        int sign = tanya2(0, makskiri, i);
        if(sign == 1) kirikiri.pb(i);
        else kirikanan.pb(i);
    }
    for(int i : kanan){
        if(i == makskanan) continue;
        int sign = tanya2(0, makskanan, i);
        if(sign == -1) kanankanan.pb(i);
        else kanankiri.pb(i);
    }
    sort(ALL(kirikiri), [&](int x, int y){
        return val[x] > val[y];
    });
    sort(ALL(kirikanan), [&](int x, int y){
        return val[x] < val[y];
    });
    sort(ALL(kanankanan), [&](int x, int y){
        return val[x] < val[y];
    });
    sort(ALL(kanankiri), [&](int x, int y){
        return val[x] > val[y];
    });
    vector<int> ans;
    ans.pb(0);
    for(int i : kanankanan) ans.pb(i);
    if(makskanan != -1)ans.pb(makskanan);
    for(int i : kanankiri) ans.pb(i);
    ans.pb(1);
    for(int i : kirikanan) ans.pb(i);
    if(makskiri != -1) ans.pb(makskiri);
    for(int i : kirikiri) ans.pb(i);
    cout << 0;
    for(int i : ans) cout << ' ' << i + 1;
    cout << endl;
}