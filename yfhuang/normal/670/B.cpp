//
//  main.cpp
//  B
//
//  Created by  on 16/5/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long n,k;

const int maxn = 100000 + 5;

int id[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d",&id[i]);
    }
    long long idx = 0;
    while(idx * (idx + 1) / 2 <= k) idx++;
    while(idx * (idx + 1) / 2 > k) idx--;
    k -= idx * (idx + 1) / 2;
    if(k == 0) k += idx;
    cout << id[k] << endl;
    return 0;
}