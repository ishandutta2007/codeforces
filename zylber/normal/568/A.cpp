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

#define MAXN 1200000
int primes[MAXN];
int plas[MAXN];


int main()
{
#ifdef ACMTUYO
    //freopen("A.in","r",stdin);
#endif

    for(int i=2; i<MAXN; i++)
        if(!primes[i])
            for(int j=2*i; j<MAXN; j+=i) primes[j]=1;


    int p, q;
    cin >> p >> q;
    
    int palin=0, prim=0, best=0;
    for(int i=1; i<MAXN; i++)
    {
        vector<int> dig;
        int j=i;
        while(j>0)
        {
            dig.push_back(j%10);
            j/=10;
        }
        
        int ds=dig.size();
        int k=0;
        forn(j, ds)
        {
            k*=10;
            k+=dig[j];
        }
        
        if(k==i) palin++;
        if(i>=2 && !primes[i]) prim++;
        
        //cout << palin << " " << prim << endl;
        
        if(q*prim <= p*palin) best=i;
    }
    cout << best << endl;

    return 0;
}