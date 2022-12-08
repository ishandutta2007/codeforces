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

vector<int> clauses[200010];
int cs[200010];
int valid[200010];
int fs[200010];
int vars[200010][2];
int vs[200010];
int sig[200010][2];

int setted[200010];

void asig(int cl)
{
    forn(i, cs[cl])
    {
        if(setted[clauses[cl][i]]==-1)
        {
            int avar=clauses[cl][i], asign=0;
            forn(j, vs[avar]) if(vars[avar][j]==cl) asign=sig[avar][j];
            
            //cout << cl << " " << avar << " " << asign << endl;
            setted[avar]=asign;
            
            forn(j, vs[avar])
            {
                fs[vars[avar][j]]--;
            }
            
            forn(j, vs[avar])
            {
                if(sig[avar][j]==asign) valid[vars[avar][j]]=1;
                 
                if(!valid[vars[avar][j]] && fs[vars[avar][j]]==1) asig(vars[avar][j]);
                
            }
            return;
        }
    }
}

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif
    
    int n, m;
    scanf("%i %i", &n, &m);
    
    forn(i, n)
    {
        scanf("%i", &(cs[i]));
        clauses[i].resize(cs[i]);
        forn(j, cs[i])
        {
            scanf("%i", &(clauses[i][j])); 
            int avar=abs(clauses[i][j]);
            vars[avar][vs[avar]]=i;
            sig[avar][vs[avar]]=(avar==clauses[i][j]);
            vs[avar]++;
            
            clauses[i][j]=avar;
        }
        
        fs[i]=cs[i];
    }
    
    memset(setted,-1,sizeof(setted));
    forn(i, n)
    {
        if(fs[i]==1 && !valid[i]) asig(i);
    }
    
    forn(i, n) if(fs[i]==0 && !valid[i]){ printf("NO\n"); return 0; }
    
    forn(i, n)
    {
        if(!valid[i]) asig(i); 
    }
    
    forn(i, m) if(setted[i+1]==-1) setted[i+1]=0;
    
    printf("YES\n");
    forn(i, m) printf("%i", setted[i+1]);
    printf("\n");
    
    return 0;
}