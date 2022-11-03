//
//  main.cpp
//  B
//
//  Created by  on 16/5/12.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 500000 + 5;

int n,k;

int c[maxn];

long long pre[maxn];
long long suf[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) scanf("%d",c + i);
    long long sum = 0;
    for(int i = 1;i <= n;i++) sum += c[i];
    long long a,b;
    a = sum / (long long) n;
    if(sum % (long long) n == 0) b = a;
    else b = a + 1;
    long long kk = 0;
    for(int i = 1;i <= n;i++){
        if(c[i] <= a){
            kk += a - c[i];
        }
    }
    //cout << sum << endl;
    //cout << a << b << endl;
    //if(kk <= (long long)k){
        //cout << b - a << endl;
    {
        sort(c + 1,c + 1 + n);
        for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + (long long)c[i];
        for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + (long long)c[i];
        int l = 1e9 + 1,r = 0;
        for(int i = 1;i <= n;i++){
            l = min(c[i],l);
            r = max(r,c[i]);
        }
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            int pos = (int)(lower_bound(c + 1, c + 1 + n, mid) - c);
            pos --;
            if((long long)mid * (long long)pos - pre[pos] <= (long long)k) l = mid;
            else r = mid - 1;
        }
        int ll = l;
        int pos1 = (int)(lower_bound(c + 1,c + 1 + n,ll) - c);
        pos1 --;
        //cout << l << endl;
        for(int i = 1;i <= n;i++){
            l = min(c[i],l);
            r = max(r,c[i]);
        }
        while(l < r){
            int mid = (l + r) >> 1;
            int pos = (int)(upper_bound(c + 1,c + 1 + n,mid) - c);
            if(suf[pos] - (long long)mid * (long long)(n - pos + 1) <= (long long)k) r = mid;
            else l = mid + 1;
        }
        int pos2 = (int)(upper_bound(c + 1, c + 1 + n, r) - c);
        int rr = r;
        //cout << rr  << ' '<< ll << endl;
        if(pos2 <= pos1 || rr <= ll){
            cout << b - a << endl;
            return 0;
        }
        cout << rr - ll << endl;
    }
    return 0;
}