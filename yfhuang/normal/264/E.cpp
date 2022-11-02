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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 2e5 + 1000;

int n, m;

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

struct segtree{
    int maxv[maxn << 2];
    segtree(){
        memset(maxv, 0, sizeof(maxv));
    }
    void pushup(int o){
        maxv[o] = max(maxv[o*2], maxv[o*2+1]);
    }
    void update(int o, int l, int r, int p, int v){
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
    int query(int o, int l, int r, int ql, int qr){
        if(ql <= l and r <= qr){
            return maxv[o];
        }
        int mid = (l + r) / 2;
        int ans = 0;
        if(ql <= mid){
            ans = max(ans, query(lson, ql, qr));
        }
        if(qr > mid){
            ans = max(ans, query(rson, ql, qr));
        }
        return ans;
    }
    void change(int p, int v){
        //cout << "!!!" << endl;
        update(1, 1, maxn - 1, p, v);
    }
    int ask(int ql){
        return query(1, 1, maxn - 1, ql, maxn - 1);
    }
}segx, segy;

priority_queue<int, vector<int>, greater<int> > pq;

int height[maxn], pos[maxn];
int tmp[20];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= m;i++){
        int type;
        scanf("%d", &type); 
        if(type == 1){
            int p, h;
            scanf("%d%d", &p, &h);
            height[p] = h - i + 200000;
            pos[height[p]] = p;
            for(int j = 200000 - i;j < height[p];j++)if(pos[j]){
                segx.change(pos[j], 0);
                segy.change(j, 0);
            }
            for(int j = height[p];j >= 200000 - i;j--)if(pos[j]){
                int res = segx.ask(pos[j]) + 1;
                segx.change(pos[j], res);
                segy.change(j, res);
            }
            pq.push(p);
        }else{
            int x;
            scanf("%d", &x);
            for(int i = 1;i <= x;i++){
                tmp[i] = pq.top();
                pq.pop();
                segx.change(tmp[i], 0);
                segy.change(height[tmp[i]], 0);
            }
            pos[height[tmp[x]]] = 0;
            height[tmp[x]] = 0;
            for(int i = x - 1;i >= 1;i--){
                int res = segy.ask(height[tmp[i]]) + 1;
                segx.change(tmp[i], res);
                segy.change(height[tmp[i]], res);
                pq.push(tmp[i]);
            }
        }
        printf("%d\n", segx.maxv[1]);
    }
    return 0;
}