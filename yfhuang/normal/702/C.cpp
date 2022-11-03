//
//  main.cpp
//  C
//
//  Created by  on 7/30/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;

const int maxn = 1e5 + 5;
const int INF = 1e9 + 5;

int a[maxn];
int b[maxn];

struct Point{
    int x;
    int type;
    int id;
    bool operator < (const Point & rhs) const{
        return x < rhs.x || (x == rhs.x && type < rhs.type);
    }
}p[maxn << 1];

int r[maxn];

bool cmp(Point a,Point b){
    return a.x > b.x || (a.x == b.x && a.type < b.type);
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) r[i] = 2e9 + 5;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        p[i].type = 1;
        p[i].x = a[i];
        p[i].id = i;
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",b + i);
        p[i + n].type = 0;
        p[i + n].x = b[i];
        p[i].id = i;
    }
    sort(p + 1,p + 1 + n + m);
    bool flag = false;
    int l = -1e9 - 5;
    for(int i = 1;i <= n + m ;i++){
        if(p[i].type == 0){
            flag = true;
            l = p[i].x;
        }else{
            if(flag){
                r[p[i].id] = min(r[p[i].id],p[i].x - l);
            }
        }
    }
    sort(p + 1,p + 1 + n + m,cmp);
    flag = false;
    l = 1e9 + 5;
    for(int i = 1;i <= n + m;i++){
        if(p[i].type == 0){
            flag = true;
            l = p[i].x;
        }else{
            if(flag){
                r[p[i].id] = min(r[p[i].id],l - p[i].x);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(r[i],ans);
    cout << ans << endl;
    return 0;
}