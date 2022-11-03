//
//  main.cpp
//  C
//
//  Created by  on 9/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int y,x;

int f[200];

int main(int argc, const char * argv[]) {
    cin >> x >> y;
    f[0] = y;
    f[1] = y;
    int i;
    for(i = 1;f[i] < x;i++ ){
        f[i + 1] = f[i] + f[i - 1] - 1;
    }
    cout << i + 1 << endl;
    return 0;
}