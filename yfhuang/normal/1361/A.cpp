#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 5e5 + 5;
int n, m;
int a[maxn], b[maxn];
int t[maxn];
int deg[maxn];

vector<int> G[maxn];
vector<int> e[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> a[i] >> b[i];
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    for(int i = 1;i <= n;i++){
        cin >> t[i];
    }
    bool flag = true;
    for(int i = 1;i <= m;i++){
        if(t[a[i]] + 1 == t[b[i]]){
            G[a[i]].push_back(b[i]);
            deg[b[i]]++;
        }else if(t[b[i]] + 1 == t[a[i]]){
            G[b[i]].push_back(a[i]);
            deg[a[i]]++;
        }else if(t[a[i]] == t[b[i]]){
            flag = false;
        }
    }
    for(int i = 1;i <= n;i++){
        for(auto v : e[i]){
            vis[t[v]] = true;
        }
        for(int j = 1;j < t[i];j++){
            if(!vis[j]){
                flag = false;
                break;
            }
        }
        for(auto v : e[i]){
            vis[t[v]] = false;
        }
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(deg[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int p = q.front(); q.pop();
        ans.push_back(p);
        for(auto v : G[p]){
            deg[v]--;
            if(deg[v] == 0){
                q.push(v);
            }
        }
    }
    if(ans.size() == n){
        for(int i = 0;i < n;i++){
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}