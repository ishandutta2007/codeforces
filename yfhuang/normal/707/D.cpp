#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
pair<int,int> op[maxn];
const  int N = 1005;
int n,m,q;
int flip[N];
int ans[maxn];
int a[N][N];
int sum;
int s[N];
vector<int> G[maxn];
void dfs(int u){
    bool flag = false;
    if(u){
        if(op[u].first == 1){
            int x = op[u].second / 10000;
            int y = op[u].second % 10000;
            if((a[x][y] ^ flip[x]) == 0){
                flag = 1;
                a[x][y] ^= 1;
                sum++;
                s[x]++;
            }
        }else if(op[u].first == 2){
            int x = op[u].second / 10000;
            int y = op[u].second % 10000;
            if((a[x][y] ^ flip[x])){
                flag = 1;
                a[x][y] ^= 1;
                sum--;
                s[x]--;
            }
        }else if(op[u].first == 3){
           int x = op[u].second;
           flip[x] ^= 1;
           sum += (m - s[x] - s[x]);
           s[x] = m - s[x];
           flag = 1;
        }
        ans[u] = sum;
    }
    for(int i = 0;i < (int)G[u].size();i++){
        int x = G[u][i];
        dfs(x);
    }
    if(u && flag){
        if(op[u].first == 1){
            int x = op[u].second / 10000;
            int y = op[u].second % 10000;
            a[x][y] ^= 1;
            sum--;
            s[x]--;
        }else if(op[u].first == 2){
            int x = op[u].second / 10000;
            int y = op[u].second % 10000;
            a[x][y] ^= 1;
            sum++;
            s[x]++;
        }else if(op[u].first == 3){
            int x = op[u].second;
            sum += m - s[x] * 2;
            s[x] = m - s[x];
            flip[x] ^= 1;
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 0;i <= n;i++){
        G[i].clear();
    }
    for(int i = 1;i <= q;i++){
        scanf("%d",&op[i].first);
        if(op[i].first <= 2){
            int x,y;
            scanf("%d%d",&x,&y);
            op[i].second = x * 10000 + y;
        }else if(op[i].first >= 3){
            int x;
            scanf("%d",&x);
            op[i].second = x;
        }
        if(op[i].first == 4){
            G[op[i].second].push_back(i);
        }else G[i - 1].push_back(i);
    }
    sum = 0;
    memset(flip,0,sizeof(flip));
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    dfs(0);
    for(int i = 1;i <= q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}