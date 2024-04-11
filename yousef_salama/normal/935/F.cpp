#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long long INF = -1LL << 60;

array <long long, 5> tree[4 * MAXN];
int n;
long long d[MAXN];

array <long long, 5> add(const array <long long, 5>& a, const array <long long, 5>& b){
    array <long long, 5> ret = {{INF, INF, INF, INF, INF}};

    for(int i = -2; i <= 2; i++)
    for(int j = -2; j <= 2; j++){
        if(-2 > i + j || i + j > 2)continue;
        ret[i + j + 2] = max(ret[i + j + 2], a[i + 2] + b[j + 2]);
    }
    return ret;
}
array <long long, 5> combine(const array <long long, 5>& a, const array <long long, 5>& b){
    array <long long, 5> ret;
    
    for(int i = 0; i < 5; i++)
        ret[i] = max(a[i], b[i]);

    return ret;
}

array <long long, 5> get_array1(long long other){
    if(other >= 0){
        return {{INF, 0, INF, -2LL * other, INF}};
    }else{
        return {{INF, INF, INF, 0, INF}};
    }
}

array <long long, 5> get_array2(int i){
    if(i == 0){
        return get_array1(d[i]);
    }else if(i == n - 1){
        return get_array1(-d[n - 1]);
    }else{
        return add(get_array1(-d[i - 1]), get_array1(d[i]));
    }
}

long long evaluate(const array <long long, 5>& a, long long x){
    long long ret = INF;
    for(int i = -2; i <= 2; i++)
        ret = max(ret, i * x + a[i + 2]);
    return ret;
}

void build(int i, int L, int R){
    if(L == R){
        tree[i] = get_array2(L);
    }else{
        int mid = (L + R) / 2;

        build(2 * i, L, mid);
        build(2 * i + 1, mid + 1, R);

        tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
    }
}

void update(int i, int L, int R, int u){
    if(u < L || R < u)return;

    if(L == R){
        tree[i] = get_array2(L);
    }else{
        int mid = (L + R) / 2;

        update(2 * i, L, mid, u);
        update(2 * i + 1, mid + 1, R, u);

        tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
    }
}

array <long long, 5> query(int i, int L, int R, int u, int v){
    if(v < L || R < u){
        return {{INF, INF, INF, INF, INF}};
    }
    if(u <= L && R <= v){
        return tree[i];
    }

    int mid = (L + R) / 2;
    return combine(query(2 * i, L, mid, u, v), query(2 * i + 1, mid + 1, R, u, v));
}


int main(){
    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long F = 0;

    for(int i = 0; i + 1 < n; i++){
        d[i] = a[i + 1] - a[i];
        F += llabs(d[i]);
    }
    build(1, 0, n - 1);

    int q;
    scanf("%d", &q);

    while(q--){
        int t, l, r, x;
        scanf("%d %d %d %d", &t, &l, &r, &x);
        l--, r--;

        if(t == 1){
            printf("%lld\n", F + evaluate(query(1, 0, n - 1, l, r), x));
        }else{
            if(l > 0){
                F -= llabs(d[l - 1]);
                d[l - 1] += x;
                F += llabs(d[l - 1]);

                update(1, 0, n - 1, l - 1);
                update(1, 0, n - 1, l);
            }
            if(r + 1 < n){
                F -= llabs(d[r]);
                d[r] -= x;
                F += llabs(d[r]);

                update(1, 0, n - 1, r);
                update(1, 0, n - 1, r + 1);
            }
        }
    }

    return 0;
}