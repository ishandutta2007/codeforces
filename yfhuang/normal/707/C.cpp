//
//  main.cpp
//  C
//
//  Created by  on 8/20/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long n;

typedef long long ll;

int main(int argc, const char * argv[]) {
    cin >> n;
    if(n == 1 || n == 2){
        printf("-1\n");
        return 0;
    }
    if(n & 1){
        cout << (n * n + 1) / 2 << " " << (n * n - 1) / 2 << endl;
    }else{
        long long a = n * n / 2;
        long long b = 2;
        cout << (a + b) / 2 << " " << (a - b) / 2 << endl;
    }
    return 0;
}