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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; }};
Scanner sc(cin);

const int L = 1e10;
const int N = 100005;
int a[N];
int c[N];
int n, k;

int del (int u) {
    for (int i=2;i*i<=u;i++) {
        while (u % (i*i) == 0) u /= i * i;
    }
    return u;
}

void sub() {
    rep (i,n) a[i] = del( a[i] );
    rep (i,n) c[ a[i] ] ++;
    int ans = 0;
    rep (i,N) ans += c[i] * (c[i]-1) / 2;
    printf(IN,ans);
    exit(0);
}

void init() {
    scanf(II,&n,&k);
    rep (i,n) scanf(I,&a[i]);
    if (k == 2) sub();
    rep (i,n) c[ a[i] ]++;
}

int power(int b, int e) {
    int res = 1;
    while (e--) {
        res *= b;
        if (res >= L) throw (int)(-1);
    }
    return res;
}

vector < int > getFactors(int u) {
    vector < int > res;
    for (int i=1;i*i<=u;i++) {
        if (u % i == 0) {
            res.push_back(i);
            if (i * i != u) res.push_back(u / i);
        }
    }
    return res;
}

void solve() {
    int b = 1;
    int ans = 0;
    while (1) {
        int p;
        try {
            p = power(b,k);
        } catch (int e) {
            printf(IN,ans / 2);
            return ;
        }
        ses(k); see(p);
        vector < int > f = getFactors(p);
        repe (i,f) {
            if (f[i] >= N || (p/f[i]) >= N) continue;
            if (f[i] * f[i] == p) ans += c[ f[i] ] * (c[ f[i] ]-1) ; 
            else ans += c[ f[i] ] * c[ p/f[i] ] ;
        }
        see(ans);
        b++;
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