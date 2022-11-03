//
//  main.cpp
//  D
//
//  Created by  on 15/12/19.
//  Copyright  2015 . All rights reserved.
//
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[110], b[310], c[310];
int n, t, k, res = 0, M = 0;

int main() {
    cin>>n>>t;
    for(int i = 0; i < n; ++i){
        cin>>a[i]; M = max(M, ++b[a[i]]);
    }
    for(int i = 0; i < min(n * 2, t) * n; ++i){
        k = 1;
        for(int j = 1; j <= a[i % n]; ++j)
            k = max(k, c[j] + 1);
        c[a[i % n]] = k;
        res = max(res, k);
    }
    cout<<res + max((t-n*2)*M,0);
}