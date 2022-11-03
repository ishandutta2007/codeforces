//
//  main.cpp
//  D
//
//  Created by  on 2017/5/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int n;

const int maxn = 1e5 + 5;
int a[maxn];

map<long long,int> mp,mp1;

int main(int argc, const char * argv[]) {
    cin >> n;
    long long pre = 0,suf = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        suf += a[i];
        mp1[a[i]]++;
    }
    bool flag = false;
    for(int i = 1;i <= n;i++){
        pre += a[i];
        suf -= a[i];
        mp[a[i]]++;
        mp1[a[i]]--;
        if(pre > suf){
            if((pre - suf) % 2 == 0 && mp[(pre - suf) / 2] > 0 && i > 1) flag = true;
        }else{
            if((suf - pre) % 2 == 0 && mp1[(suf - pre) / 2] > 0 && i < n) flag = true;
        }
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}