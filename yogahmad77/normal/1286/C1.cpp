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

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 1e5 + 10;

map<string, int> tanya(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int n = r - l + 1;
    n = n * (n + 1) / 2;
    map<string, int> ret;
    for(int i = 0; i < n; i++){
        string ss;
        cin >> ss;
        sort(ALL(ss));
        ret[ss] += 1;
    }
    return ret;
}

void solve(){
    int n;
    cin >> n;
    auto sa = tanya(1, n);
    if(n == 1){
        for(auto i : sa){
            cout << "! " << i.f << endl;
            return;
        }
    }
    auto du = tanya(1, n - 1);
    map<string, int> gabung;
    for(auto i : sa) gabung[i.f] += i.s;
    for(auto i : du) gabung[i.f] -= i.s;
    vector<char> ans(n);
    for(int i = n - 1; i >= 0; i--){
        int leng = n - i;
        for(auto x : gabung){
            if(sz(x.f) == leng && x.s > 0){
                assert(x.s == 1);
                map<char, int> ini;
                for(auto j : x.f){
                    ini[j] += 1;
                }
                for(int j = i + 1; j < n; j++) ini[ans[j]] -= 1;
                for(auto j : ini){
                    if(j.s > 0){
                        ans[i] = j.f;
                    }
                }
                break;
            }
        }
    }
    cout << "! ";
    for(auto i : ans) cout << i;
    cout << endl;
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        solve();
    }
}