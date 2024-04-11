//
//  main.cpp
//  A
//
//  Created by  on 16/6/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1005;

int a[N];

int n,h;

int main(int argc, const char * argv[]) {
    int ans = 0;
    cin >> n >> h;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        if(a[i] > h) ans += 2;
        else ans += 1;
    }
    cout << ans << endl;
    return 0;
}