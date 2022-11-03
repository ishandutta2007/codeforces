#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int maxn = 1e6 + 5;

vector<int> G[maxn];

int dp[maxn][2];
bool vis[maxn];


    int ch[maxn][26];
    int fail[maxn];
    int dep[maxn];
    int tot;
    void init(){
        tot = 0;
        memset(ch[0],0,sizeof(ch[0]));
    }
    int newnode(){
        tot++;
        memset(ch[tot],0,sizeof(ch[tot]));
        return tot;
    }
    void insert(char *s){
        int now = 0;
        for(int i = 0;s[i];i++){
            int tr = s[i] - 'a';
            if(ch[now][tr] == 0){
                ch[now][tr] = newnode();
            }
            now = ch[now][tr];
            dep[now] = i + 1;
        }
    }

void getFail() {
    queue<int> Q;
    for (int i = 0 ; i < 26 ; ++ i)
        if (ch[0][i]) {
            fail[ch[0][i]] = 0;
            Q.push(ch[0][i]);
        }
    while (!Q.empty()) {
        int x = Q.front() ; Q.pop();
        for (int i = 0 ; i < 26 ; ++ i) {
            int y = ch[x][i];
            if (!y) {
                ch[x][i] = ch[fail[x]][i];
            } else {
                Q.push(y);
                fail[y] = ch[fail[x]][i];
            }
        }
    }
}

char s[maxn];

void dfs(int u){
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(auto v : G[u]){
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0],dp[v][1]);
    }
}

int solve(){
    getFail();
    for(int i = 1;i <= tot;i++){
        vis[i] = 0;
        G[i].clear();
    }
    for(int i = 1;i <= tot;i++){
        if(fail[i] && dep[fail[i]] + 1 == dep[i]){
            vis[i] = 1;
            G[fail[i]].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 1;i <= tot;i++){
        if(!vis[i]){
            dfs(i);
            ans += max(dp[i][0],dp[i][1]);
        }
    }
    return ans;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        init();
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%s",s);
            insert(s);
        }
        printf("%d\n",solve());
    }
    return 0;
}