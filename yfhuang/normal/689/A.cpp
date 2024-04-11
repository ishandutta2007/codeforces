//
//  main.cpp
//  A
//
//  Created by  on 16/7/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int G[15][15];

const int INF = 0x3f3f3f3f;

int x[15],y[15];

char s[15];

int main(int argc, const char * argv[]) {
    memset(G,INF,sizeof(G));
    for(int i = 0;i < 3;i++){
        for(int j = 1;j < 4;j++){
            G[i + 4][j + 3] = i * 3 + j;
        }
    }
    G[7][5] = 0;
    int n;
    cin >> n;
    scanf("%s",s + 1);
    for(int i = 1;i <= n;i++){
        if(s[i] == '0'){
            x[i] = 7;
            y[i] = 5;
            continue;
        }
        x[i] = (s[i] - '0' - 1) / 3 + 4;
        y[i] = (s[i] - '0' - 1) % 3 + 4;
    }
    bool flag = false;
    for(int i = -3;i <= 3;i++){
        for(int j = -3;j <= 3;j++){
            if(i == 0 && j == 0) continue;
            bool f = true;
            for(int k = 1;k <= n;k++){
                int xx = x[k] + i;
                int yy = y[k] + j;
                if(G[xx][yy] == INF) f = false;
            }
            if(f) flag = true;
           // if(f)cout << i << ' ' << j << endl;
        }
    }
    if(flag) cout << "NO" << endl;
    else cout <<"YES" << endl;
    return 0;
}