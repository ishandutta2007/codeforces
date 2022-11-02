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

int G[30][30];

int T;
const int maxn = 205;
char s[maxn];
stack<int> S;
void dfs(int u, int fa){
    for(int i = 0;i < 26;i++){
        if(G[u][i] and i != fa){
            dfs(i, u);
        }
    }
    S.push(u);
}

int main(){
    cin >> T;
    while(T--){
        while(!S.empty()) S.pop();
        int n;
        scanf("%s", s + 1);
        n = strlen(s + 1);
        if(n == 1){
            cout << "YES" << endl;
            for(int i = 0;i < 26;i++){
                putchar('a' + i);
            }
            puts("");
            continue;
        }
        memset(G, 0, sizeof(G));
        for(int i = 1;i < n;i++){
            int u = s[i] - 'a';
            int v = s[i + 1] - 'a';
            G[u][v] = G[v][u] = 1;
        }
        bool flag = true;
        vector<int> v;
        vector<int> v1;
        for(int i = 0;i < 26;i++){
            int deg = 0;
            for(int j = 0;j < 26;j++){
                if(G[i][j])
                    deg++;
            }
            if(deg == 0){
                v1.push_back(i);
                continue;
            }
            if(deg > 2)
                flag = false;
            if(deg == 1)
                v.push_back(i);
        }
        if(v.size() != 2){
            flag = false;
        }
        if(flag){
            dfs(v[0], v[0]); 
            cout << "YES" << endl;
            string ans = "";
            while(!S.empty()){
                int id = S.top(); S.pop();
                ans.push_back(id + 'a');
            }
            for(auto id : v1){
                ans.push_back(id + 'a');
            }
            cout << ans << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}