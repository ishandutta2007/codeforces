#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

struct barrier{
    int u, l, r, s, index;
    barrier(){}
    barrier(int u, int l, int r, int s, int index): u(u), l(l), r(r), s(s), index(index){}
    bool operator <(const barrier& b) const{
        return u < b.u;
    }
};

stack <int> tree[4 * MAXN];
barrier v[MAXN];

void refresh(int i, int height){
    while(!tree[i].empty() && v[tree[i].top()].u + v[tree[i].top()].s < height)
        tree[i].pop();
}

pair <int, int> query(int i, int L, int R, int u, int height){
    refresh(i, height);

    if(u < L || R < u)return make_pair(-1, -1);
    
    pair <int, int> q;
    
    if(tree[i].empty())q = make_pair(-1, -1);
    else q = make_pair(v[tree[i].top()].u, tree[i].top());
    
    if(L < R){
        int mid = (L + R) / 2;
    
        q = max(q, query(2 * i, L, mid, u, height));
        q = max(q, query(2 * i + 1, mid + 1, R, u, height));
    }

    return q;
}
void update(int i, int L, int R, int u){
    if(v[u].r < L || R < v[u].l)return;
    if(v[u].l <= L && R <= v[u].r){
        while(!tree[i].empty() && v[tree[i].top()].u + v[tree[i].top()].s <= v[u].u + v[u].s)
            tree[i].pop();
        tree[i].push(u);

        return;
    }

    int mid = (L + R) / 2;
    
    update(2 * i, L, mid, u);
    update(2 * i + 1, mid + 1, R, u);
}

int main(){
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &v[i].u, &v[i].l, &v[i].r, &v[i].s);
        v[i].index = i;
    }
    sort(v, v + n);

    vector <long long> dp(n, 0);
    
    for(int i = 0; i < n; i++){
        pair <int, int> ql = make_pair(-1, -1);
        pair <int, int> qr = make_pair(-1, -1);
        
        if(v[i].l > 1){
            ql = query(1, 1, w, v[i].l - 1, v[i].u);
        }

        if(v[i].r < w){
            qr = query(1, 1, w, v[i].r + 1, v[i].u); 
        }
        
        if(v[i].l > 1){
            if(ql.first == -1){
                dp[i] = 1;
            }else{
                dp[i] = dp[ql.second];
            }
        }else{
            if(qr.first == -1){
                dp[i] = 1;
            }else{
                dp[i] = dp[qr.second];
            }
        }

        if(v[i].r < w){
            if(qr.first == -1){
                dp[i] = (dp[i] + 1) % MOD;
            }else{
                dp[i] = (dp[i] + dp[qr.second]) % MOD;
            }
        }else{
            if(ql.first == -1){
                dp[i] = (dp[i] + 1) % MOD;
            }else{
                dp[i] = (dp[i] + dp[ql.second]) % MOD;
            }
        }

        update(1, 1, w, i);
    }

    long long res = 0;
    for(int i = 1; i <= w; i++){
        pair <int, int> q = query(1, 1, w, i, h + 1);

        if(q.first == -1){
            res = (res + 1) % MOD;
        }else{
            res = (res + dp[q.second]) % MOD;
        }
    }
    printf("%lld\n", res);

    return 0;
}