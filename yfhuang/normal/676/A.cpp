//
//  main.cpp
//  A
//
//  Created by  on 16/5/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

const int N = 105;

int a[N];

int main(int argc, const char * argv[]) {
    cin >> n;
    int maxp = 0,minp = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1){
            minp = i;
        }
        if(a[i] == n){
            maxp = i;
        }
    }
    int ans = 0;
    ans = max(ans,max(n - maxp,maxp - 1));
    ans = max(ans,max(n - minp,minp - 1));
    cout << ans << endl;
    return 0;
}