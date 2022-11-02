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

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 200005;
int a[N] , b[N];
int w[N] , c[N];
int n;

int main(){
    scanf ("%d",&n);
    repa (i,n) scanf("%d",&a[i]);
    repa (i,n) scanf("%d",&b[i]);
    repa (i,n) w[ b[i] ] = i;
    repa (i,n) if (w[i] == 0) c[i] = -i;
               else           c[i] = w[i] - i;
    repa (i,n) see(c[i]);
    int m1 = -0x3f3f3f3f , m2 = -0x3f3f3f3f;
    repa (i,n) {
        if (c[i] > m1) m2 = m1 , m1 = c[i];
        else if (c[i] > m2 && c[i] != m1) m2 = c[i];
    }
    see(m1);
    see(m2);
    if (m1 < 0) printf("%d\n",m1 + n + 1);
    else {
        if (m2 == -0x3f3f3f3f) printf("%d\n",m1);
        else printf("%d\n" , (m1 == m2 + n + 1) ? m1 : m1 + n + 1);
    }
    return 0;
}