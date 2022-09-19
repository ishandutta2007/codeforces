#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
int n, m, k;
const int MXN = 2e5+5;
int r[MXN];
int perm[MXN];
#define per perm
VI V[MXN], Vi[MXN];
int sto[MXN];
int low[MXN], high[MXN];
void err() {
    printf("-1\n");
    exit(0);
}
 bool is[MXN];
int main()
    {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n)
        scanf("%d", &r[i]);
    
    REP(i, m)
        {
        int a, b;
        scanf("%d%d", &a, &b);
        V[b].PB(a);
        Vi[a].PB(b);
        sto[a]++;
        }
    queue<int> q;
    FOR(i, 1, n)
        if(sto[i] == 0)
            q.push(i);
    int il = 0;
    while(q.size())
        {
        int x;
        perm[++il] = x = q.front();
        q.pop();
        for(auto v : V[x])
            {
            sto[v]--;
            if(sto[v] == 0)
                q.push(v);
            }
        }
    if(il != n)
        {
        debug("cykl\n");
        cout<<-1<<endl;
        exit(0);
        }
    set <pair <PII, int> > ava;
    FOR(i, 1, n) {
        int v = per[i];
        if (r[v])
            low[v] = r[v];
        else
            low[v] = 1;
        for (auto c : Vi[v]) {
            debug("maxi(low[%d], low[%d] + 1\n", v, c);
            maxi(low[v], low[c] + 1);
        }
        debug("low[%d] = %d\n", v, low[v]);
    }
    FORD(i, n, 1) {
        int v = per[i];
        if (r[v])
            high[v] = r[v];
        else
            high[v] = k;
        for (auto c : V[v]) {
            debug("maxi(low[%d], low[%d] - 1\n", v, c);
            mini(high[v], high[c] - 1);
        }
        debug("high[%d] = %d\n", v, high[v]);
    }
    FOR(i, 1, n)
        if (high[i] < low[i]) err();
    
    vector <pair <int, int> > ranges[MXN];
        FOR(i, 1, n)
            ranges[high[i]].PB(MP(low[i], i));
   
    FOR(i, 1, n)    is[r[i]] = true;
    FORD(R, k, 1) {
        for (auto p : ranges[R]) {
            debug("insert range(%d, %d) from %d\n", p.first, R, p.second);
            ava.insert(MP(MP(p.first, R), p.second));
        }
        if (!is[R]) {
            debug("find %d\n", R);
            while (true) {
                if (ava.empty()) err();
                auto x = ava.end();
                x--;
                auto take = *x;
                ava.erase(x);
                debug("erase (%d, %d) from %d\n", take.f.f, take.f.s, take.s);
                if (take.f.f <= R && take.f.s >= R) {
                    r[take.s] = R;
                    break;
                }
            }
        }
    }
    FOR(i, 1, n) debug("%d ", r[i]);
    debug("\n");
    
    FORD(i, n, 1) {
        int v = per[i];
        if (r[v] == 0) {
            r[v] = k;
            for (auto c : V[v])
                mini(r[v], r[c] - 1);
        }
    }
    
    FOR(i, 1, n)
        {
        for(auto j : V[i])
            {
            if(r[i] > r[j])
                {
                assert(false);
                puts("-1");
                exit(0);
                }
            }
        }
    
    FOR(i, 1, n) printf("%d ", r[i]);
    printf("\n");
    }