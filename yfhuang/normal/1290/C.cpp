#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, k;
const int maxn = 3e5 + 5;
vector<int> id[maxn];

const int INF = 1e9;
int l[maxn], r[maxn], col[maxn];
int fa[maxn];
char s[maxn];

pair<int, int> Find(int x){
    if(fa[x] == x){
        return make_pair(x, col[x]);
    }
    pair<int, int> par = Find(fa[x]);
    fa[x] = par.first;
    col[x] ^= par.second; 
    return make_pair(fa[x], col[x]);
}

int main(){
    cin >> n >> k;
    scanf("%s", s + 1);
    for(int i = 1;i <= k;i++){
        int c;
        scanf("%d", &c);
        for(int j = 1;j <= c;j++){
            int num;
            scanf("%d", &num);
            id[num].push_back(i);
        }
    }
    for(int i = 1;i <= k;i++){
        fa[i] = i;
        l[i] = 1, r[i] = 0;
        col[i] = 0;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int type = s[i] - '0';
        type ^= 1;
        if(id[i].size() == 1){
            pair<int, int> par = Find(id[i][0]);
            int root = par.first;
            //cout << root << endl;
            ans -= min(l[root], r[root]);
            l[root] = min(INF, l[root] + (par.second == type) * INF);
            r[root] = min(INF, r[root] + (par.second != type) * INF);
            ans += min(l[root], r[root]);
        }else if(id[i].size() == 2){
            pair<int, int> u = Find(id[i][0]);
            pair<int, int> v = Find(id[i][1]);
            int fx = u.first;
            int fy = v.first;
            //cout << fx << " " << fy << endl;
            if(fx != fy){
                ans -= min(l[fx], r[fx]) + min(l[fy], r[fy]);
                if(u.second ^ v.second ^ type){
                    swap(l[fy], r[fy]);
                    col[fy] ^= 1;
                } 
                fa[fy] = fx;
                l[fx] = min(INF, l[fx] + l[fy]);
                r[fx] = min(INF, r[fx] + r[fy]);
                ans += min(l[fx], r[fx]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}