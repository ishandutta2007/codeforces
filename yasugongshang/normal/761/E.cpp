#include <bits/stdc++.h>
 
using namespace std;
 
#define REP(i,n)                for(int i(0); i <  (n); ++i)
#define rep(i,a,b)              for(int i(a); i <= (b); ++i)
#define LL              long long
#define PB              push_back
 
const int Q     = 1000        +       10;
const int A    = 30          +       1;
const LL dx[]     = {0, 1, 0, -1};
const LL dy[]     = {1, 0, -1, 0};
 
struct node{ LL x, y;} c[A];
vector <int> v[A];
int f[A][A];
LL num[Q];
int n;
int x, y;
int inn[Q];
bool vis[Q];
 
void dfs(int x, int cnt){
    REP(i, (int)v[x].size()){
        int u = v[x][i];
        if (!vis[u]){
            vis[u] = true;
            REP(j, 4){
                if (!f[x][j] && !f[u][(j + 2) % 4]){
                    c[u].x = c[x].x + dx[j] * num[cnt];
                    c[u].y = c[x].y + dy[j] * num[cnt];
                    f[u][(j + 2) % 4] = 1;
                    f[x][j] = 1;
                    break;
                }
            }
            dfs(u, cnt - 1);
        }
    }
}   
 
int main(){
 
    num[0] = 1; rep(i, 1, 36) num[i] = num[i - 1] * 2;
    scanf("%d", &n);
    rep(i, 1, n - 1){
        scanf("%d%d", &x, &y);
        v[x].PB(y);
        v[y].PB(x);
        ++inn[x], ++inn[y];
    }
 
    rep(i, 1, n) if (inn[i] > 4){
        puts("NO");
        return 0;
    }
 
    memset(vis, false, sizeof vis); vis[1] = true;
    c[1].x = c[1].y = 0;
    dfs(1, 30);
 
    puts("YES");
    rep(i, 1, n){
        printf("%lld %lld\n", c[i].x, c[i].y);
    }
 
    return 0;
 
}