#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
const int maxn = 2e5 + 5;
typedef long long LL;
LL maxv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = min(maxv[o*2],maxv[o*2+1]);
}

void build(int o, int l, int r){
    maxv[o] = 0;
    if(l == r)
        return;
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}

void update(int o, int l, int r, int p, LL v){
    if(l == r){
        maxv[o] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid)
        update(lson, p, v);
    if(p > mid)
        update(rson, p, v);
    pushup(o);
}

LL querymax(int o, int l, int r, int ql, int qr){
    if(qr < ql)
        return 1e18;
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    int mid = (l + r) / 2;
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    return min(querymax(lson, ql, qr), querymax(rson, ql, qr));
}

int n, k;
char s[maxn];

vector<pair<int, int> > p[maxn];

LL dp[maxn];

int main(){
    cin >> n >> k;
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++){
        if(s[i] == '1'){
            int l = max(1, i - k);
            int r = min(n, i + k);
            p[r].push_back(make_pair(l, i));
        }
    }
    build(1, 1, n);
    for(int i = 1;i <= n;i++){
        dp[i] = 1e18;
        update(1, 1, n, i, dp[i]);
    }    
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i] = min(dp[i - 1] + i, dp[i]);
        for(auto v : p[i]){
            int l = v.first;
            int cost = v.second;
            //cout << "$$$" << endl;
            //cout << l << " " << i << " " << cost << endl;
            LL mi = querymax(1, 1, n, l, i - 1);
            //if(i == n){
                //cout << "!!!" << endl;
                //cout << l << " " << " " << mi << " " << cost << endl;
            //}
            mi = min(mi, dp[l - 1]);
            dp[i] = min(dp[i], mi + cost);
        }
        update(1, 1, n, i, dp[i]);
    }
    for(int i = 1;i <= n;i++){
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;    
    return 0;
}