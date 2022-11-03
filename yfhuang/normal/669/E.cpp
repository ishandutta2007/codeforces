//
//  main.cpp
//  E
//
//  Created by  on 16/4/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;

struct opt{
    int type;
    int t;
    int x;
    int id;
    int ans;
    int tid;
}a[maxn];

bool cmp1(opt a,opt b){
    return a.x < b.x || (a.x == b.x && a.id < b.id);
}

bool cmp2(opt a,opt b){
    return a.id < b.id;
}

int c[maxn];

struct app{
    int key;
    int id;
}id[maxn];

bool cmp3(app a,app b){
    return a.key < b.key;
}

bool cmp4(app a,app b){
    return a.id < b.id;
}

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= x & -x;
    }
    return ret;
}

void add(int x,int d){
    while(x < maxn){
        c[x] += d;
        x += x & -x;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&a[i].type,&a[i].t,&a[i].x);
        a[i].id = i;
        a[i].ans = 0;
    }
    sort(a + 1,a + 1 + n,cmp1);
    memset(c,0,sizeof(c));
    for(int i = 1,j = 1;i <= n;i = j + 1,j = i){
        while(j < n && a[j].x == a[j + 1].x) j++;
        int tot = 0;
        for(int k = i;k <= j;k++){
            id[++tot].key = a[k].t;
            id[tot].id = k;
        }
        sort(id + 1,id + tot + 1,cmp3);
        for(int k = 1;k <= tot;k++){
            id[k].key = k;
        }
        sort(id + 1,id + tot + 1,cmp4);
        for(int k = i;k <= j;k++){
            a[k].tid = id[k - i + 1].key;
        }
        for(int k = i;k <= j;k++){
            if(a[k].type == 1){
                add(a[k].tid,1);
            }else if(a[k].type == 2){
                add(a[k].tid,-1);
            }else{
                a[k].ans = sum(a[k].tid);
            }
        }
        for(int k = i;k <= j;k++){
            if(a[k].type == 1) add(a[k].tid,-1);
            else if(a[k].type == 2)add(a[k].tid,1);
        }
    }
    sort(a + 1,a + 1 + n,cmp2);
    for(int i = 1;i <= n;i++){
        if(a[i].type == 3)
            printf("%d\n",a[i].ans);
    }
    return 0;
}