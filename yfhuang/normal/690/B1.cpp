//
//  main.cpp
//  B(easy)
//
//  Created by  on 16/7/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 55;

char G[maxn][maxn];
bool vis[maxn][maxn];

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    memset(G,0,sizeof(G));
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++){
        scanf("%s",G[i] + 1);
    }
    int up = n + 1,down = 0,lef = n + 1,ri = 0;
    bool flag = false;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(G[i][j] == '4') flag = true,up = min(up,i),down = max(down,i),lef = min(lef,j),ri = max(ri,j);
        }
    }
    if(!flag){
        cout << "No" << endl;
    }else{
        flag = true;
        for(int i = up;i <= down;i++) {
            for(int j = lef;j <= ri;j++){
                if(G[i][j] != '4') flag = false;
                else vis[i][j] = true;
            }
        }
        if(!flag){
            cout << "No" << endl;
            return 0;
        }
        if(lef > 1){
            flag = true;
            for(int i = up;i <= down;i++){
                if(G[i][lef - 1] != '2') flag = false;
                else vis[i][lef - 1] = true;
            }
            if(!flag){
                cout << "No" << endl;
                return 0;
            }
        }
        if(ri < n){
            flag = true;
            for(int i = up;i <= down;i++){
                if(G[i][ri + 1] != '2') flag = false;
                else vis[i][ri + 1] = true;
            }
            if(!flag){
                cout << "No" << endl;
                return 0;
            }
        }
        if(up > 1){
            flag = true;
            for(int i = lef;i <= ri;i++){
                if(G[up - 1][i] != '2') flag = false;
                else vis[up - 1][i] = true;
            }
            if(!flag){
                cout << "No" << endl;
                return 0;
            }
        }
        if(down < n){
            flag = true;
            for(int i = lef;i <= ri;i++){
                if(G[down + 1][i] != '2') flag = false;
                else vis[down + 1][i] = true;
            }
            if(!flag){
                cout << "No" << endl;
                return 0;
            }

        }
        flag = true;
        if(lef > 1 && up > 1){
            if(G[up - 1][lef - 1] != '1') flag = false;
            else vis[up - 1][lef - 1] = true;
        }
        if(lef > 1 && down < n){
            if(G[down + 1][lef - 1] != '1') flag = false;
            else vis[down + 1][lef -  1] = true;
        }
        if(ri < n && up > 1){
            if(G[up - 1][ri + 1] != '1') flag = false;
            else vis[up - 1][ri + 1] = true;
        }
        if(ri < n && down < n){
            if(G[down + 1][ri + 1] != '1') flag = false;
            else vis[down + 1][ri + 1] = true;
        }
        if(!flag){
            cout << "No" << endl;
        }else{
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(!vis[i][j]){
                        if(G[i][j] != '0'){
                            cout << "No" << endl;
                            return 0;
                        }
                    }
                }
            }
            cout << "Yes" << endl;
        }
    }
    return 0;
}