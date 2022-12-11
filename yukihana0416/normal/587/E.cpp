#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) (((l)+(r))>>1)

const int MOD = (int) 1e9 + 7;
const double eps = (double) 1e-8;
const int maxn = (int) 2e5 + 20;

struct Node
{
    int r, flag;
    vector<int> base;

    Node() {r = flag = 0; base.clear();}
};
Node T[maxn << 2];

int n, m;
int a[maxn];

void ins(vector<int> &base, int v)
{
    for(auto vv : base)
        v = min(v, vv ^ v);
    if(v) base.push_back(v);
}

Node mer(const Node &x, const Node &y)
{
    Node ans;
    for(const auto v : x.base)
        ins(ans.base, v);
    for(const auto v : y.base)
        ins(ans.base, v);

    ins(ans.base, x.r ^ y.r);
    ans.r = y.r;
    return ans;
}

void build(int l, int r, int id)
{
    if(l == r)
    {
        T[id].base.clear();
        T[id].r = a[l];
        T[id].flag = 0;
        return ;
    }
    int mid = MID(l, r);
    build(lson);
    build(rson);
    T[id] = mer(T[ls], T[rs]);
}

void lazy(int id)
{
    if(T[id].flag)
    {
        int flag = T[id].flag;
        T[ls].r ^= flag; T[ls].flag ^= flag;
        T[rs].r ^= flag; T[rs].flag ^= flag;
        T[id].flag = 0;
    }
}

void update(int x, int L, int R, int l, int r, int id)
{
    if(L <= l && r <= R)
    {
        T[id].r ^= x;
        T[id].flag ^= x;
        return ;
    }
    lazy(id);
    int mid = MID(l, r);
    if(L <= mid) update(x, L, R, lson);
    if(mid < R)  update(x, L, R, rson);
    T[id] = mer(T[ls], T[rs]);
}

void query(Node &res, int L, int R, int l, int r, int id)
{
    if(L <= l && r <= R)
    {
        res = mer(res, T[id]);
        return ;
    }
    lazy(id);
    int mid = MID(l, r);
    if(L <= mid) query(res, L, R, lson);
    if(mid < R)  query(res, L, R, rson);
}


void work()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, n, 1);

    for(int i = 0; i < m; i++)
    {
        int opt;
        int l, r, x;
        scanf("%d%d%d", &opt, &l, &r);
        if(opt == 2)
        {
            Node ans;
            query(ans, l, r, 1, n, 1);
            printf("%d\n", 1 << ans.base.size());
        }
        else
        {
            scanf("%d", &x);
            update(x, l, r, 1, n, 1);
        }
    }
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r" ,stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416

    int tc = 1;
//    scanf("%d", &tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}