//
//  main.cpp
//  C
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

const int maxn = 105;


int w;

struct pot{
    int vol;
    int id;
    int t;
    pot(int vol = 0,int id = 0,int t = 0):vol(vol),id(id),t(t){}
}a[maxn];

bool cmp1(pot a,pot b){
    return a.vol > b.vol;
}

bool cmp2(pot a,pot b){
    return a.id < b.id;
}

int main(int argc, const char * argv[]) {
    cin >> n >> w;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i].vol);
        a[i].id = i;
    }
    sort(a + 1,a + 1 + n,cmp1);
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if((a[i].vol + 1) / 2 > w){
            flag = false;
            break;
        }else{
            a[i].t = (a[i].vol + 1) / 2;
            w -= a[i].t;
        }
    }
    if(!flag){
        printf("-1\n");
        return 0;
    }else{
        for(int i = 1;i <= n;i++){
            int del = min(w,a[i].vol - a[i].t);
            w -= del;
            a[i].t += del;
            if(w == 0) break;
        }
        sort(a + 1,a + 1 + n,cmp2);
        for(int i = 1;i <= n;i++){
            printf("%d ",a[i].t);
        }
    }
    return 0;
}