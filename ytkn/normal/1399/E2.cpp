#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

struct edge{
    int to;
    int c;
    ll w;
};

const ll INF = 1e18;
ll min_sum[2][2500000];
vector<edge> G[100000];
bool used[100000];

priority_queue<P> que1, que2;
vector<ll> v1, v2;

int dfs(int v){
    used[v] = true;
    int ret = 0;
    bool is_leaf = true;
    for(edge e: G[v]){
        if(!used[e.to]){
            ll ch = dfs(e.to);
            ret += ch;
            is_leaf = false;
            if(e.c == 1){
                min_sum[0][0] += ch*e.w;
                ll w = e.w;
                while(w > 0){
                    v1.push_back(w*ch-(w/2)*ch);
                    w /= 2;
                }
            }else{
                min_sum[1][0] += ch*e.w;
                ll w = e.w;
                while(w > 0){
                    v2.push_back(w*ch-(w/2)*ch);
                    w /= 2;
                }
            }
        }
    }
    if(is_leaf) ret++;
    return ret;
}

void solve(){
    int n; ll s; cin >> n >> s;
    for(int i = 0; i < n-1; i++){
        int u, v, c; ll w;
        cin >> u >> v >> w >> c; u--; v--;
        G[u].push_back((edge){v, c, w});
        G[v].push_back((edge){u, c, w});
    }
    dfs(0);

    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), greater<ll>());
    
    ll cnt1 = 0;
    for(ll w : v1){
        cnt1++;
        min_sum[0][cnt1] = min_sum[0][cnt1-1]-w;
    }

    ll cnt2 = 0;
    for(ll w : v2){
        cnt2++;
        min_sum[1][cnt2] = min_sum[1][cnt2-1]-w;
    }

    ll ans = INF;
    for(int i = 0; i <= cnt1; i++){
        if(min_sum[0][i]+min_sum[1][0] <= s){
            ans = min(ans, (ll)i);
            continue;
        }
        if(min_sum[0][i]+min_sum[1][cnt2] > s){
            continue;
        }
        int l = 0, r = cnt2;
        while(r-l > 1){
            int c = (l+r)/2;
            if(min_sum[0][i]+min_sum[1][c] <= s) r = c;
            else l = c;
        }
        ans = min(ans, (ll)i+2*r);
    }

    cout << ans << endl;
    min_sum[0][0] = 0; min_sum[1][0] = 0;
    for(int i = 0; i < n; i++) {
        G[i].clear();
        used[i] = false;
    }
    v1.clear(); v2.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}