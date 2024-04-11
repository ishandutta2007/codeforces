//
//  main.cpp
//  A
//
//  Created by  on 16/5/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int minx,maxx;

int main(int argc, const char * argv[]) {
    cin >> n;
    int ansx = n % 7;
    int ansy = n / 7;
    maxx = min(ansx,2) + 2 * ansy;
    if(ansx <= 5) minx = 2 * ansy;
    else minx = 7 - ansx + 2 * ansy;
    cout << minx << ' ' << maxx << endl;
    return 0;
}