#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

const int N = 1000005;

struct Node {
    int t, m;
    Node *l, *r;

    Node () { t = 0; l = r = NULL; }
    ~Node () {
        if (l != NULL) delete l;
        if (r != NULL) delete r;
    }

    void pushUp () {
        m = min(l->m, r->m);
        see(m);
    }

    void pushDown () {
        l->t += t; r->t += t;
        l->m += t; r->m += t;
        t = 0;
    }
};

struct STree{
    Node* R;

    STree () { R = new Node(); }

    void build (int l, int r, Node* p = NULL) { 
        if (p == NULL) p = R;
        if (l == r) { p->m = 0; return; }
        int m = (l + r) >> 1;
        build(l  , m, p->l = new Node());
        build(m+1, r, p->r = new Node());
        p->pushUp();
    }

    void modify (int l, int r, int ul, int ur, int d, Node* p = NULL) {
        ses(l);ses(r);ses(ul);ses(ur);see(d);
        if (p == NULL) p = R;
        if (ul != ur) p->pushDown();
        if (ul >= l && ur <= r) {
            p->t += d; p->m += d;
            return ;
        }
        int m = (ul + ur) >> 1;
        if (l <= m) modify(l, r, ul , m , d, p->l);
        if (r >  m) modify(l, r, m+1, ur, d, p->r);
        p->pushUp();
    }

    int query (int l, int r, Node* p = NULL) {
        if (p == NULL) p = R;
        if (l != r) p->pushDown();
        see(p->m);
        if (p->m >= 0) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        if (p->r->m < 0) return query(m+1, r, p->r);
        else return query(l, m, p->l); 
    }

    ~STree () { delete R; }
};

int n, m; //n represents dishes, m students
int d[N], p[N]; // d(dishes); p(pupils)
STree st;
const int E = 1000001;
void init() {
    scanf(II,&n,&m);
    rep (i,n) scanf(I,&d[i]);
    rep (i,m) scanf(I,&p[i]);    
    st.build(0, E);
    rep (i,m) st.modify(0,p[i],0,E,1);
    rep (i,n) st.modify(0,d[i],0,E,-1);
}

void solve() {
    int q; scanf(I,&q);
    while (q--) {
        int opt, id, nv; scanf(III,&opt,&id,&nv); id--;
        if (opt == 1) { 
            st.modify(0,d[id],0,E,1);
            st.modify(0,d[id] = nv,0,E,-1);
        }else {
            st.modify(0,p[id],0,E,-1);
            st.modify(0,p[id] = nv,0,E,1);
        }
        printf(IN,st.query(0,E));
    }
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}
//