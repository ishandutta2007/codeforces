//
//  main.cpp
//  A
//
//  Created by  on 8/1/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long n,m,a;

int main(int argc, const char * argv[]) {
    cin >> n >> m >> a;
    cout << ((n + a - 1)/ a) * ((m + a - 1) / a) << endl;
    return 0;
}