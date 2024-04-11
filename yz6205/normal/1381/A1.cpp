#define MULTIPLE_TEST_CASES_WITH_T
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

const int N = 100005;
int n; int a[N],b[N];
char s[N];

void init() {
    scanf(I,&n);
    scanf("%s",s); rep (i,n) a[i]=s[i]-'0';
    scanf("%s",s); rep (i,n) b[i]=s[i]-'0'; 
}

void rotate(int& l, int& r, int& c) {
    swap(l,r);
    if (l<=r) { r--; }
    else      { r++; }
}

void update(int& l, int& r) {
    if (l<=r) { r--; }
    else      { r++; }
}

void solve() {
    vector <int> ans;
    int l=0, r=n-1; int c=0;
    repb (i,n-1,1) {
        ses(i);ses(l);ses(r);see(c);
        ses((a[r]^c)); see(b[i]);
        if ((a[r]^c)==b[i]) { update(l,r); continue; }
        if ((a[l]^c)!=b[i]) { ans.push_back(i+1); c^=1; rotate(l,r,c); }
        else {
            ans.push_back(1); a[l]^=1;
            ans.push_back(i+1); c^=1; rotate(l,r,c); }
    }
    if ((a[l]^c) != b[0]) ans.push_back(1);
    printf("%d ",(int)ans.size());
    for (int i:ans) printf("%d ",i); 
    puts("");
}