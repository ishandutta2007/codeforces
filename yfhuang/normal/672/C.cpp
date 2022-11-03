//
//  main.cpp
//  A
//
//  Created by  on 16/5/12.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 5;

struct Point{
    int x,y;
    void read(){
        scanf("%d%d",&x,&y);
    }
}p[maxn],a,b,t;

double da[maxn],db[maxn],dt[maxn];

struct app{
    double x;
    int id;
    bool operator < (const app & rhs) const{
        return x < rhs.x;
    }
}at[maxn],bt[maxn];

int n;

double dis(Point a,Point b){
    return sqrt(1.0 * (double)(a.x - b.x) * (a.x - b.x) + 1.0 * (double)(a.y - b.y) * (a.y - b.y));
}

int main(int argc, const char * argv[]) {
    a.read(),b.read(),t.read();
    cin >> n;
    for(int i = 1;i <= n;i++){
        p[i].read();
        da[i] = dis(p[i],a);
        db[i] = dis(p[i],b);
        dt[i] = dis(p[i],t);
        at[i].x = da[i] - dt[i];
        at[i].id = i;
        bt[i].x = db[i] - dt[i];
        bt[i].id = i;
    }
    sort(at + 1,at + 1 + n);
    sort(bt + 1,bt + 1 + n);
    double ans = 0;
    double sum = 0;
    for(int i = 1;i <= n;i++){
        sum += 2 * dt[i];
    }
    ans = min(sum + at[1].x,sum + bt[1].x);
    if(at[1].id != bt[1].id){
        ans = min(ans,sum + at[1].x + bt[1].x);
    }else{
        ans = min(min(ans,sum + at[1].x + bt[2].x),sum + at[2].x + bt[1].x);
    }
    printf("%.10lf\n",ans);
    return 0;
}