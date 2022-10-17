#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int LOG = 20, N = (1 << LOG);

const pii mod = {1e9 + 7, 1e9 + 9};
const pii base = {53, 59};
pii pw[N];

struct Node
{
    int sz;
    pii x;
    Node *l, *r;
    Node(char c)
    {
        sz = 1;
        x = {c - 'a' + 1, c - 'a' + 1};
        l = NULL;
        r = NULL;
    }
    Node(Node *l_, Node *r_)
    {
        l = l_;
        r = r_;
        sz = l->sz + r->sz;
        x.f = (l->x.f ^ r->x.f);
        x.s = (1ll * l->x.s * pw[r->sz].s + r->x.s) % mod.s;
    }
};

Node *t[LOG][N];

int n;
char s[N];

void out(Node *v)
{
    if (v->sz == 1)
        cerr << (char)(v->x.f + 'a' - 1);
    else
    {
        out(v->l);
        out(v->r);
    }
}

void build(int v, int k)
{
    if (k == 0)
    {
        t[k][v] = new Node(s[v]);
        return;
    }
    build(v, k - 1);
    build(v + (1 << (k - 1)), k - 1);

    for (int i = 0; i < (1 << (k - 1)); i++)
    {
        t[k][v + i] = new Node(t[k - 1][v + i], t[k - 1][v + (1 << (k - 1)) + i]);
        t[k][v + i + (1 << (k - 1))] = new Node(t[k - 1][v + (1 << (k - 1)) + i], t[k - 1][v + i]);
    }
    for (int i = 0; i < (1 << k); i++)
        assert(t[k][v + i]->sz == (1 << k));
}
bool check(Node *i, Node *j)
{
    if (i->sz == 1)
        return i->x.f <= j->x.f;

    if (i->l->x == j->l->x)
        return check(i->r, j->r);
    else
        return check(i->l, j->l);
}
void solve()
{
    scanf("%d", &n);
    scanf("%s", s);
    build(0, n);
    int p = 0;
    for (int i = 1; i < (1 << n); i++)
        if (check(t[n][i], t[n][p]))
            p = i;
    for (int i = 0; i < (1 << n); i++)
        printf("%c", s[i ^ p]);
    printf("\n");
}
int main()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].f = 1ll * pw[i - 1].f * base.f % mod.f;
        pw[i].s = 1ll * pw[i - 1].s * base.s % mod.s;
    }

    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}