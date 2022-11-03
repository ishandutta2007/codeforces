//
//  main.cpp
//  D
//
//  Created by  on 8/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 7e6 + 5;
const int len = 30;

int ch[maxn][2],sz;
int val[maxn];

void insert(int x,int valv){
    int u = 0;
    for(int i = len - 1;i >= 0;i--){
        int t = (x >> i) & 1;
        if(ch[u][t] == 0){
            memset(ch[sz],0,sizeof(ch[sz]));
            ch[u][t] = sz++;
        }
        u = ch[u][t];
        val[u] += valv;
    }
}

int query(int x){
    int u = 0;
    int ret = x;
    for(int i = len - 1;i >= 0;i--){
        int t = 1 ^ ((x >> i) & 1);
        if(ch[u][t] == 0 || val[ch[u][t]] <= 0) t ^= 1;
        ret ^= t << i;
        u = ch[u][t];
    }
    return ret;
}

int q;

int main(int argc, const char * argv[]) {
    cin >> q;
    memset(ch[0],0,sizeof(ch[0]));
    sz = 1;
    insert(0,1);
    
    while(q--){
        char s[2];
        int x;
        scanf("%s%d",s,&x);
        if(s[0] == '?'){
            printf("%d\n",query(x));
        }else{
            if(s[0] == '+') insert(x,1);
            else insert(x,-1);
        }
    }
    return 0;
}