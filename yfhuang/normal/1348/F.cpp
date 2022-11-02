#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 2e5 + 5;

int a[maxn], b[maxn];

vector<int> G[maxn];
typedef pair<int, int> pi;

int p[maxn];
int ans[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        G[a[i]].push_back(i);
    }
    set<pi> s;
    for(int i = 1;i <= n;i++){
        for(auto id : G[i]){
            s.insert(make_pair(b[id], id));
        }
        auto it = s.begin();
        p[i] = it->second;
        ans[it->second] = i;
        s.erase(it);
    }
    for(int i = 1;i <= n;i++){
        G[i].clear();
    }
    for(int i = 1;i <= n;i++){
        G[b[i] + 1].push_back(i);
    }
    s.clear();
    int x = -1, y = -1;
    for(int i = 1;i <= n;i++){
        for(auto v : G[i]){
            s.erase(make_pair(-ans[v], v));
        }
        if(!s.empty()){
            auto it = s.begin();
            int pos = -it->first;
            if(pos >= a[p[i]]){
                x = p[i], y = it->second; 
                break;
            }
        }
        s.insert(make_pair(-i, p[i]));
    }
    if(x == -1){
        cout << "YES" << endl;
        for(int i = 1;i <= n;i++){
            cout << ans[i] << ((i == n) ? '\n' : ' ');
        }
    }else{
        cout << "NO" << endl;
        for(int i = 1;i <= n;i++){
            cout << ans[i] << ((i == n) ? '\n' : ' ');
        }
        swap(ans[x], ans[y]);
        for(int i = 1;i <= n;i++){
            cout << ans[i] << ((i == n) ? '\n' : ' ');
        }
    }
    return 0;
}