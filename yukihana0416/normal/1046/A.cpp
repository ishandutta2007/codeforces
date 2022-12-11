#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = (int) 1e5+20;

int n, K;

struct Node
{
    int sum;
    Node *lson, *rson;
    Node() {sum = 0, lson = rson = NULL;}
};

map<int, Node*> G;
struct Robot {int x, r, q;};
vector< Robot > vec;
int ers[maxn];
int pos[maxn];

void ins(int pos, int val, int l, int r, Node *&o)
{
    if(o == NULL) o = new Node();
    if(l == r)
    {
        o->sum += val;
        return ;
    }

    int mid = (l + r) >> 1;
    if(pos <= mid) ins(pos, val, l, mid, o->lson);
    else ins(pos, val, mid + 1, r, o->rson);
    o->sum = 0;
    if(o->lson) o->sum += o->lson->sum;
    if(o->rson) o->sum += o->rson->sum;
}

int query(int L, int R, int l, int r, Node *&o)
{
    if(o == NULL) return 0;
    if(L <= l && r <= R) return o->sum;

    int mid = (l + r) >> 1;
    if(R <= mid) return query(L, R, l, mid, o->lson);
    if(mid < L)  return query(L, R, mid + 1, r, o->rson);
    return query(L, R, l, mid, o->lson) + query(L, R, mid + 1, r, o->rson);
}

void work()
{
    scanf("%d%d", &n, &K);
    vec = vector< Robot > (n);
    for(int i = 0; i < n; i++)
    {
        int x, r, q;
        scanf("%d%d%d", &x, &r, &q);
        vec[i] = (Robot) {x, r, q};
    }
    iota(ers, ers + n, 0);
    iota(pos, pos + n, 0);

    sort(ers, ers + n, [](int x, int y) {return vec[x].x + vec[x].r < vec[y].x + vec[y].r;});
    sort(pos, pos + n, [](int x, int y) {return vec[x].x < vec[y].x;});

//    for(int i =  0; i < n; i++) cout <<ers[i] <<" "; cout <<endl;

    LL ans = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        int u = pos[i], v = ers[j];
        int p = vec[u].x;
        while(j < n && vec[v].x + vec[v].r < p)
        {
            ins(vec[v].x, -1, 0, 1e9, G[vec[v].q]);
            v = ers[++j];
        }

        for(int k = -K; k <= K; k++)
            ans += query(vec[u].x - vec[u].r, vec[u].x, 0, 1e9, G[k + vec[u].q]);

//        cout <<"query end !" <<endl;
        if(G.find(vec[u].q) == G.end())
        {
//            cout <<"find not!" <<endl;
            G[vec[u].q] = new Node();
        }

        ins(vec[u].x, 1, 0, 1e9, G[vec[u].q]);
    }

    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    work();
    return 0;
}