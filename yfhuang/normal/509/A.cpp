//
//  main.cpp
//  A
//
//  Created by  on 10/18/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 15;

long long a[maxn][maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        a[i][1] = 1;
        a[1][i] = 1;
    }
    for(int i = 2;i <= n;i++){
        for(int j = 2;j <= n;j++){
            a[i][j] = a[i][j - 1] + a[i - 1][j];
        }
    }
    cout << a[n][n] << endl;
    return 0;
}