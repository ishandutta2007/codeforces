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
using namespace std;

#define MAXN 200010
struct rmq {
    int MAX;
    tint vec[4*MAXN];

    tint* init(int n) {
        MAX = 1 << (32-__builtin_clz(n));
        fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
        return vec+MAX;
    }

    void updall() { dforn(i, MAX) vec[i] = max(vec[2*i], vec[2*i+1]); } // + = operacion

    void pset(int i, tint vl) {
        vec[i+=MAX] = vl;
        while(i) { i /= 2; vec[i] = max(vec[2*i], vec[2*i+1]); } // + = operacion
    }

    tint pget(int i, int j) { return _pget(i+MAX, j+MAX); }

    tint _pget(int i, int j) {
            tint res = 0; // 0 = elemento neutro
            if (j-i <= 0) return res;
            if (i%2) res = max(res,vec[i++]); // + = operacin
            res = max(res,_pget(i/2, j/2)); // + = operacin
            if (j%2) res = max(res,vec[--j]); // + = operacin
            return res;
    }
};

pair<long long, long long> next[200010];
pair<long long, long long> cost[200010][20];
long long p[200010], l[200010];

set<pair<long long, long long> > doms;
long long bestcost[200010];
rmq tirogatomulo;

void calcNext(int i)
{
    if(next[i].first!=-1) return;
    
    set<pair<long long, long long> >::iterator it=doms.lower_bound(make_pair(p[i]+l[i], 300000));
    it--;
    long long j=it->second;
    
    long long k=tirogatomulo.pget(i, j+1);
    //cout << j+1 << endl;
    //cout << i << " " << k << endl;
    
    if(j>i)
    {
        next[i].first=k;
        next[i].second=min(p[next[i].first]-p[i]-l[i], bestcost[next[i].first]);
        bestcost[next[i].first]=next[i].second;
    }
    else
    {
        next[i].first=i+1;
        next[i].second=p[i+1]-p[i]-l[i];
        bestcost[i+1]=next[i].second;
    }
    //cout << next[i].first << endl;
    tirogatomulo.pset(i, next[i].first);
}

long long calc(int x, int y)
{
    if(next[x].first>y) return 0;
    
    int s=0;
    while(cost[x][s+1].first<=y) s++;
    //cout << x << " " << y << " " << s << endl;
    //cout << cost[x][s].second << endl;
    return cost[x][s].second+calc(cost[x][s].first, y);
}

int main()
{
#ifdef ACMTUYO
    freopen("E.in","r",stdin);
#endif

    int n;
    cin >> n;
    forn(i, n)
    {
        cin >> p[i] >> l[i];
        doms.insert(make_pair(p[i], i));
    }
    
    tint* v=tirogatomulo.init(n+1);
    forn(i, n) v[i]=i+1;
    v[n]=n;
    tirogatomulo.updall();
    
    p[n]=10000000000000000LL;
    memset(next, -1, sizeof(next));
    memset(bestcost,0x3f, sizeof(bestcost));
    next[n-1]=make_pair(n, 0LL);
    next[n]=make_pair(n, 0LL);
    bestcost[n]=0;
    //bestcost[n-1]=0;
    dforn(i,n-1)
    {
        calcNext(i);
        //cout << next[i].first << " " << next[i].second << endl;
    }
    
    forn(i, n+1)
    {
        cost[i][0]=next[i];
    }
    
    forn(i,19)
        forn(j,n+1)
        {
            cost[j][i+1].first=cost[cost[j][i].first][i].first;
            cost[j][i+1].second=cost[cost[j][i].first][i].second+cost[j][i].second;
            //cout << j << " " << i << cost[j][i].first << " " << cost[j][i].second << endl;
        }
    
    /*if(n==1000)
    {
        forn(i, n) if(p[i]>6706) cout << p[i] << " " << l[i] << " ";
        cout << endl;
    }*/
    /*forn(i,20)
        forn(j,n+1)
        {
            cout << j << " " << i << cost[j][i].first << " " << cost[j][i].second << endl;
        }*/
    int q;
    cin >> q;
    //if(n==1000) cout << q << endl;
    forn(i,q)
    {
        int x, y;
        cin >> x >> y;
        
        x--; y--;
        //cout << x << " " << y << endl;
         cout << calc(x,y) << endl;
        //else cout << x << " " << y << " ";
    }
    
    return 0;
}