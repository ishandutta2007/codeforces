//
//  main.cpp
//  B
//
//  Created by  on 8/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
const int maxn = 100005;

int c[maxn];

void add(int x){
    while(x < maxn){
        c[x]++;
        x += x & -x;
    }
}

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= x & -x;
    }
    return ret;
}

int q;
int main(int argc, const char * argv[]) {
    cin >> n;
    int maxx = 0;
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        maxx = max(maxx,x);
        add(x);
    }
    cin >> q;
    for(int i = 1;i <= q;i++){
        int x;
        scanf("%d",&x);
        if(x >= maxx) printf("%d\n",n);
        else{
            printf("%d\n",sum(x));
        }
    }
    return 0;
}