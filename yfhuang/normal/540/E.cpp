//
//  main.cpp
//  E
//
//  Created by  on 10/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn],b[maxn];
int p[maxn * 2];
int c[maxn * 2];
int T[maxn * 2];

int n;

map<int,int> ID;

long long res;

void merge_sort(int x,int y){
    if(y - x > 1){
        int m = x + (y - x) / 2;
        int p = x,q = m,i = x;
        merge_sort(x, m);
        merge_sort(m, y);
        while(p < m || q < y){
            if(q >= y || (p < m && c[p] <= c[q])) T[i++] = c[p++];
            else{
                T[i++] = c[q++];
                res += m - p;
            }
        }
        for(i = x;i < y;i++) c[i] = T[i];
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d",a + i,b + i);
        p[i * 2 - 1] = a[i];
        p[i * 2] = b[i];
    }
    sort(p + 1,p + 1 + 2 * n);
    int cnt = unique(p + 1,p + 1 + 2 * n) - p - 1;
    //cout << cnt << endl;
    for(int i = 1;i <= cnt;i++){
        ID[p[i]] = i;
        c[i] = p[i];
    }
    for(int i = 1;i <= n;i++){
        int x = ID[a[i]];
        int y = ID[b[i]];
        swap(c[x],c[y]);
       // swap(p[x],p[y]);
    }
    
    long long ans = 0;
    for(int i = 1;i <= cnt;i++){
        int now = p[i];
        int pre = c[i];
        int preid = ID[c[i]];
        ans += abs(now - pre) - 1 - (abs(preid - i) - 1);
    }
    res = 0;
    merge_sort(1,cnt + 1);
    //cout << res << endl;
    //cout << ans << endl;
    ans += res;
    cout << ans << endl;
    return 0;
}