#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1005;

string S[maxn][2];


bool check(int x,int i,int y,int j){
    bool flag = true;
    for(int l = 0;l < 3;l++){
        if(S[x][i][l] != S[y][j][l]) flag = false;
    }
    return flag;
}


struct twosat{
    int n;
    vector<int> G[maxn * 2];
    bool vis[maxn * 2];
    int S[maxn * 2];
    int top;
    
    bool dfs(int x){
        if(vis[x ^ 1]) return false;
        if(vis[x]) return true;
        vis[x] = true;
        S[top++] = x;
        for(int i = 0;i < G[x].size();i++){
            if(!dfs(G[x][i])) return false;
        }
        return true;
    }
    
    void init(int n){
        this->n = n;
        for(int i = 0;i < n * 2;i++) G[i].clear();
        memset(vis,false,sizeof(vis));
    }
    
    void add(int x,int y){
        int xx = 2 * x;
        int yy = 2 * y;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                if(check(x,i,y,j)){
                   // cout << "2" << endl;
                   // cout << x << " " << i << " " << y << " " << j << endl;
                    G[xx + i].push_back((yy + j) ^ 1);
                    G[yy + j].push_back((xx + i) ^ 1);
                }
            }
        }
        if(check(x,0,y,0)){
            //cout << "1" << endl;
            G[xx ^ 1].push_back(yy ^ 1);
            G[yy ^ 1].push_back(xx ^ 1);
        }
    }
    
    bool solve(){
        for(int i = 0;i < 2 * n;i += 2){
            if(!vis[i] && !vis[i + 1]){
                top = 0;
                if(!dfs(i)){
                    while(top > 0) vis[S[--top]] = false;
                    if(!dfs(i + 1)) return false;
                }
            }
        }
        return true;
    }
}s;

char s1[25],s2[25];

int n;

int main(){
    while(~scanf("%d",&n)){
        for(int i = 0;i < n;i++){
            scanf("%s",s1);
            scanf("%s",s2);
            S[i][0] = "";
            S[i][0] += s1[0];
            S[i][0] += s1[1];
            S[i][1] = S[i][0];
            S[i][0] += s1[2];
            S[i][1] += s2[0];
           // cout << S[i][0] << " " << S[i][1] << endl;
        }
        s.init(n);
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                s.add(i,j);
            }
        }
        if(s.solve()){
            printf("YES\n");
            for(int i = 0;i < n;i++){
                if(s.vis[i * 2]){
                    cout << S[i][0] << endl;
                }else cout << S[i][1] << endl;
            }
        }else{
            printf("NO\n");
        }
    }
    return 0;
}