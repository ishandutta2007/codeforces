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
typedef long long tipo;
using namespace std;

pair<tint, int> a[200010];
tint ans[200010];

#define MAXN 200010
struct rmq {
    int MAX;
    tipo vec[4*MAXN];
    tipo* init(int n) {
        MAX = 1 << (32-__builtin_clz(n)); 
        fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
        return vec+MAX;
    }
    void updall() { dforn(i, MAX) vec[i] = vec[2*i] + vec[2*i+1]; } // + = operacion
    void pset(int i, tipo vl) {
        vec[i+=MAX] = vl;
        while(i) { i /= 2; vec[i] = vec[2*i] + vec[2*i+1]; } // + = operacion
    }
    tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
    tipo _pget(int i, int j) {
        tipo res = 0;             // 0 = elemento neutro
        if (j-i <= 0) return res;
        if (i%2) res += vec[i++]; // + = operacin
        res += _pget(i/2, j/2);   // + = operacin
        if (j%2) res += vec[--j]; // + = operacin
        return res;
    }
};

rmq menores;

int main()
{
#ifdef ACMTUYO
    freopen("F.in","r",stdin);
#endif
    int n;
    cin >> n;
    
    menores.init(n);
    
    forn(i, n)
    {
        cin >> a[i].first;
        //a[i].first=-a[i].first;
        a[i].second=i;
    }
    
    sort(a, a+n);
    
    forn(i, n)
    {
        //cout << a[i].first << " " << a[i].second << endl;
        int v=a[i].second;
        for(int k=1; k*v+1<n && k<n; k++)
        {
            int l=k*v+1;
            int u=min(n, k*v+k+1);
            //if(k==1) cout << l << " " << u << endl;
            ans[k]+=menores.pget(l, u);
        }
        menores.pset(v, 1);
    }
    
    //cout << "VENGO BIEN" << endl;
    forn(i, n-1)
    {
        if(i) cout << " ";
        cout << ans[i+1];
    }
    cout << endl;
    
    return 0;
}