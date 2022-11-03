#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1005;

int n;
bool vis[maxn];
int cnt[maxn][maxn];

vector<int> e[maxn];
vector<vector<int> > vec[maxn];

void read(){
    for(int i = 1;i <= n;i++){
        int left = n - 1;
        while(left > 0){
            vector<int> tmp(0);
            int m;
            scanf("%d:",&m);
            for(int j = 1;j < m;j++){
               int v;
                scanf("%d,",&v);
                cnt[i][v] = m;
                tmp.push_back(v);
            }
            left -= m;
            if(left == 0){
                int v;
                scanf("%d",&v);
                tmp.push_back(v);
                cnt[i][v] = m;
                sort(tmp.begin(),tmp.end());
                vec[i].push_back(tmp);
            }else{
                int v;
                scanf("%d-",&v);
                tmp.push_back(v);
                sort(tmp.begin(),tmp.end());
                vec[i].push_back(tmp);
                cnt[i][v] = m;
            }
        }
        sort(vec[i].begin(),vec[i].end());
    }
}

void get(int u,int fa,vector<int> & tmp){
    tmp.push_back(u);
    for(auto v:e[u]){
        if(v == fa) continue;
        get(v,u,tmp);
    }
}

bool check(){
    for(int i = 1;i <= n;i++){
        vector<vector<int> > w;
        for(auto v:e[i]){
            vector<int> tmp(0);
            get(v,i,tmp);
            sort(tmp.begin(),tmp.end());
            w.push_back(tmp);
        }
        sort(w.begin(),w.end());
        if(w != vec[i]) return false;
    }
    return true;
}

int dfs(int u,int f){
    int sum = 1;
    vis[u] = 1;
    for(auto v:e[u]){
        if(v == f) continue;
        if(vis[v]) return -1;
        int ret = dfs(v,u);
        if(ret == -1) return -1;
        sum += ret;
    }
    return sum;
}

int main(){
    cin >> n;
    read();
    int ecnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(cnt[i][j] + cnt[j][i] == n){
                e[i].push_back(j);
                e[j].push_back(i);
                ecnt++;
            }
        }
    }
    if(ecnt != n - 1){
        printf("-1\n");
        return 0;
    }
    if(dfs(1,1)){
        if(!check()){
            printf("-1\n");
            return 0;
        }
        printf("%d\n",n - 1);
        for(int i = 1;i <= n;i++){
            for(auto v : e[i]){
                if(v > i){
                    printf("%d %d\n",i,v);
                }
            }
        }
    }else{
        printf("-1\n");
    }
    return 0;
}