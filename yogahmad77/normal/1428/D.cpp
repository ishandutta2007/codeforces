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
    cin >> n;
    vector<int> a(n), di(n), sama(n);
    for(int &i : a) cin >> i;
    set<int> sa, du;
    int idx = 0;
    for(int i = 0; i < n; i++) if(a[i] == 1){
        sa.insert(i);
        di[i] = idx++;
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] != 2) continue;
        auto it = sa.lower_bound(i);
        if(it == sa.end()){
            cout << -1 << '\n';
            return;
        }
        int x = *it;
        sa.erase(x);
        du.insert(i);
        di[i] = di[x];
    }
    for(int i : sa) du.insert(i);
    for(int i = n - 1; i >= 0; i--){
        if(a[i] != 3) continue;
        auto it = du.lower_bound(i);
        if(it == du.end()){
            cout << -1 << '\n';
            return;
        }
        int x = *it;
        du.erase(x);
        di[i] = idx++;
        sama[i] = x; 
        du.insert(i);
    }   
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) continue;
        if(a[i] <= 2){
            ans.push_back({n - di[i], i + 1});
        }
        else{
            ans.push_back({n - di[i], i + 1});
            ans.push_back({n - di[i], sama[i] + 1});
        }
    }
    cout << sz(ans) << '\n';
    for(auto x : ans) cout << x.first << ' ' << x.second << '\n';





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