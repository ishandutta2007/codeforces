#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<__int128, __int128> pll;

const int maxn = 1005;
multiset<pll> S[maxn];

int n, m;

vector<int> in[maxn], out[maxn];
int indeg[maxn], outdeg[maxn];
ll a[maxn];
const int mod = 998244353;

void solve(){
    queue<int> Q;
    for(int i = 1;i <= n;i++){
        if(indeg[i] == 0){
            Q.push(i);
        }
    } 
    while(!Q.empty()){
        int p = Q.front(); Q.pop(); 
        multiset<pll> tmp;
        tmp.clear();
        if(a[p] > 0){
            tmp.insert(mp(1, a[p]));
        }
        for(auto v : in[p]){
            for(auto l : S[v]){
                tmp.insert(mp(l.fi+1, l.se+1));
            }
        }
        if(tmp.size() <= 1){
            S[p] = tmp;
        }else{
            pll l = *tmp.begin();
            tmp.erase(tmp.begin());
            for(auto r : tmp){
                if(r.fi > l.se + 1){
                    S[p].insert(l);
                    l = r;
                }else{
                    __int128 len = r.se - r.fi + 1 + l.se - l.fi + 1;
                    l.se = l.fi + len - 1;
                }
            }
            S[p].insert(l);
        }
        for(auto v : out[p]){
            indeg[v]--;
            if(indeg[v] == 0){
                Q.push(v);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(outdeg[i] == 0){
            if(S[i].size() == 0){
                cout << 0 << endl;
            }else{
                auto it = S[i].end();
                it--;
                auto l = *it;
                cout << (ll)(l.se % mod) << endl;
            }
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            in[i].clear();
            out[i].clear();
            indeg[i] = 0;
            outdeg[i] = 0;
            S[i].clear();
        }
        for(int i = 1;i <= m;i++){
            int x, y;
            cin >> x >> y;
            in[y].push_back(x);
            out[x].push_back(y);
            indeg[y]++;
            outdeg[x]++;
        }
        solve();
    }
    return 0;
}