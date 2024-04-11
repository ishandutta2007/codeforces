//
//  main.cpp
//  D
//
//  Created by  on 16/4/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,q;

const int maxn = 1000000 + 5;
const int maxq = 2000000 + 5;

int ans[maxn];

int main(int argc, const char * argv[]) {
   // int odd = 0;
    int pos1 = 1,pos2 = 2;
    //long long forward = 0;
    //long long move = 0;
    cin >> n >> q;
    int t,x;
    for(int i = 1;i <= q;i++){
        scanf("%d",&t);
        if(t == 1){
            scanf("%d",&x);
            pos1 += x;
            pos2 += x;
            if(pos1 > n) pos1 -= n;
            if(pos2 > n) pos2 -= n;
            if(pos1 < 1) pos1 += n;
            if(pos2 < 1) pos2 += n;
        }else{
            if(pos1 & 1) pos1++;
            else pos1--;
            if(pos2 & 1) pos2++;
            else pos2--;
        }
    }
    //ans[pos1] = 1;
    //ans[pos2] = 2;
    for(int i = 1;i <= n / 2;i++){
        int p = (pos1 + (i - 1) * 2) % n;
        if(p == 0) p += n;
        ans[p] = i * 2 - 1;
    }
    for(int i = 1;i <= n / 2;i++){
        int p = (pos2 + (i - 1) * 2) % n;
        if(p == 0) p += n;
        ans[p] = i * 2;
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c",ans[i],i == n ? '\n' : ' ');
    }
    return 0;
}