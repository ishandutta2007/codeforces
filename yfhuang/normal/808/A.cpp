//
//  main.cpp
//  A
//
//  Created by  on 2017/5/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int num[40];
int ans[40];

int main(int argc, const char * argv[]) {
    cin >> n;
    long long m = n;
    int tot = 0;
    long long ret = 0;
    while(n > 0){
        num[++tot] = n % 10;
        n /= 10;
    }
    if(num[tot] == 9){
        ret = 1;
        ans[tot + 1] = 1;
        for(int i = 1;i <= tot;i++) ret *= 10;
    }else{
        ans[tot] = num[tot] + 1;
        ret = ans[tot];
        for(int i = 1;i < tot;i++) ret *= 10;
    }
    cout << ret - m << endl;
    return 0;
}