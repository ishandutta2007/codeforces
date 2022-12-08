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
#define c2n(n) ((n)*((n)-1))/2.0
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

vector<vector<pair<long long, tint> > > grafo;
long long prof[1000010];
pair<long long, long long> roads[1000010];
long long weights[1000010];

void calcProf(int i)
{
    prof[i]=1;
    int vs=grafo[i].size();
    
    forn(j, vs)
    {
        int next=grafo[i][j].first;
        if(prof[next]==-1)
        {
            calcProf(next);
            prof[i]+=prof[next];
        }
    }
    return;
}

int main()
{
#ifdef ACMTUYO
    freopen("D.in","r",stdin);
#endif

    long long n;
    cin >> n;
    grafo.resize(n);
    
    forn(i, n-1)
    {
        tint a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        
        roads[i]=make_pair(a,b);
        weights[i]=l;
        
        grafo[a].push_back(make_pair(b,l));
        grafo[b].push_back(make_pair(a,l));
    }
    
    memset(prof, -1, sizeof(prof));
    
    calcProf(0);
    
    double c3n;
    c3n=(n*(n-1)*(n-2));
    c3n/=6;
    
    //forn(i, n) cout << prof[i] << endl;
    
    //forn(i, n) cout << prof[i] << endl;
    //cout << c3n << endl;
    double exp=0;
    forn(i, n-1)
    {
        double dif=weights[i];
        //cout << dif << endl;
        
        int a=roads[i].first, b=roads[i].second;
        if(prof[b]>prof[a]) swap(a,b);
        //cout <<;
        
        exp+=2.0*dif*(prof[b]*c2n(n-prof[b])+c2n(prof[b])*(n-prof[b]));
        //printf("%.9f\n",exp);
    }
    
    int q;
    cin >> q;
    forn(i, q)
    {
        tint r, l;
        cin >> r >> l;
        r--;
        double dif=weights[r]-l;
        //cout << dif << endl;
        weights[r]=l;
        
        tint a=roads[r].first, b=roads[r].second;
        if(prof[b]>prof[a]) swap(a,b);
        //cout << 
        
        exp-=2.0*dif*(prof[b]*c2n(n-prof[b])+c2n(prof[b])*(n-prof[b]));//*c3n;
        printf("%.9f\n",exp/c3n);
    }
    
    
    return 0;
}