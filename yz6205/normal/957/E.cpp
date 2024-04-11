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

const int N = 100005;
int n,s;

inline int lowbit (int x) {
    return x & (-x);
}
int tree[N];
void insert(int w , int u) {
    w += 5;
    for (;w<=n + 10;w+=lowbit(w)) tree[w] += u;
}

int query(int w) {
    w += 5;
    int ans = 0;
    for (;w > 0;w -= lowbit(w)) ans += tree[w];
    return ans;
}

int v[N] , w[N];

struct Node {
    double l,r;

    Node (double l = 0 , double r = 0) : l(l) , r(r) {}
    bool operator < (Node B) {
        return l != B.l ? l > B.l : r < B.r;
    }
};

Node inter[N];
double Disy[N];
void init(){
    scanf("%lld%lld",&n,&s);
    rep (i,n) scanf("%lld%lld",&w[i],&v[i]);
    rep (i,n) inter[i] = Node( (double)(1.0) * w[i] / (v[i] + s) , (double)(1.0) * w[i] / (v[i] - s) );
    sort (inter , inter + n);
    rep (i,n) Disy[i] = inter[i].r;
    sort (Disy , Disy + n);
    int ans = 0;
    rep (i,n) {
        see(i);
        int id = lower_bound(Disy , Disy + n , inter[i].r) - Disy;
        see(id);
        ans += query(id);
        insert(id , 1);
    }
    printf("%lld\n",ans);
}

#undef int

int main(){
    init();
    return 0;
}