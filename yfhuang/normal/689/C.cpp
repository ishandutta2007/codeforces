//
//  main.cpp
//  C
//
//  Created by  on 16/7/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long m;

long long cal(long long n){
    long long ret = 0;
    for(long long i = 2;i * i * i <= n;i++){
        ret += n / (i * i * i );
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    cin >> m;
    long long l = 1,r = 1e18;
    while(l < r){
        long long mid = (l + r) / 2;
        if(cal(mid) >= m) r = mid;
        else l = mid + 1;
    }
    if(cal(r) != m) cout << -1 << endl;
    else cout << r << endl;
    return 0;
}