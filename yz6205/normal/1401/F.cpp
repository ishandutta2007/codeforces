#define ENABLE_LL
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
#include <bitset>
#include <sstream>
using namespace std;

#ifndef CUSTOM_MAIN
void init();
void solve();
int main(){
try { 

#ifdef MULTIPLE_TEST_CASES_WITH_T

int T; scanf("%d",&T); while(T--) {init(); solve();}

#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T

while(1) {try{init(); } catch(bool t){return 0;} solve(); }

#else

init(); solve();

#endif
#endif

} catch (...) { return 0; }
    return 0;
}
#endif

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
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr; typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; } char nextChar(){ char r; ist>>r; return r;} }; Scanner sc(cin);
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } }
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }

const int N = 1200005;
namespace STree {
    int rev[N], swp[N];

    struct Node {
        int val, dep;
        Node *l, *r;
        int lo_rev, go_rev, go_swap;
        Node () { val=dep=lo_rev=go_rev=go_swap=0; l=r=NULL; }

        void pushRev() {
            swap(l,r); lo_rev ^= 1; }
        void pushSwap() {
            swap(l,r); }
        void pushUp() {
            if (rev[dep] > go_rev) {
                if ( (rev[dep]-go_rev) % 2 == 1 ) pushRev(); 
                go_rev = rev[dep]; }
            if (swp[dep] > go_swap) {
                if ( (swp[dep]-go_swap) % 2 == 1 ) pushSwap(); 
                go_swap = swp[dep]; }
            val = 0;
            if (l) val += l->val;
            if (r) val += r->val; }
        void pushDown() {
            if (rev[dep] > go_rev) {
                if ( (rev[dep]-go_rev) % 2 == 1 ) pushRev(); 
                go_rev = rev[dep]; }
            if (swp[dep] > go_swap) {
                if ( (swp[dep]-go_swap) % 2 == 1 ) pushSwap(); 
                go_swap = swp[dep]; }
            if (lo_rev == 1) {
                if (l) l->pushRev();
                if (r) r->pushRev(); }
            lo_rev = 0; }
    };

    Node p[N], *R;
    int cnt;

    void init() {
        memset(rev,0,sizeof(rev));
        memset(swp,0,sizeof(swp));
        R = &p[0];
        cnt=1; }
    Node* newNode() {
        return &p[cnt++]; }
    void build(int l, int r, int a[], Node* u, int deep=0) {
        u->dep = deep;
        if (l==r) { u->val = a[l]; return; }
        int mid = (l+r)/2;
        build(l,mid,a,u->l=newNode(),deep+1);
        build(mid+1,r,a,u->r=newNode(),deep+1);
        u->pushUp(); }
    void modify(int w, int _val, int l, int r, Node* u) {
        u->pushDown();
        if (l==r) { u->val = _val; return; }
        int mid = (l+r)/2;
        if (w<=mid) modify(w,_val,l,mid,u->l);
        else modify(w,_val,mid+1,r,u->r); 
        u->pushUp(); }
    int query(int l, int r, int sl, int sr, Node* u) {
        u->pushDown();
        if (sl <= l && sr >= r) { return u->val; }
        int mid=(l+r)/2, ans=0;
        if (sl <= mid) ans += query(l,mid,sl,sr,u->l);
        if (sr >  mid) ans += query(mid+1,r,sl,sr,u->r); 
        ses(l);ses(r);see(ans);
        return ans; }
    void pushSwap(int dep) {
        swp[dep]++; }
    void pushRev(int dep) {
        rev[dep]++; }
}

int a[N];
int t,n,q;

void init() {
    STree::init();
    scanf(II,&t,&q); n = (1<<t); 
    rep (i,n) scanf(I,&a[i]);
    STree::build(0,n-1,a,STree::R);
}

void solve() {
    while (q--) {
        int o; scanf(I,&o);
        if (o==1) {
            int x,k; scanf(II,&x,&k); x--;
            STree::modify(x, k, 0,n-1,STree::R); }
        else if (o==2) {
            int k; scanf(I,&k);
            STree::pushRev(t-k); }
        else if (o==3) {
            int k; scanf(I,&k);
            STree::pushSwap(t-k-1); }
        else {
            int l,r; scanf(II,&l,&r); l--; r--;
            printf(IN,STree::query(0,n-1,l,r,STree::R)); }
    }
}