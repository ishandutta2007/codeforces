//
//  main.cpp
//  E
//
//  Created by  on 16/7/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 200000 + 5;

int n,k;

int l[maxn],r[maxn];

const long long mod = 1e9 + 7;


int sumv[maxn << 4];
int addv[maxn << 4];

void maintain(int o,int l,int r){
    int lc = o * 2,rc = o * 2 + 1;
    sumv[o] = 0;
    if(r > l){
        sumv[o] = sumv[lc] + sumv[rc];
    }
    sumv[o] += addv[o] * (r - l + 1);
}

int y1,y2;

void update(int o,int l,int r){
    int lc = o * 2,rc = o * 2 + 1;
    if(y1 <= l && y2 >= r){
        addv[o] ++;
    }else{
        int m = l + (r - l) / 2;
        if(y1 <= m) update(lc,l,m);
        if(y2 > m) update(rc,m + 1,r);
    }
    maintain(o,l,r);
}

int _sum;
void query(int o,int l,int r,int add){
    if(y1 <= l && y2 >= r){
        _sum += sumv[o] + add * (r - l + 1);
    }else{
        int m = l + (r - l) / 2;
        if(y1 <= m) query(o * 2, l, m, add + addv[o]);
        if(y2 > m) query(o * 2 + 1,m + 1,r,add + addv[o]);
    }
}

int xx[maxn << 2];

long long fac[maxn];
long long inv[maxn];

long long mod_pow(long long a,long long n){
    long long ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ret;
}

void table(){
    fac[0] = fac[1] = 1;
    for(int i = 2;i < maxn;i++){
        fac[i] = fac[i - 1] * (long long)(i) % mod;
    }
    inv[0] = inv[1] = 1;
    for(int i = 2;i < maxn;i++){
        inv[i] = mod_pow(fac[i], mod - 2);
    }
}

bool vis[maxn << 1];

struct Event{
    int p,v;
    bool operator < (const Event & rhs) const{
        return p < rhs.p;
    }
}E[maxn << 1];

long long C(int cnt,int k){
    if(k > cnt) return 0;
    return ((fac[cnt] * inv[k] % mod * inv[cnt - k] % mod));
}



int main(int argc, const char * argv[]) {
    cin >> n >> k;
    table();
    int tot = 0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&l[i],&r[i]);
//        xx[nn++]=l[i];
//        xx[nn++]=r[i];
        E[tot++] = (Event){l[i] - 1,1};
        E[tot++] = (Event){r[i],-1};
    }
    sort(E,E + tot);
    int cnt = 0;
    long long res = 0;
    int pre = -2e9;
    for(int i = 0;i < tot;i++){
        res = (res + C(cnt,k) * (E[i].p - pre)) % mod;
        //cout << res << endl;
        pre = E[i].p;
        cnt += E[i].v;
    }
    cout << res << endl;
//    
//    sort(xx,xx+nn);
//    nn=unique(xx,xx+nn)-xx;
//    for(int i=nn-1;i>0;i--)
//        if(xx[i]!=xx[i-1]+1) xx[nn++]=xx[i-1]+1;
//    sort(xx,xx+nn);
//    memset(addv,0,sizeof(addv));
//    memset(sumv,0,sizeof(sumv));
//    memset(vis,false,sizeof(vis));
//    for(int i = 0;i < n;i++){
//        int L = lower_bound(xx,xx + nn,l[i]) - xx;
//        int R = lower_bound(xx,xx + nn,r[i]) - xx;
//        y1 = L,y2 = R;
//        vis[L] = vis[R] = true;
//        update(1, 0, nn);
//    }
//    long long ans = 0;
//    for(int i = 0;i < nn;i++){
//        y1 = y2 = i;
//        _sum = 0;
//        query(1,0,nn,0);
//        long long temp = 0;
//        if(_sum >= k) temp =( (fac[_sum] * inv[k]) % mod * inv[_sum - k]) % mod;
//        if(vis[i]){
//            ans  = (ans + temp) % mod;
//            continue;
//        }
//        if(i == 0){
//            ans = (ans + temp * (xx[i + 1] - xx[i]) % mod ) % mod;
//        }else if(i == nn - 1){
//            ans = (ans + temp * (xx[nn - 1] - xx[nn - 2]) % mod) % mod;
//        }else{
//            ans = (ans + temp * (xx[i + 1] - xx[i - 1] - 1) % mod) % mod;
//        }
//    }
//    cout << ans << endl;
    return 0;
}