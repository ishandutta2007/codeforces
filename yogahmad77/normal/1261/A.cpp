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
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

void solve(){
    string ss;
    int n, k;
    cin >> n >> k >> ss;
    vector<pair<int, int>> ans;
    for(int i = 0; i < (k - 1) * 2; i += 2){
        if(ss[i] != '('){
            for(int j = i + 1; j < n; j++){
                if(ss[j] == '('){
                    ans.pb({i, j});
                    // debug(i, j);
                    reverse(ss.begin() + i, ss.begin() + j + 1);
                    break;
                }
            }
        }
        // debug(ss, ss[i + 1]);
        if(ss[i + 1] != ')'){
            for(int j = i + 2; j < n; j++){
                if(ss[j] == ')'){
                    ans.pb({i + 1, j});
                    // debug(i + 1, j);
                    reverse(ss.begin() + i + 1, ss.begin() + j + 1);
                    break;
                }
            }
        }
        // debug(ss);
    }
    for(int i = (k - 1) * 2; i < n; i++){
        if(ss[i] == ')'){
            for(int j = i + 1; j < n; j++){
                if(ss[j] == '('){
                    ans.pb({i, j});
                    reverse(ss.begin() + i, ss.begin() + j + 1);
                    break;
                }
            }
        }
    }
    // debug(ss);
    cout << sz(ans) << '\n';
    for(auto i : ans) cout << i.f + 1 << ' ' << i.s + 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}