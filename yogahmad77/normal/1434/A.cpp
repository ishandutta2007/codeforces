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
    vector<int> a(6);
    for(int &i : a) cin >> i;
    cin >> n;
    vector<int> b(n);
    for(int &i : b) cin >> i;
    vector<pair<int, int>> ve;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 6; j++)
            ve.push_back({b[i] - a[j], i});
    sort(ALL(ve));
    vector<int> cnt(n, 0);
    int sum = 0, l = 0;
    int ans = 2e9;
    for(auto x : ve){
        while(sum < n && l < sz(ve)){
            cnt[ve[l].second] += 1;
            if(cnt[ve[l].second] == 1) sum += 1;
            l += 1;
        }
        if(sum == n){
            ans = min(ans, ve[l - 1].first - x.first);
        }

        cnt[x.second] -= 1;
        if(cnt[x.second] == 0) sum -= 1;
    }
    cout << ans << endl;
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