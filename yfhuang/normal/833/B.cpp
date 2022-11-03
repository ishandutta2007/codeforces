#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

const int maxn = 35000 + 5;

int n,k;
int Left[maxn];
int Last[maxn];
int maxv[maxn << 2];
int dp[55][maxn];
int lazy[maxn << 2];
int a[maxn];
void pushup(int o){
    maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
}

void pushdown(int o){
   maxv[o * 2] += lazy[o];
    maxv[o * 2 + 1] += lazy[o];
    lazy[o * 2] += lazy[o];
    lazy[o * 2 + 1] += lazy[o];
    lazy[o] = 0;
}

void build(int o,int l,int r,int step){
    lazy[o] = 0;
    if(l == r){
        maxv[o] = dp[step][l - 1];
        return;
    }
    int mid = (l + r) / 2;
    build(o * 2,l,mid,step);
    build(o * 2 + 1,mid + 1,r,step);
    pushup(o);
}

void update(int o,int l,int r,int ql,int qr,int v){
    if(ql <= l && r <= qr){
        lazy[o] += v;
        maxv[o] += v;
        return;
    }
    pushdown(o);
    int mid = (l + r) / 2;
    if(ql <= mid)update(o * 2,l,mid,ql,qr,v);
    if(qr > mid)update(o * 2 + 1,mid + 1,r,ql,qr,v);
    pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    pushdown(o);
    int mid = (l + r) / 2;
    int ans = -1e9;
    if(ql <= mid) ans = max(ans,query(o * 2,l,mid,ql,qr));
    if(qr > mid) ans = max(ans,query(o * 2 + 1,mid + 1,r,ql,qr));
    return ans;
}

int main(){
    while(cin >> n >> k){
        for(int i = 1;i <= n;i++) Last[i] = 0;
       for(int i = 1;i <= n;i++){
           scanf("%d",a + i);
           Left[i] = Last[a[i]];
            Last[a[i]] = i;
       }
        for(int i = 1;i <= n;i++) dp[0][i] = -1e5;
        dp[0][0] = 0;
        for(int i = 1;i <= k;i++){
           build(1,1,n,i - 1);
            for(int j = 1;j <= n;j++){
                update(1,1,n,Left[j] + 1,j,1);
                dp[i][j] = query(1,1,n,1,j);
            }
        }
        cout << dp[k][n] << endl;
    }

    return 0;
}