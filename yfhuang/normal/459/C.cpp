//
//  main.cpp
//  C
//
//  Created by  on 10/9/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long n,k,d;

typedef long long LL;

const int maxn = 1005;
int num[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k >> d;
    LL cnt = 1;
    bool flag = false;
    for(int i = 1;i <= d;i++){
        cnt = cnt * k;
        if(cnt >= n){
            flag = true;
            break;
        }
    }
    if(!flag){
        printf("-1\n");
    }else{
        for(int i = 1;i <= n;i++){
            num[i] = i - 1;
        }
        for(int i = 1;i <= d;i++){
            for(int j = 1;j <= n;j++){
                int x = num[j] % k;
                num[j] /= k;
                printf("%d%c",x + 1,j == n ? '\n':' ');
            }
        }
    }
    return 0;
}