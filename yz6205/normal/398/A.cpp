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
 
#define int long long
 
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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
 
const int INF = 0x3f3f3f3f3f3f3f3f;
int a , b;
 
inline int calcMin(int n , int p) {
    if (p > n || p <= 0) return INF;
    return (n / p + 1) * (n / p + 1) * (n % p) + (n / p) * (n / p) * (p - n % p);
}
 
inline int calcMax(int n , int p) {
    if (p > n || p <= 0) return -INF;
    return (p - 1) + (n - p + 1) * (n - p + 1);
}   
 
inline string repeat(string c , int t) {
    string s;
    rep (i,t) s += c;
    ses(c);ses(t);see(s);
    return s;
}
 
vector < string > sa , sb;
void show(int x , int y) {  
    ses(a);see(x);
    rep (i,x) sa.push_back( repeat("o",i == 0 || x == 1? a - x + 1 :1) );
    rep (i,y) sb.push_back( repeat("x",b / y + (i < (b % y))) );
    ses(sa[0]);see(sb[0]);
    int m = min(x , y);
    if (y > m) cout << sb[y - 1];
    rep (i,m) cout << sa[i] << sb[i];
    if (x > m) cout << sa[x - 1];
    puts("");
}
 
#undef int
int main(){
#define int long long
    cin >> a >> b;
    if (a == 0) {
        cout << -b * b << endl;
        cout << repeat("x",b);
        return 0;
    }else if (b == 0) {
        cout << a * a << endl;
        cout << repeat("o",a);
        return 0;
    }
    int p = min(a,b);
    int ans = -INF;
    int ansi , ansj;
    repa (i,p) {
        for (int j = i-1 ; j <= i+1 ; j++ ){
            int nans = calcMax(a , i) - calcMin(b , j);
            ses(i);ses(j);see(nans);
            if (nans > ans) {
                ans = nans;
                ansi = i;
                ansj = j;
            }
        }
    }
    cout << ans << endl;
    show(ansi , ansj);
    return 0;
}