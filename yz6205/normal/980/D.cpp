// nan
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

const int N = 5005;
int a[N];
int n;

void init(){
    scanf("%d",&n);
    rep (i,n) scanf("%d",&a[i]);
}

int as[N];
int fst[N];
void solve() {
    memset(fst , -1 , sizeof(fst));
    rep (i,n) {
        if (a[i] == 0) fst[i] = i;
        else {
            for (int j=i - 1;j>=0;j--) {
                if (!a[j]) continue;
                long long tmp = 1LL * a[i] * a[j];
                if (tmp < 0) continue;
                long long sqn = sqrt(tmp);
                if (sqn * sqn == tmp) {
                    fst[i] = j;
                    break;
                }
            }
        }
    }
    rep (st,n) {
        int len = 0;
        for (int ed = st;ed < n;ed++) {
            if (fst[ed] < st) len++;
            as[len > 1 ? len : 1] ++;
        }
    } 
    repa (i,n) printf("%d ",as[i]);
    puts("");
}

int main(){
    init();
    solve(); 
    return 0;
}