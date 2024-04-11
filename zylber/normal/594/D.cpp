#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
typedef tint tipo;
using namespace std;

#define MAXN 200010
struct rmq {
    int MAX;
    tipo vec[4*MAXN];
    tipo* init(int n) {
        MAX = 1 << (32-__builtin_clz(n)); 
        fill(vec, vec+2*MAX, 1); // 0 = elemento neutro
        return vec+MAX;
    }
    void updall() { dforn(i, MAX) vec[i] = (vec[2*i] * vec[2*i+1])%MOD; } // + = operacion
    void pset(int i, tipo vl) {
        vec[i+=MAX] = vl;
        while(i) { i /= 2; vec[i] = (vec[2*i] * vec[2*i+1])%MOD; } // + = operacion
    }
    tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
    tipo _pget(int i, int j) {
        tipo res = 1;             // 0 = elemento neutro
        if (j-i <= 0) return res;
        if (i%2) res = (res*vec[i++])%MOD; // + = operacin
        res = (res*_pget(i/2, j/2))%MOD;   // + = operacin
        if (j%2) res = (res*vec[--j])%MOD; // + = operacin
        return res;
    }
};

rmq prod;

int a[200010];
tint ultimo[1000000];

pair<pair<int,int>, int> que[200010];
long long res[200010];

tint modexp(tint b, tint e)
{
    if(e==0) return 1;
    
    tint pans=modexp(b,e/2);
    pans=(pans*pans)%MOD;
    if(e%2) pans=(pans*b)%MOD;
    return pans;
}

tint inv(tint a)
{
    return modexp(a, MOD-2);
}

tint calcphi(tint n, tint pos)
{
    tint ans=1;
    for(tint i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(ultimo[i]!=-1)
            {
                int ppos=ultimo[i];
                tint red = prod.vec[ppos+prod.MAX];
                red = ((red*i)%MOD)*inv(i-1)%MOD;
                prod.pset(ppos, red);
            }
            ultimo[i]=pos;
            
            ans = (ans*(i-1))%MOD;
            n/=i;
            while(n%i==0)
            {
                ans = (ans*i)%MOD;
                n/=i;
            }
        }
    }
    
    if(n!=1)
    {
        tint i=n;
        if(ultimo[i]!=-1)
        {
            int ppos=ultimo[i];
            tint red = prod.vec[ppos+prod.MAX];
            red = (((red*i)%MOD)*inv(i-1))%MOD;
            prod.pset(ppos, red);
        }
        ultimo[i]=pos;
            
        ans = (ans*(i-1))%MOD;  
    }
    
    return ans;
}

int main()
{
#ifdef ACMTUYO
    freopen("D.in","r",stdin);
#endif

    memset(ultimo, -1, sizeof(ultimo));

    int n;
    cin >> n;
    prod.init(n);
    
    forn(i, n) scanf("%i", &(a[i]));
    
    int q;
    cin >> q;
    forn(i, q)
    {
        scanf("%i %i", &(que[i].first.second), &(que[i].first.first));
        que[i].second=i;
    }
    
    sort(que, que+q);

    int iq=0;
    forn(i, n)
    {
        prod.pset(i, calcphi(a[i], i));
        /*forn(j, i+1) cout << prod.vec[prod.MAX+j] << " ";
        cout << endl;*/
        
        while(iq<q && que[iq].first.first==i+1)
        {
            res[que[iq].second] = prod.pget(que[iq].first.second-1, que[iq].first.first);
            iq++;
        }
    }
    
    forn(i, q) printf("%i\n", int(res[i]));

    return 0;
}