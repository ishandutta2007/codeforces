#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int n, m, f[100005][20], v, p, depth[100005], ans[100005];
vi g[100005];
vector < pair<pii, int> > Q[100005];
void solve(int i, int d){
    depth[d]++;

    for(int u = 0; u < sz(Q[i]); u++)
        Q[i][u].second += depth[d + Q[i][u].first.second];

    for(int u = 0; u < sz(g[i]); u++)
        solve(g[i][u], d + 1);

    for(int u = 0; u < sz(Q[i]); u++)
        ans[Q[i][u].first.first] = (i == 0 ? 0 : depth[d + Q[i][u].first.second] - Q[i][u].second - 1);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &f[i][0]);
    for(int i = 1; i <= n; i++)
        g[f[i][0]].pb(i);
    for(int j = 1; j < 20; j++)
    for(int i = 1; i <= n; i++)
        f[i][j] = f[f[i][j - 1]][j - 1];
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &v, &p);

        int par = v;
        for(int j = 19; j >= 0; j--)
            if(p & (1 << j))par = f[par][j];

        Q[par].pb(mp(mp(i, p), 0));
    }
    solve(0, 0);
    for(int i = 0; i < m; i++){
        if(i > 0)printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}