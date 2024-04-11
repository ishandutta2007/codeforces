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

void init();
void solve();
int main(){
try { 

#ifndef CUSTOM_MAIN
#ifdef MULTIPLE_TEST_CASES_WITH_T

int T; scanf("%d",&T); while(T--) {init(); solve();}

#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T

while(1) {try{init(); } catch(bool t){return 0;} solve(); }

#else

init(); solve();

#endif
#endif
#endif

} catch (const char* s) { return 0; }
    return 0;
}

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

const int N = 200005;
int a[N]; int n;

struct Node {
    Node* s[2]; 
    int d, l, r;
    Node () { s[0] = s[1] = NULL; d=r=0; l=0x3f3f3f3f; } };
struct Trie {
    Node* R;
    long long ans;
    Trie () { R= new Node(); }
    void insert(int a, int id) {
        Node* p=R;
        repb (i,29,0) {
            int pos=(a>>i)&1;
            if (p->s[pos]==NULL) p->s[pos]=new Node(); 
            p->d=i; checkMin(p->l,id); checkMax(p->r,id); p=p->s[pos]; }
        checkMin(p->l,id); checkMax(p->r,id); p->d=-1; }
    int query (Node* u, int a) {
        ses(a);see(u->d);
        a &= ((1<<(u->d+1))-1);
        a |= (1<<(u->d+1));
        repb (i,u->d,0) {
            int v=(a>>i) & 1;
            if (u->s[v] != NULL) { a&= (~(1<<i)); u=u->s[v]; } 
            else                 { a|=   (1<<i) ; u=u->s[!v];} }
        return a; }
    void work (Node* u) {
        if (u->s[0] == NULL && u->s[1] == NULL) return;
        if (u->s[0] != NULL && u->s[1] != NULL) {
            int res=0x3f3f3f3f; repi (i,u->s[0]->l,u->s[0]->r) checkMin(res,query(u->s[1], a[i]));
            ans += res; see(ans); }
        if (u->s[0]!=NULL) work(u->s[0]);
        if (u->s[1]!=NULL) work(u->s[1]); }
    long long main () {
        ans=0;
        work(R);
        return ans; } };
Trie Tr;
void init() {
    scanf(I,&n);
    rep (i,n) scanf(I,&a[i]); sort(a,a+n);
    rep (i,n) Tr.insert(a[i],i);
}

void solve() {
    printf("%lld\n",Tr.main());
}