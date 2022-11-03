//
//  main.cpp
//  A
//
//  Created by  on 9/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    b[n] = a[n];
    for(int i = n - 1;i >= 1;i--){
        b[i] = a[i] + a[i + 1];
    }
    for(int i = 1;i <= n;i++){
        cout << b[i] << ' ';
    }
    return 0;
}