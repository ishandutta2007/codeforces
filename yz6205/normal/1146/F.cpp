#define ENABLE_LL
#include <iostream>
#include <cstdio>
using namespace std; 
#ifndef _LIB_SCANNER
#define _LIB_SCANNER 1

#include <stdio.h>
#include <stdlib.h>

class Scanner {
private:
    static const int BUFFER_SIZE = 10000;
    char buff[BUFFER_SIZE];
    int buffPos, buffLim;

public:
    Scanner () { 
        buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
        buffPos = 0;
    }

private:
    inline void flushBuff() {
        buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
        if (buffLim==0) {
            buff[buffLim++] = '\n';
        }
        buffPos = 0; 
    }

    inline bool isWS(char t) {
        return t==' ' || t=='\n';
    }

    inline bool isDig(char t) {
        return t>='0' && t<='9'; 
    }

    void nextPos() {
        buffPos++;
        if (buffPos == buffLim) {
            flushBuff();
        }
    }

#define getChar() buff[buffPos]

public:
    inline char getchar() {
        char ch=getChar();
        nextPos();
        return ch; 
    }

    inline void next(char* s) {
        while ( isWS(getChar()) ) {
            nextPos(); 
        }
        while ( !isWS(getChar()) ) {
            *s = getChar(); s++;
            nextPos();
        }
        *s = '\0';
    }

    inline void nextLine(char* s) {
        while ( getChar()!='\n' ) {
            nextPos();
        }
        if ( getChar()=='\n' ) {
            nextPos();
        }
        while ( getChar() != '\n' ) {
            *s = getChar(); s++;
            buffPos++;
        }
        *s = '\0';
    }

    inline int nextInt() {
        while ( !isDig(getChar()) ) {
            nextPos();
        }
        int sign = (getChar() == '-') ? nextPos(),-1 : 1;
        int res = 0;
        while (isDig(getChar())) {
            res = res*10 + getChar()-'0';
            nextPos();
        }
        return res * sign; 
    }

    inline double nextDouble() {
        while ( isWS(getChar()) ) {
            nextPos();
        }
        int sign = (getChar() == '-') ? nextPos(),-1 : 1;
        double res = 0;
        while (isDig(getChar())) {
            res = res * 10 + getChar()-'0';
            nextPos();
        }
        if (getChar() == '.') {
            nextPos();
            double ep = 1;
            while (isDig(getChar())) {
                ep *= 0.1;
                res += ep * (getChar()-'0');
                nextPos();
            }
        }
        return sign * res;
    }

    inline char nextChar() {
        while (isWS(getChar())) nextPos();
        char res = getChar(); nextPos();
        return res;
    }

#undef getChar
};
Scanner sc;
#endif /* _LIB_SCANNER */
class Intm {
private:
    static unsigned long long MOD;
    unsigned long long a;

public:
    inline static void setMod(const unsigned long long _MOD) {
        MOD = _MOD; }
    inline static void getModSub(unsigned long long & a) {
        if (a>=MOD) a-=MOD; }
    inline static void getMod(unsigned long long & a) {
        a %= MOD; }
    inline static unsigned long long power(unsigned long long a, unsigned long long b) {
        unsigned long long r = 1;
        while (b) {
            if (b&1) getMod(r*=a);
            getMod(a*=a); b>>=1; }
        return r; }

    Intm () { a=0; }
    Intm (unsigned long long _a) : a(_a) { getMod(a); }
    Intm& operator += (const Intm b) {
        a += b.a; getModSub(a); return *this; }
    Intm operator + (const Intm b) const {
        Intm R(a); return (R += b); }
    Intm& operator -= (const Intm b) {
        a += MOD-b.a; getModSub(a); return *this; }
    Intm operator - (const Intm b) const {
        Intm R(a); return (R -= b); }
    Intm& operator *= (const Intm b) {
        a *= b.a; getMod(a); return *this; }
    Intm operator * (const Intm b) const {
        Intm R(a); return (R *= b); }
    Intm& operator /= (const Intm b) {
        a *= power(b.a,MOD-2); getMod(a); return *this; }
    Intm operator / (const Intm b) const {
        Intm R(a); return (R /= b); }
    Intm pow(int e) {
        return Intm(power(a,e)); }

    operator int()  {
        getModSub(a);
        return (int)a; }
};
unsigned long long Intm::MOD;

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

typedef pair < int , int > pr; 
typedef pair < pr  , int > prr; 
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); } 
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); } 
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } } 
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }
#define L first
#define R second

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif

#ifndef CUSTOM_MAIN

void preInit();
void init(); 
void solve(); 

int32_t main(){ 
preInit();

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
while(1) {
    try {init(); } 
    catch(bool t) {return 0;} 
    solve();
}
#else
init(); solve(); 
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */

#endif /* MULTIPLE_TEST_CASES_WITH_T */
    return 0;
}

#endif /* CUSTOM_MAIN */

// my code begins here

typedef Intm Int;
const int MOD = 998244353;
const int N = 200005;
vector <int> e[N];
int n;


void preInit() {
    Int::setMod(MOD);
    n = sc.nextInt();
    repi (i,2,n) e[sc.nextInt()].push_back(i); 
}

void init() {
     
}

Int dp[N][3];

void dfs(int u) { 
    if (e[u].size() == 0) { dp[u][2]=1; return; } dp[u][0]=1;
    for (int v: e[u]) {
        dfs(v); Int U[3] = {dp[u][0],dp[u][1],dp[u][2]}, *V = dp[v];
        dp[u][0] = U[0] * (V[0] + V[2]);
        dp[u][1] = U[0] * (V[1] + V[2]) + U[1] * (V[0] + V[2]);
        dp[u][2] = U[1] * (V[1] + V[2]) + U[2] * (V[0] + V[1] + V[2]*Int(2)); } }
        

void solve() {
    dfs(1);
    printf(IN, static_cast<int>(dp[1][0]+dp[1][2]));
}