//
//  main.cpp
//  D
//
//  Created by  on 7/30/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long d,k,a,b,t;

int main(int argc, const char * argv[]) {
    cin >> d >> k >> a >> b >> t;
    if(d <= k){
        cout << d * a << endl;
    }else{
        long long r = (d - k) % k;
        long long times = (d - k - r) / k;
        long long l = d - k - r;
        long long T = k * a + min(t * times + a * l + min(t + r * a,r * b),(d - k) * b);
        cout << T << endl;
    }
    return 0;
}