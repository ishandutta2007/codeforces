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
typedef pair < int , int > Point;

const int N = 105;
int a[N];
char x[N];

void show(int x) {
    puts("YES");
    cout << x << endl;
    exit(0);
}

int main(){
    cin >> x;
    int n = strlen(x);
    rep (i,n) a[i] = x[i] - '0';
    rep (i,n) if (a[i] % 8 == 0) show(a[i]);
    rep (i,n) for (int j = i + 1;j<n;j++) {
        int foo = a[i] * 10 + a[j];
        if (foo % 8 == 0) show(foo);
    }
    for (int i=0;i<n;i++) {
        for (int j=i + 1;j<n;j++) {
            for (int k=j + 1;k<n;k++) {
                int foo = a[i] * 100 + a[j] * 10 + a[k];
                if (foo % 8 == 0) show(foo);
            }
        }
    }
    puts("NO");
    return 0;
}