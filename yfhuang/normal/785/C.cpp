//
//  main.cpp
//  C
//
//  Created by  on 2017/3/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    long long n,m;
    //long long ans;
    long long ret = 0;
    cin >> n >> m;
    if(n <= m){
        cout << n << endl;
        return 0;
    }
    long long ans = 2 * (n - m);
    ret = sqrt(ans);
    while(ret * (ret + 1) < ans) ret++;
    cout << ret + m << endl;
    return 0;
}