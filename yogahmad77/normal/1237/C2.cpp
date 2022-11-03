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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
#define MOD 1000000007 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n), sudah(n, 0);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];
    vector<int> ve;
    map<pair<int, int>, vector<int>> ini;
    for(int i = 0; i < n; i++){
        ini[{x[i], y[i]}].pb(i);
    }
    map<int, vector<int>> itu;
    for(auto i : ini){
        sort(ALL(i.s), [&](int a, int b){
            return z[a] < z[b];
        });
        int tadi = -1;
        for(int j : i.s){
            if(tadi == -1)
                tadi = j;
            else{
                cout << tadi + 1 << ' ' << j + 1 << '\n';
                tadi = -1;
            }
        }
        if(tadi != -1){
            itu[x[tadi]].pb(tadi);
        }
    }
    for(auto i : itu){
        sort(ALL(i.s), [&](int a, int b){
            return y[a] < y[b];
        });
        int tadi = -1;
        for(int j : i.s){
            if(tadi == -1)
                tadi = j;
            else{
                cout << tadi + 1 << ' ' << j + 1 << '\n';
                tadi = -1;
            }
        }
        if(tadi != -1){
            ve.pb(tadi);
        }
    }
    sort(ALL(ve), [&](int a, int b){
        return x[a] < x[b];
    });
    int tadi = -1;
    for(int j : ve){
        if(tadi == -1)
            tadi = j;
        else{
            cout << tadi + 1 << ' ' << j + 1 << '\n';
            tadi = -1;
        }
    }
    assert(tadi == -1);
}