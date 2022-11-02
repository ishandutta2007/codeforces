#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, q;

const int maxn = 2e5 + 5;
int u[maxn], v[maxn], x[maxn];

vector<int> G[maxn];
int a[maxn];
int b[maxn];

void solve(int bit){
    for(int i = 1;i <= n;i++){
        G[i].clear();
        b[i] = -1;
    }
    for(int i = 1;i <= q;i++){
        int d = (x[i] >> bit) & 1; 
        if(u[i] == v[i]){
            b[u[i]] = d;
        }else{
            if(d == 0){
                b[u[i]] = b[v[i]] = 0; 
            }else{
                G[u[i]].push_back(v[i]);
                G[v[i]].push_back(u[i]);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(b[i] == -1){
            bool flag = false;
            for(auto to : G[i]){
                if(b[to] == 0){
                    flag = true;
                }
            }
            b[i] = flag ? 1 : 0;
        }
    }
    for(int i = 1;i <= n;i++){
        a[i] |= (b[i] << bit); 
    } 
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= q;i++){
        cin >> u[i] >> v[i] >> x[i];
    }
    for(int bit = 29;bit >= 0;bit--){
        solve(bit);
    }
    for(int i = 1;i <= n;i++){
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}