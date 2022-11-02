#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
char s[maxn][maxn];

int cnt[maxn * 2], d[maxn * 2];
vector<pair<int, int> > G[maxn * 2];
bool inq[maxn * 2];
int fa[maxn * 2];
int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
bool spfa(){
    for(int i = 0;i <= n + m;i++){
        d[i] = -INF;
        int fx = Find(i);
        G[0].push_back(make_pair(fx, 0));
        inq[i] = false;
        cnt[i] = 0;
    }
    d[0] = 1;
    queue<int> q;
    q.push(0);
    inq[0] = true;
    while(!q.empty()){
        int p = q.front();q.pop();
        inq[p] = false;
        if(cnt[p] > n + m + 1)
            return false;
       for(auto x:G[p]){
           if(d[x.first] < d[p] + x.second){
               cnt[x.first]++;
               d[x.first] = d[p] + x.second;
               if(!inq[x.first]){
                   inq[x.first] = true;
                   q.push(x.first);
               }
           }
       } 
    }
    return true;
}


int main(){
    while(cin >> n >> m){
        for(int i = 1;i <= n;i++){
            scanf("%s", s[i] + 1);
        }
        for(int i = 1;i <= n + m;i++){
            fa[i] = i;
        } 
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i][j] == '='){
                    int fx = Find(i);
                    int fy = Find(j + n);
                    if(fx != fy)
                        fa[fx] = fy;
                }
            }
        }
        bool flag = true;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i][j] == '>'){
                    int fx = Find(i);
                    int fy = Find(j + n);
                    if(fx == fy)
                        flag = false;
                    G[fy].push_back(make_pair(fx, 1));
                }else if(s[i][j] == '<'){
                    int fx = Find(i);
                    int fy = Find(j + n);
                    if(fx == fy)
                        flag = false;
                    G[fx].push_back(make_pair(fy, 1));
                }
            } 
        }
        if(!flag){
            puts("No");
        }else{
            flag &= spfa();
            if(flag){
                puts("Yes");
                for(int i = 1;i <= n;i++){
                    int fx = Find(i);
                    printf("%d%c", d[fx], i == n ? '\n' : ' ');
                }
                for(int i = 1;i <= m;i++){
                    int fx = Find(i + n);
                    printf("%d%c", d[fx], i == m ? '\n' : ' ');
                }
            }else{
                puts("No");
            }
        }
    }
    return 0;
}