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

int N;
tint DP[200][200][400];
tint m[200][200][400];
tint d[800];
pair<int, int> sol[200][2];


vector<vector<int> > grafo;

tint calcdp(int n, int dup, int ddown, int p);

void calcmn(int n, int dup, int ddown, int p)
{
    m[n][dup][ddown]=DP[n][dup][ddown];
    if(ddown<2*N){ calcdp(n, dup, ddown+1, p); m[n][dup][ddown]=min(m[n][dup][ddown], m[n][dup][ddown+1]); }
}

tint calcdp(int n, int dup, int ddown, int p)
{
    if(DP[n][dup][ddown]!=-1) return DP[n][dup][ddown];
    tint &ans=DP[n][dup][ddown];
    
    ans=d[min(dup,ddown)];
    //cout << n << " " << dup << " " << ddown << " " << p << " " << ans << " " << m[n][dup][ddown]<< endl;
    int vs=grafo[n].size();
    tint prev0=0,prev1=1000000000000000LL;
    
    int resto=(p!=-1);
    /*if(dup==0 && ddown!=0){ans=1000000000000000LL; calcmn(n, dup, ddown,p); 
    return 1000000000000000LL;}*/
    if(vs-resto==0 && (ddown>0 && ddown<dup)){ans=1000000000000000LL; calcmn(n, dup, ddown,p); 
    return 1000000000000000LL;}
    if(vs-resto==0){ ans=d[min(ddown, dup)]; calcmn(n, dup, ddown,p);  
    return ans;}
    
    
    if(ddown)
    {
        forn(i, vs)
        {
            tint act0=1000000000000000LL, act1=1000000000000000LL;
            int v=grafo[n][i];
            int ndup=min(N, min(dup+1, ddown+1));
            int dup1=ndup;
            if(ddown==1) dup1=0;
            if(v!=p)
            {
                act1=min(act1, prev0+calcdp(v, dup1, ddown-1, n));
                act1=min(act1, prev1+calcdp(v, dup1, ddown-1, n));
                
                calcdp(v, ndup, ddown, n);
                act0=min(act0, prev0+m[v][ndup][ddown]);
                act1=min(act1, prev1+m[v][ndup][ddown]);
            
                prev1=act1;
                prev0=act0;
            }
        }
        
    //cout << "PREV " << n << " " << dup << " " << ddown << " " << p << " " << prev1 << endl;
        ans+=prev1;
    }
    else
    {
        tint resto=0;
        forn(i, vs)
        {
            int v=grafo[n][i];
            if(v!=p)
            {
                tint act=1000000000000000LL;
                forn(j, 2*N+1)
                {
                    act=min(act, calcdp(v, 1, j, n));
                }
                resto+=act;
            }
        }
        ans+=resto;
    }
    
    calcmn(n, dup, ddown,p); 
    //if(ans<1000) cout << n << " " << dup << " " << ddown << " " << p << " " << ans << " " << m[n][dup][ddown]<< endl;
    return ans;
}

void construct(int n, int dup, int ddown, int p)
{
    //cout << n << " " << dup << " " << ddown << " " << p << endl;
    sol[n][0]=make_pair(dup, ddown);
    int vs=grafo[n].size();
    
    tint prev0=0,prev1=1000000000000000LL;
    if(ddown)
    {
        int first1=0;
        forn(i, vs)
        {
            tint act0=1000000000000000LL, act1=1000000000000000LL;
            int v=grafo[n][i];
            int ndup=min(N, min(dup+1, ddown+1));
            int dup1=ndup;
            if(ddown==1) dup1=0;
            if(v!=p)
            {
                int best=ddown;
                for(int j=ddown; j<=2*N; j++) if(calcdp(v, ndup, j, n)<calcdp(v, ndup, best, n)) best=j;
                
                act0=min(act0, prev0+m[v][ndup][ddown]);
                act1=min(act1, prev1+m[v][ndup][ddown]);
                sol[v][0]=make_pair(ndup, best);
                sol[v][1]=make_pair(ndup, best);
                
                if(prev1+calcdp(v, dup1, ddown-1, n) < act1)
                {
                    sol[v][1]=make_pair(dup1, ddown-1);
                    act1=min(act1, prev1+calcdp(v, dup1, ddown-1, n));
                }
                
                if(prev0+calcdp(v, dup1, ddown-1, n) < act1)
                {
                    first1=i;
                    sol[v][1]=make_pair(dup1, ddown-1);
                    act1=min(act1, prev0+calcdp(v, dup1, ddown-1, n));
                }
                
            
                prev1=act1;
                prev0=act0;
            }
            
            
        }
        
        //cout << first1 << endl;
        forn(i, vs)
        {
            int v=grafo[n][i];
            if(v!=p)
            {
                if(i<first1)
                {
                    construct(v, sol[v][0].first, sol[v][0].second, n);
                }
                else
                {
                    construct(v, sol[v][1].first, sol[v][1].second, n);
                }
            }
        }
    }
    else
    {
        forn(i, vs)
        {
            int v=grafo[n][i];
            if(v!=p)
            {
                tint act=1000000000000000LL;
                forn(j, 2*N+1)
                {
                    if(act> calcdp(v, 1, j, n))
                    {
                        sol[v][0]=make_pair(1, j);
                        act=min(act, calcdp(v, 1, j, n));
                    }
                }
                construct(v, sol[v][0].first, sol[v][0].second, n);
            }
        }
    }
}

int ans[200];

int main()
{
#ifdef ACMTUYO
    freopen("70E.in","r",stdin);
#endif

    cin >> N >> d[0];
    forn(i, N-1) cin >> d[i+1];
    
    grafo.resize(N);
    forn(i, N-1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    
    tint res=1000000000000000LL;
    memset(DP,-1,sizeof(DP));
    
    for(int k=N; k<=3*N; k++) d[k]=1000000;
    
    //calcdp(2, 4, 1, 0);
    int bestj=0;
    forn(j, N+1){ 
        if(calcdp(0, N, j, -1)<res)
        {
            bestj=j;
        }
        res=min(res,calcdp(0, N, j, -1));
    }
    cout << res << endl;

    construct(0, N, bestj, -1);
    memset(ans, -1, sizeof(ans));
    
    queue<int> bfs;
    forn(i, N)
    {
        if(!sol[i][0].second)
        {
            ans[i]=i+1;
            bfs.push(i);
        }
    }
    
    while(!bfs.empty())
    {
        int a=bfs.front(), vs=grafo[a].size();
        //cout << a << endl;
        forn(i, vs)
        {
            int next=grafo[a][i];
            if(ans[next]==-1)
            {
                ans[next]=ans[a];
                bfs.push(next);
            }
        }
        bfs.pop();
    }
    
    forn(i, N)
    {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}