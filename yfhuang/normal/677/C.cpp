//
//  main.cpp
//  C
//
//  Created by  on 16/6/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const long long mod = 1e9 + 7;

const int maxn = 1e5 + 5;
long long s[maxn];

long long num[100];

char ss[maxn];

int main(int argc, const char * argv[]) {
    scanf("%s",ss + 1);
    memset(num,0,sizeof(num));
    for(int i = 0;i < 64;i++){
        for(int j = 0;j < 64;j++){
            num[i & j]++;
        }
    }
    int len = strlen(ss + 1);
    s[0] = 1;
    for(int i = 1;i <= len;i++){
        if(ss[i] >= '0' && ss[i] <= '9') s[i] = s[i - 1] * num[ss[i] - '0'] % mod;
        else if(ss[i] >='A' && ss[i] <= 'Z') s[i] = s[i - 1] * num[ss[i] - 'A' + 10] % mod;
        else if(ss[i] >= 'a' && ss[i] <= 'z') s[i] = s[i - 1] * num[ss[i] - 'a' + 36] % mod;
        else if(ss[i] == '-') s[i] = s[i - 1] * num[62] % mod;
        else s[i] = s[i - 1] * num[63] % mod;
    }
    cout << s[len] << endl;
    return 0;
}