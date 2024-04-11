//
//  main.cpp
//  D
//
//  Created by  on 16/5/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

const int maxn = 100000 + 5;

long long k;

int a[maxn];
int b[maxn];

struct st{
    int q;
    int p;
    int id;
    bool operator < ( const st& rhs)const{
        return q < rhs.q;
    }
}c[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&b[i]);
    }
    for(int i = 1;i <= n;i++){
        c[i].q = b[i] / a[i];
        c[i].p = b[i] % a[i];
        c[i].id = i;
    }
    long long sum = 0;
    long long x = 0;
    sort(c + 1,c + 1 + n);
    long long ans = 0;
    for(int i = 1,j = 1;i <= n;i = j + 1,j = i){
        if(i > 1)
        {if( (long long)c[i].q   <= (k + sum) / x) ans = max(ans,(long long)c[i].q);else break;}
        while(j < n && c[j].q == c[j + 1].q){
            j++;
        }
        for(int l = i;l <= j;l++){
            sum += b[c[l].id];
            x += a[c[l].id];
        }
        long long temp = (k + sum) / x;
        if(j < n)
            temp = min(temp,(long long)c[j + 1].q);
        ans = max(ans,temp);
    }
    cout << ans << endl;
    return 0;
}