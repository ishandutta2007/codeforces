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

const int N = 500005;

struct Segment{
    static const int M = N * 4;
    int ori[N];
    int a[M];
    int n;

    void init (int _n) {
        n = _n;
        memset(a,0,sizeof(a));
        memset(ori , 0 , sizeof(ori));
    }

    void add (int l , int r , int pos , int x) {
        a[pos]++;
        if (l >= r) return;
        int mid = (l + r) >> 1;
        if (x <= mid) add(l , mid , pos * 2 , x);
        else          add(mid + 1 , r , pos * 2 + 1 , x);
    }

    void modify(int w) {
        see(w);
        if (ori[w] == 1) return;
        ori[w] = 1;
        add (1,n,1,w);
    }

    int lower_bound(int k) {
        int l = 1 , r = n , pos = 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[pos * 2] >= k) {
                r = mid;
                pos = pos * 2;
            }else {
                l = mid + 1;
                k -= a[pos * 2];
                pos = pos * 2 + 1;  
            }
        }
        return l;
    }
};

int n,m,q;
int qry[N] , qryIdx[N];
int held[N] , heldIdx[N];

void init(){
    scanf("%lld%lld%lld",&n,&m,&q);
    rep (i,n) {
        int r ; scanf("%lld",&r);
        held[r]++;
    }
    repa (i,m) heldIdx[i] = i;
    sort (heldIdx + 1, heldIdx + m + 1, [](int a, int b) { return held[a] < held[b]; } );

    rep (i,q) scanf("%lld",&qry[i]);
    rep (i,q) qryIdx[i] = i;
    sort (qryIdx , qryIdx + q , [](int a, int b) { return qry[a] < qry[b]; } );
}

int ans [N];

Segment st;
void solve() {
    vector < int > v;
    int sum = 0;
    repa (i,m - 1) {
        see(i);
        sum += held[ heldIdx[i] ];
        v.push_back( held[ heldIdx[i + 1] ] * i - sum) ;
    }
    v.push_back( (int)(2e18) );
    st.init(m + 5);
    rep (i,m) see(v[i]);
    rep (i,q) { 
        see(i);
        int qr = qry[ qryIdx[i] ] - n;
        int id = lower_bound( v.begin() , v.end() , qr) - v.begin() + 1;
        int _id = id;
        while (_id > 0 && st.ori[ heldIdx[_id] ] == 0) {
            see(_id);
            st.modify (heldIdx[_id]);
            _id--;
        }
        see(id);
        qr -= (id == 1) ? 0 : v[id - 2];
        see(qr);
        int fi = (qr - 1) % id + 1;
        ans[ qryIdx[i] ] = st.lower_bound(fi);
    }
}

#undef int

int main(){
    init();
    solve();
    rep (i,q) printf("%lld\n",ans[i]);     
    return 0;
}