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
#define forn(a, n) for(int a = 0; a<(n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
using namespace std;

struct Eje{ long f,m; long d(){return m-f;}};
#define MAX_N 256
typedef map <int, Eje> MIE; MIE red[MAX_N];
int N,F,D;

void iniG(int n, int f, int d){N=n; F=f; D=d;fill(red, red+N, MIE());}

void aEje(int d, int h, int m){
    red[d][h].m=m;red[d][h].f=red[h][d].m=red[h][d].f=0;
}

#define DIF_F(i,j) (red[i][j].d())
#define DIF_FI(i) (i->second.d())

int v[MAX_N];

long camAu(){
    fill(v, v+N,-1);
    queue<int> c;
    c.push(F);
    while(!(c.empty()) && v[D]==-1){
        int n = c.front(); c.pop();
        for(MIE::iterator i = red[n].begin(); i!=red[n].end(); i++){
            if(v[i->first]==-1 && DIF_FI(i) > 0){
                v[i->first]=n;
                c.push(i->first);
            }
        }
    }
    if(v[D]==-1)return 0;
    int n = D;
    long f = DIF_F(v[n], n);
    while(n!=F){
        f=min(f,DIF_F(v[n], n));
        n=v[n];
    }
    n = D;
    while(n!=F){
        red[n][v[n]].f=-(red[v[n]][n].f+=f);
        n=v[n];
    }
    return f;
}

long flujo(){long tot=0, c;do{tot+=(c=camAu());}while(c>0); return tot;}

long long num[128];
long long good[12800][2];

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif
    int n, m;
    cin >> n >> m;
    
    forn(i, n) cin >> num[i];
    forn(i, m){ cin >> good[i][0] >> good[i][1]; if(good[i][0]%2) swap(good[i][0], good[i][1]); }
    
    set<long long> primes;
    forn(i, n)
    {
        long long r=num[i];
        for(long long j=2; j*j<=r; j++)
        {
            if(r%j==0)
            {
                primes.insert(j);
                while(r%j==0) r/=j;
            }
        }
        if(r!=1) primes.insert(r);
    }
    
    long long ans=0;
    forall(a, primes)
    {
        iniG(n+2, 0, n+1);
        
        long long p=(*a);
        //cout << p << endl;
        forn(i,n)
        {
            if((i+1)%2){
                long long r=num[i];
                int cap=0;
                while(r%p==0){ r/=p; cap++;}
                //cout << i << " " << cap << endl;
                if(cap) aEje(i+1, n+1, cap);
            }
            else
            {
                long long r=num[i];
                int cap=0;
                while(r%p==0){ r/=p; cap++;}
                if(cap) aEje(0, i+1, cap);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(num[good[i][0]-1]%p==0 && num[good[i][1]-1]%p==0)
            {
                long long r=num[good[i][0]-1], s=num[good[i][1]-1], cap=0;
                while(r%p==0 && s%p==0)
                {
                    cap++;
                    r/=p;
                    s/=p;
                }
                //cout << good[i][0] << " " << good[i][1] << " " << cap << endl;
                aEje(good[i][0], good[i][1], cap);
            }
        }
        ans+=flujo();
        //cout << p << endl;
    }
    cout << ans << endl;
}