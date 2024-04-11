//
//  main.cpp
//  E
//
//  Created by  on 16/2/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;

const int maxn = 2e5+16;

int x[maxn];
long long pre[maxn];

struct f{
    long long a,b;
    
    inline bool operator < (const f &rhs) const{
        return a * rhs.b < b * rhs.a;
    }
};

f best;
int bi,bk;

inline f get(int i,int k){
    long long value = pre[i] - pre[i - k - 1];
    value += pre[n] - pre[n - k];
    f cur = f {value, 2LL * k + 1LL};
    cur.a -= x[i] * cur.b;
    if(best < cur){
        best = cur;
        bi = i;
        bk = k;
        //cout << best.a <<' ' <<best.b<<' '<<i<<' '<<k<<endl;
    }
    return cur;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&x[i]);
    }
    sort(x + 1, x + n + 1);
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + x[i];
    }
    best = {0, 1};
    bi = 1, bk = 0;
    for(int i = 1; i <= n; i++){
        int r = min(i - 1, n - i);
        int l = 0;
        //printf("%d %d\n",l,r);
        while( l + 3 < r){
            int ll = (l * 2 + r) / 3;
            int rr = (l + 2 * r) / 3;
            f ans1 = get (i, ll);
            f ans2 = get (i, rr);
            if(ans1 < ans2) l = ll;
            else r = rr;
        }
        for(int k = l; k <= r; k++){
            get (i, k);
        }
    }
    //get(2,1);
    //printf("%d %d\n\n",get(1,0).a,get(2,1).a);
    //printf("%d %d\n\n",get(1,0).b,get(2,1).b);
    //printf("%d %d\n",bi,bk);
    vector <int > res;
    for(int i = bi - bk; i <= bi; i++){
        res.push_back(x[i]);
    }
    for(int i = n - bk + 1; i <= n; i++){
        res.push_back(x[i]);
    }
    int sz = res.size();
    printf("%d\n",sz);
    for(int i = 0; i < sz; i++){
        printf("%d%c",res[i],i != sz - 1 ? ' ' : '\n');
    }
    return 0;
}