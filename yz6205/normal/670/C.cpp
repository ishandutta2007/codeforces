#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif

const int N = 200005;
typedef pair < int , int > pii;
int n,m;
int a[N];
int x[N];
int idx = 0;

void init(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    a[0] = -1;
    for (int i=1;i<=n;i++){
        if (a[i] != a[i - 1]){
            x[++idx] = a[i];
        }
    }
    x[++idx] = 1e9 + 5;
}

bool haveApr(int t){
    return x[lower_bound(x + 1,x + idx + 1,t) - x] == t;
}

int get(int t){
    return lower_bound(x + 1,x + idx + 1,t) - x;
}

int tot[N];
int r1[N],r2[N];
void solve(){
    cin >> m;
    for (int i=1;i<=m;i++){
        cin >> r1[i];
    }
    for (int i=1;i<=m;i++){
        cin >> r2[i];
    }
    for (int i=1;i<=n;i++){
        tot[get(a[i])] ++;
    }
    int ans = 1;
    pii tmp(0,0);
    for (int i=1;i<=m;i++){
        int t1 = 0,t2 = 0;
        if (haveApr(r1[i])){
            t1 = tot[get(r1[i])];
        }
        if (haveApr(r2[i])){
            t2 = tot[get(r2[i])];
        }
        pii tns(t1,t2);
        if (tns > tmp){
            tmp = tns;
            ans = i;
        }
    }
    cout << ans << endl;
}

int main(){
    init();
    solve();
    return 0;
}