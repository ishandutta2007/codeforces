//
//  main.cpp
//  A
//
//  Created by  on 2017/5/4.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

const int maxn = 1e6 + 6;
const int mod = 1e9 + 7;

int ans[maxn];

char s[maxn];


int main(int argc, const char * argv[]) {
    ans[0] = 0;
    for(int i = 1;i < maxn;i++){
        ans[i] = (ans[i - 1] * 2LL + 1) % mod;
    }
    scanf("%s",s + 1);
    int len = strlen(s + 1);
    int num = 0;
    int ret = 0;
    for(int i = 1;i <= len;i++){
        if(s[i] == 'a'){
            num++;
        }else{
            ret = (1LL * ret + ans[num]) % mod;
        }
    }
    cout << ret << endl;
    return 0;
}