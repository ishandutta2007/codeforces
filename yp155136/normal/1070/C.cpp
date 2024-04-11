#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<ll,ll> pii;
#define F first
#define S second

ll rnd_num = 2834389458LL;

ll myRnd() {
    return (rnd_num = (rnd_num + 465465467LL)^(34185938453LL) );
}

struct Treap {
    Treap *lc,*rc;
    pii key;
    ll pri,val,sz,sum,key_mn;
    Treap(ll _core,ll _price,int id):
    lc(NULL),rc(NULL),pri(myRnd()),
    val(_core),key(make_pair(_price,id)),sum(_core*_price),
    sz(_core),key_mn(_price){}
};

LL Sz(Treap* t) {
    return t?t->sz:0;
}

LL Sum(Treap* t) {
    return t?t->sum:0;
}

LL Key_mn(Treap* t) {
    return t?t->key_mn:(1LL<<60);
}

void pull(Treap* t) {
    if (!t) return;
    t->sz = Sz(t->lc) + Sz(t->rc) + t->val;
    t->sum = Sum(t->lc) + Sum(t->rc) + t->val*t->key.F;
    t->key_mn = min( min( Key_mn(t->lc),Key_mn(t->rc) ) , t->key.F );
}

Treap* merge(Treap* a,Treap* b) {
    if (!a || !b) return a?a:b;
    else if (a->pri > b->pri) {
        a->rc = merge(a->rc,b);
        pull(a);
        return a;
    }
    else {
        b->lc = merge(a,b->lc);
        pull(b);
        return b;
    }
}

void split_by_key(Treap* t,pii k,Treap* &a,Treap* &b) {
    if (!t) a=b=NULL;
    else if (t->key <= k) {
        a=t;
        split_by_key(t->rc,k,a->rc,b);
        pull(a);
    }
    else {
        b=t;
        split_by_key(t->lc,k,a,b->lc);
        pull(b);
    }
}

void split(Treap* t,ll pre,Treap* &a,Treap* &b) {
    if (!t) a=b=NULL;
    else if (Sz(t->lc) + t->val <= pre) {
        a=t;
        split(t->rc,pre-Sz(t->lc)-t->val,a->rc,b);
        pull(a);
    }
    else {
        b=t;
        split(t->lc,pre,a,b->lc);
        pull(b);
    }
}

const int N = 1000006;

ll l[N],r[N],c[N],p[N];

vector<int> addd[N],dell[N];

#define SZ(x) ((int)(x).size())

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,m;
    cin >> n >> k >> m;
    for (int i=0;i<m;++i) {
        cin >> l[i] >> r[i] >> c[i] >> p[i];
        addd[ l[i] ].push_back(i);
        dell[ r[i]+1 ].push_back(i);
    }
    Treap* root = NULL;
    ll ans=0;
    ll pre=0;
    for (int i=1;i<=n;++i) {
        if (SZ(addd[i]) == 0 && SZ(dell[i]) == 0) {
            ans += pre;
            continue;
        }
        for (int id:addd[i]) {
            Treap *tl;
            split_by_key(root,make_pair(p[id],id),tl,root);
            root = merge(merge(tl,new Treap(c[id],p[id],id)),root);
        }
        for (int id:dell[i]) {
            Treap *tl,*tr;
            split_by_key(root,make_pair(p[id],id-1),tl,root);
            split_by_key(root,make_pair(p[id],id),root,tr);
            root = merge(tl,tr);
        }
        pre = 0;
        Treap *tl;
        split(root,k,tl,root);
        pre += Sum(tl);
        //cout << "i = " << i << endl;
        //cout << "Sum(tl) = " << Sum(tl) << " , Sz(tl) = " << Sz(tl) << endl;
        //cout << "Sum(root) = " << Sum(root) << endl;
        //cout << "Key_mn = " << Key_mn(root) << endl;
        if (root != NULL)pre += Key_mn(root)*(k-Sz(tl));
        root = merge(tl,root);
        ans += pre;
    }
    cout << ans << endl;
}