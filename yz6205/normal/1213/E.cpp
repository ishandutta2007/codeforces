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
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

int n;
char s[20], t[20];

void init() {
    scanf(I,&n);
    cin >> s >> t;
}

char a[10] = {'a', 'b', 'c', 'a'};

inline bool j(char* a, char* b) {
    return (a[0] != b[0] || a[1] != b[1]);
}

void solve() {
    puts("YES");
    if (s[0] != s[1] && t[0] != t[1]) {
        do {
            if ( j(a,s) && j(a+1,s) &&
                 j(a,t) && j(a+1,t) ) break;
        } while (next_permutation(a, a+3));
        rep (i,3) rep (_,n) cout << a[i];
    }else {
        do {
            a[3] = a[0];
            if ( j(a,s) && j(a+1,s) && j(a+2,s) &&
                 j(a,t) && j(a+1,t) && j(a+2,t) ) break;
        } while (next_permutation(a, a+3));
        a[3] = '\0';
        rep (i,n) printf("%s",a);
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