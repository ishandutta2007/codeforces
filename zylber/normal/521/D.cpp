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

long long skill[100010];
vector<pair<tint, tint> > adds[100010];
pair<tint, tint> planch[100010];
int type[100010];

struct event{
    int i;
    long long p, q;
};
vector<event> ops;

bool compa1(const event a, const event b)
{
    if(a.p*b.q!=a.q*b.p) return a.p*b.q>a.q*b.p;
    return a.i<b.i;
}
vector<pair<int, int> > ans;

int main()
{
#ifdef ACMTUYO
    freopen("295D.in","r",stdin);
#endif

    int k, n, m;
    cin >> k >> n >> m;
    
    forn(i, k) cin >> skill[i];
    
    forn(i, n)
    {
        tint t, j, b;
        cin >> t >> j >> b;
        j--;
        
        if(t==1)
        {
            if(b>planch[j].first)
            {
                planch[j].first=b;
                planch[j].second=i;
            }
        }
        if(t==2)
        {
            adds[j].push_back(make_pair(b, i));
        }
        if(t==3)
        {
            event ne;
            ne.i=i;
            ne.p=b-1;
            ne.q=1;
            ops.push_back(ne);
        }
        type[i]=t;
    }
    
    forn(i, k)
    {
        if(planch[i].first>skill[i]) adds[i].push_back(make_pair(planch[i].first-skill[i], planch[i].second));
        sort(adds[i].begin(), adds[i].end());
        reverse(adds[i].begin(), adds[i].end());
    
        int as=adds[i].size();
        forn(j, as)
        {
            event ne;
            ne.i=adds[i][j].second;
            ne.p=adds[i][j].first;
            ne.q=skill[i];
            ops.push_back(ne);
            skill[i]+=adds[i][j].first;
        }
    }
    
    
    sort(ops.begin(), ops.end(), compa1);
    
    int l=min((int) ops.size(), m);
    forn(i, l)
    {
        ans.push_back(make_pair(type[ops[i].i], ops[i].i));
    }
    
    cout << l << endl;
    
    sort(ans.begin(), ans.end());
    forn(i, l)
    {
        if(i) cout << " ";
        cout << ans[i].second+1;
    }
    cout << endl;
    
    return 0;
}