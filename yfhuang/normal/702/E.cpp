//
//  main.cpp
//  E
//
//  Created by  on 7/30/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;

typedef long long LL;

LL w[maxn],f[maxn][40],fmin[maxn][40],fsum[maxn][40];

LL n,k;

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> f[i][0];
    for(int i = 0;i < n;i++) cin >> w[i];
//    for(int i = 0;i < n;i++) cout << w[i] << endl;
    for(int i = 0;i < n;i++){
        fmin[i][0] = w[i];
        fsum[i][0] = w[i];
    }
    for(int i = 1;i < 40;i++){
        for(int j = 0;j < n;j++){
            f[j][i] = f[f[j][i - 1]][i - 1];
            fmin[j][i] = min(fmin[j][i - 1],fmin[f[j][i - 1]][i - 1]);
            fsum[j][i] = fsum[j][i - 1] + fsum[f[j][i - 1]][i - 1];
        }
    }
//    for(int i = 0;i < 40;i++){
//        for(int j = 0;j < n;j++){
//            cout << f[j][i] << " " << fmin[j][i] << " " << fsum[j][i] << endl;
//        }
//    }
    for(int i = 0;i < n;i++){
        LL now = i;
        LL s = 0;
        LL m = 1e9 + 5;
        for(int j = 39;j >= 0;j--) if(k & (1LL << j)){
            s += fsum[now][j];
            m = min(m,fmin[now][j]);
            now = f[now][j];
        }
        cout << s << " " << m << endl;
    }
    return 0;
}