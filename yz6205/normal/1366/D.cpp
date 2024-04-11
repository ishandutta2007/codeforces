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

const int N = 10000005;
const int M = 500005;
int a[M];
int firstFactor[N];
int n;

void initFirstFactor() {
    memset (firstFactor, 0x3f, sizeof(firstFactor));
    firstFactor[1] = -1;
    firstFactor[2] = 2;
    for (int i=2;i<N;i++) for (int j=i;j<N;j+=i) checkMin(firstFactor[j], i);
}

void init() {
    initFirstFactor(); 
    see("pass");
    scanf(I,&n);
    rep (i,n) scanf(I,&a[i]);
}

vector < pr > getFactors (int x) {
    vector < pr > res;
    while (x != 1) {
        if (res.empty() || res.back().L != firstFactor[x]) res.push_back( pr(firstFactor[x], 1) );
        else res.back().R++;
        x /= firstFactor[x];
    }
    return res;
}

int a1[M], a2[M];
void solve() {
    rep (i,n) {
        auto v = getFactors(a[i]);
        if (v.size() == 1) a1[i] = a2[i] = -1;
        else {
            a1[i] = a2[i] = 1;
            rep (j,v[0].R) a1[i] *= v[0].L;
            for (int j=1;j<(int)v.size();j++) rep (k,v[j].R) a2[i] *= v[j].L;
        }
    } 
    rep (i,n) { printf(I, a1[i]); putchar(' '); }
    puts("");
    rep (i,n) { printf(I, a2[i]); putchar(' '); }
}


#ifdef ENABLE_LL
#undef int
#endif
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