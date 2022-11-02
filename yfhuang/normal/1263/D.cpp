#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int n;

const int maxn = 3e5;

int fa[maxn];
int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

char s[100];
bool vis[30];

int main(){
    cin >> n;
    for(int i = 1;i <= n + 26;i++){
        fa[i] = i;
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1;i <= n;i++){
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for(int j = 1;j <= len;j++){
            int now = s[j] - 'a' + 1;
            vis[now] = 1;
            int fx = Find(now);
            int fy = Find(i + 26);
            if(fx != fy){
                fa[fy] = fx;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n + 26;i++){
        int fx = Find(i);
        if(fx == i)
            ans++;
    }
    for(int i = 1;i <= 26;i++){
        if(vis[i] == false)
            ans--;
    }
    cout << ans << endl;
    return 0;
}