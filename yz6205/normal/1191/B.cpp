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

bool up(string a, string b) {
    return a[0] + 1 == b[0] && a[1] == b[1];
}

bool dup(string a, string b) {
    return a[0] + 2 == b[0] && a[1] == b[1];
}

int main(){
    string a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a , a + 3);
    int ans = 2;
    if (a[0] == a[2]) {
        ans = 0;
    }
    if (a[0] == a[1] || a[1] == a[2]) {
        ans = min(ans,1);
    }
    if (up(a[0],a[1]) && up(a[1] , a[2])) {
        ans = 0;
    }
    if ( up(a[0],a[1]) || up(a[1],a[2]) || up(a[0],a[2]) || dup(a[0],a[1]) || dup(a[0],a[2]) || dup(a[1],a[2])  ) {
        ans = min(ans,1);
    }
    printf("%d\n",ans);
    return 0;
}