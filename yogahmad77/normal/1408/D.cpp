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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i] >> d[i];
    priority_queue<pair<int, int>> pq[n];
    vector<pair<int, int>> naik;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] > c[j] || d[j] < b[i]) continue;
            pq[i].push({c[j], d[j]});
            naik.push_back({d[j] - b[i] + 1, i});
        }
    }
    sort(ALL(naik));
    int ans = 1e9;
    vector<int> berapa(n, 0);
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        if(!pq[i].empty()){
            berapa[i] = pq[i].top().f - a[i] + 1;
            q.push({pq[i].top().f - a[i] + 1, i});
        }
    }
    if(q.empty()) ans = 0;
    else ans = min(ans, q.top().f);

    for(auto x : naik){
        int i = x.s;
        while(!pq[i].empty() && pq[i].top().s < x.f + b[i]) pq[i].pop();
        if(!pq[i].empty()){
            berapa[i] = pq[i].top().f - a[i] + 1;
            q.push({pq[i].top().f - a[i] + 1, i});
        }
        else berapa[i] = 0;
        while(!q.empty() && berapa[q.top().s] != q.top().f) q.pop();
        if(q.empty()) ans = min(ans, x.f);
        else ans = min(ans, q.top().f + x.f);
    }
    cout << ans << '\n';

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