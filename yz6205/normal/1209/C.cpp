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

const int N = 200005;
char s[N];
int a[N];
int n;

void init() {
    scanf(I,&n);
    scanf("%s",s);
    rep (i,n) a[i] = s[i] - '0';
}

int ans[N];
void solve() {
    rep (sp,10) {
        vector < int > v1, v2;
        int m1=n, m2=n;
        rep (i,n) {
            if (a[i] < sp) {
                v1.push_back(a[i]);
                m1=i;
                ans[i] = 1;
            } else if (a[i] > sp) {
                v2.push_back(a[i]);
                checkMin(m2,i);
                ans[i] = 2;
            }
        }        

        //jury
        rep (i,(int)v1.size()-1) if (v1[i] > v1[i+1]) goto nxt;
        rep (i,(int)v2.size()-1) if (v2[i] > v2[i+1]) goto nxt;
        rep (i,n) if (a[i] == sp) if (!(i > m1 || i < m2)) goto nxt;
        
        see(sp);
        rep (i,n) {
            if (a[i] == sp) putchar((i>m1) ? '1' : '2');
            else printf(I,ans[i]);
        }
        puts("");
        return;
nxt:;
    }
    puts("-");
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    int T; scanf(I,&T);
    while (T--) {
        init();
        solve();
    }
    return 0;
}