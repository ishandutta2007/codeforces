#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;

const int maxn = 2e5 + 5;
vector<int> G[maxn];

int b[maxn];
int p[maxn];
int rk[maxn];
int n;

ll dis[maxn];
ll w[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;   
        for(int i = 1;i <= n;i++){
            cin >> b[i];
        }
        for(int i = 1;i <= n;i++){
            cin >> p[i];
            rk[p[i]] = i;
        }
        bool ok = true;
        for(int i = 1;i <= n;i++){
            if(rk[i] < rk[b[i]])
                ok = false;
        }
        if(!ok){
            cout << -1 << endl;
        }else{
            for(int i = 1;i <= n;i++){
                int u = p[i];
                if(i == 1){
                    dis[u] = 0;
                    w[u] = 0;
                }else{
                    w[u] = max(1LL, dis[p[i-1]] + 1 - dis[b[u]]);
                    dis[u] = dis[b[u]] + w[u];
                }
            }
            for(int i = 1;i <= n;i++){
                cout << w[i] << ((i == n) ? '\n' : ' ');
            }
        }
    }
    return 0;
}