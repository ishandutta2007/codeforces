#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int T;
int n, m;
typedef long long LL;

const int maxn = 3005;
LL vote[maxn];

vector<int> G[maxn];

void update(pair<int, LL> &a, pair<int, LL> b){
    if(b > a)
        a = b;
}

vector<pair<int, LL> > dfs(int u, int fa){
    vector<pair<int,LL> > now = {make_pair(0, vote[u])};
    for(auto v : G[u]){
        if(v == fa)
            continue;
        vector<pair<int,LL> > tmp = dfs(v, u);
        vector<pair<int,LL> > ans(now.size() + tmp.size(), {0, -1e15});
        for(int i = 0; i < now.size();i++){
            for(int j = 0;j < tmp.size();j++){
                pair<int, LL> a = now[i], b = tmp[j];
                update(ans[i + j], {a.first + b.first, a.second + b.second});
                update(ans[i + j + 1], {a.first + b.first + (b.second > 0), a.second});
            }
        }
        now = ans;
    }
    return now;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            int x;
            scanf("%d", &x);
            vote[i] = -x;
            G[i].clear();
        }
        for(int i = 1;i <= n;i++){
            int x;
            scanf("%d", &x);
            vote[i] += x;
        }
        for(int i = 1;i < n;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<pair<int, LL> > ans = dfs(1, -1);
        int ret = ans[m - 1].first;
        if(ans[m - 1].second > 0)
            ret++;
        cout << ret << endl;
    }
    return 0;
}