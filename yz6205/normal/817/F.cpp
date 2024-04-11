#include <iostream>
#include <cstdio>
using namespace std; 

#ifndef _LIB_SCANNER
#define _LIB_SCANNER 1 
#include <stdio.h>
#include <stdlib.h> 
class Scanner {
private:
    static const int BUFFER_SIZE = 10000; char buff[BUFFER_SIZE]; int buffPos, buffLim; 
public:
    Scanner () { buffLim = fread(buff, 1, BUFFER_SIZE, stdin); buffPos = 0; } 
private:
    inline void flushBuff() { buffLim = fread(buff, 1, BUFFER_SIZE, stdin); if (buffLim==0) { buff[buffLim++] = '\n'; } buffPos = 0; } 
    inline bool isWS(char t) { return t==' ' || t=='\n'; } 
    inline bool isDig(char t) { return t>='0' && t<='9'; } 
    void nextPos() { buffPos++; if (buffPos == buffLim) { flushBuff(); } } 
#define getChar() buff[buffPos]
public:
    inline char getchar() { char ch=getChar(); nextPos(); return ch; } 
    inline void next(char* s) { while ( isWS(getChar()) ) { nextPos(); } while ( !isWS(getChar()) ) { *s = getChar(); s++; nextPos(); } *s = '\0'; } 
    inline void nextLine(char* s) { while ( getChar()!='\n' ) { nextPos(); } if ( getChar()=='\n' ) { nextPos(); } while ( getChar() != '\n' ) { *s = getChar(); s++; buffPos++; } *s = '\0'; } 
    inline int nextInt() { while ( !isDig(getChar()) && getChar() != '-' ) { nextPos(); } int sign = (getChar() == '-') ? nextPos(),-1 : 1; int res = 0; while (isDig(getChar())) { res = res*10 + getChar()-'0'; nextPos(); } return res * sign; } 
    inline long long n() { while ( getChar()<'0' || getChar()>'9' ) { buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } long long res = 0; while ( getChar()>='0' && getChar()<='9' ) { res = res*10 + (getChar()-'0'); buffPos++; if ( buffPos == buffLim ) { flushBuff(); } } return res; }
    inline double nextDouble() { while ( isWS(getChar()) ) { nextPos(); } int sign = (getChar() == '-') ? nextPos(),-1 : 1; double res = 0; while (isDig(getChar())) { res = res * 10 + getChar()-'0'; nextPos(); } if (getChar() == '.') { nextPos(); double ep = 1; while (isDig(getChar())) { ep *= 0.1; res += ep * (getChar()-'0'); nextPos(); } } return sign * res; } 
    inline char nextChar() { while (isWS(getChar())) nextPos(); char res = getChar(); nextPos(); return res; }
#undef getChar
}; Scanner sc;
#endif /* _LIB_SCANNER */

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
#include <bitset>

#ifdef ENABLE_LL
#define int long long
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
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)

typedef std::pair < int , int > pr; 
typedef std::pair < pr  , int > prr; 
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); } 
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); } 
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } } 
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }
#define L first
#define R second

#ifdef __LOCALE__
template <typename T> void __ses(T a) { cout << a << " "; }
template <typename T, typename ... Args> void __ses(T a, Args... b) { cout << a << " "; __ses(b...); }
#define ses(...) { cout << #__VA_ARGS__ << " = "; __ses(__VA_ARGS__); }
#define see(...) { ses(__VA_ARGS__); cout << endl; }
#define slog(format, ...) printf(format, __VA_ARGS__)
#else
#define see(...) 
#define ses(...)
#define slog(format, ...)
#endif


#ifndef CUSTOM_MAIN
void preInit(); void init(); void solve(); int32_t main(){ preInit(); 
#ifdef MULTIPLE_TEST_CASES_WITH_T
int T; 
#ifdef _LIB_SCANNER
T = sc.nextInt();
#else
scanf("%d",&T); 
#endif /* _LIB_SCANNER */
while(T--) {init(); solve();} 
#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T 
while(1) { try {init(); } catch(bool t) {return 0;} solve(); }
#else
init(); solve(); 
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */
#endif /* MULTIPLE_TEST_CASES_WITH_T */
    return 0; }
#endif /* CUSTOM_MAIN */

// my code begins here

#define long long long

const int N = 100005;

struct STree {
    struct Node {
        // tag:  0:unset 1:to0 2:to1 3:reverse
        int8_t v0, v1, tag;
        Node *l, *r;

        Node () { v0=1; v1=0; tag=0; l=r=NULL; }
        void inherit(Node *f) { v0=f->v0; v1=f->v1; }
        void pushUp() {
            v0=0; v1=0;
            if (l!=NULL) { v0 |= l->v0; v1 |= l->v1; }
            if (r!=NULL) { v0 |= r->v0; v1 |= r->v1; } }
        void push0() { tag=1; v0=1; v1=0; }
        void push1() { tag=2; v0=0; v1=1; }
        void push2() {
            swap(v0, v1); 
            if (tag==0) { tag=3; }
            else if (tag==1) { tag=2; }
            else if (tag==2) { tag=1; }
            else { tag=0; } }
        inline void push(int8_t opt) {
            if (opt==1) { push0(); }
            else if (opt==2) { push1(); }
            else if (opt==3) { push2(); } }
        void pushDown();
    };

    static Node pool[N*180];
    static int cnt;
    static Node* newNode() { return &(pool[cnt++] = Node()); }

    Node *R;
    STree() { R = newNode(); }
    void modify(long l, long r, long sl, long sr, int opt, Node *u) {
        if (sl <= l && r <= sr) { u->push(opt); return; }
        u->pushDown();
        long mid = (l+r)/2;
        if (sl <= mid) { modify(l,mid,sl,sr,opt,u->l); }
        if (sr > mid) { modify(mid+1,r,sl,sr,opt,u->r); } 
        u->pushUp();  }
    long query(long l, long r, Node *u) {
        if (l == r) { return l; }
        u->pushDown();
        long mid = (l+r)/2;
        if (u->l->v0) { return query(l,mid,u->l); }
        else { return query(mid+1,r,u->r); } }
} T;

void STree::Node::pushDown() {
    if (l == NULL) { l = STree::newNode(); l->inherit(this); }
    else { l->push(tag); }
    if (r == NULL) { r = STree::newNode(); r->inherit(this); }
    else { r->push(tag); }
    tag=0; }

STree::Node STree::pool[N*180];
int STree::cnt = 0;

void preInit() { } void init() { } void solve() {
    const long L = 1;
    const long R = (long)(1e18) + 5;
    int n = sc.n();
    while (n--) {
        long opt=sc.n(), l=sc.n(), r=sc.n();
        if (opt == 1) { T.modify(L,R, l,r, 2, T.R); }
        else if (opt == 2) { T.modify(L,R, l,r, 1, T.R); }
        else { T.modify(L,R, l,r, 3, T.R); }
        printf("%lld\n", T.query(L,R, T.R)); }
}