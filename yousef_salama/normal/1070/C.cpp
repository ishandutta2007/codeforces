#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

long long tree[2][4 * MAXN], flag[2][4 * MAXN];
void push(int t, int i, int l, int r){
    if(l < r){
        flag[t][2 * i] += flag[t][i];
        flag[t][2 * i + 1] += flag[t][i];
    }
    tree[t][i] += flag[t][i];
    flag[t][i] = 0;
}
void update(int t, int i, int l, int r, int u, int v, long long val){
    push(t, i, l, r);
    if(r < u || v < l)return;
    if(u <= l && r <= v){
        flag[t][i] += val;
        push(t, i, l, r);
        return;
    }

    int mid = (l + r) / 2;
    
    update(t, 2 * i, l, mid, u, v, val);
    update(t, 2 * i + 1, mid + 1, r, u, v, val);

    tree[t][i] = max(tree[t][2 * i], tree[t][2 * i + 1]);
}

long long k, total;
void find_k(int i, int l, int r, long long last){
    push(0, i, l, r);
    push(1, i, l, r);
    
    if(tree[0][i] < k)return;

    if(l == r){
        total += tree[1][i] - (tree[0][i] - k) * last;
        tree[0][i] = -1LL << 50;
        return;
    }

    int mid = (l + r) / 2;

    find_k(2 * i, l, mid, last);
    find_k(2 * i + 1, mid + 1, r, last);

    tree[0][i] = max(tree[0][2 * i], tree[0][2 * i + 1]);
}
void find_positive(int i, int l, int r){
    push(0, i, l, r);
    push(1, i, l, r);
    
    if(tree[0][i] < 0)return;

    if(l == r){
        total += tree[1][i];
        tree[0][i] = -1LL << 50;
        return;
    }

    int mid = (l + r) / 2;

    find_positive(2 * i, l, mid);
    find_positive(2 * i + 1, mid + 1, r);

    tree[0][i] = max(tree[0][2 * i], tree[0][2 * i + 1]);    
}

struct plan{
    int l, r, c, p;
    plan(){}
    bool operator <(const plan& y) const{
        return p < y.p;
    }
};

int main(){
    int n, m;
    scanf("%d %lld %d", &n, &k, &m);

    vector <plan> v(m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d %d", &v[i].l, &v[i].r, &v[i].c, &v[i].p);
        v[i].l--, v[i].r--;
    }
    sort(v.begin(), v.end());

    total = 0;
    for(plan x : v){
        update(0, 1, 0, n - 1, x.l, x.r, x.c);
        update(1, 1, 0, n - 1, x.l, x.r, 1LL * x.c * x.p);

        find_k(1, 0, n - 1, x.p);
    }
    find_positive(1, 0, n - 1);

    printf("%lld\n", total);

    return 0;
}