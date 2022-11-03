//
//  main.cpp
//  A
//
//  Created by  on 8/20/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 105;

int n,m;
char g[maxn][maxn];

char s[3];

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%s",s);
            g[i][j] = s[0];
            if(g[i][j] == 'C' || g[i][j] == 'M' || g[i][j] == 'Y') flag = false;
        }
    }
    if(flag) printf("#Black&White\n");
    else printf("#Color\n");
    return 0;
}