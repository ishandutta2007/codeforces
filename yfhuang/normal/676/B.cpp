//
//  main.cpp
//  B
//
//  Created by  on 16/5/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
const int maxn = 15;

int t;

bool vis[maxn][maxn];

double l[maxn][maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> t;
    int cnt = 0;
    memset(l,0,sizeof(l));
    l[1][1] = 1.0 * t;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(l[i][j] >= 1) {cnt++;
            l[i + 1][j] += (l[i][j] - 1) / 2.0;
            l[i + 1][j + 1] += (l[i][j] - 1) / 2.0;
            }
        }
    }
    //for(int i = 1;i <= n;i++) for(int j = 1;j <= i;j++) cout << l[i][j] << endl;
    cout << cnt << endl;
    return 0;
}