//
//  main.cpp
//  A
//
//  Created by  on 16/4/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    int ans = n / 3 * 2;
    if(n % 3 == 1) ans++;
    else if(n % 3 == 2) ans++;
    cout << ans << endl;
    return 0;
}