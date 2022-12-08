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

tint l[5], r[5];

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif
    int n;
    cin >> n;
    forn(i, n) cin >> l[i] >> r[i];
    
    double ans=0;
    forn(i, n)
    {
        forn(j, n)
        if(i!=j)
        {
            double p=1;
            p/=(r[i]-l[i]+1);
            for(tint k=l[i]; k<=r[i]; k++)
            {
                //cout << i << " " << j << " " << k << endl;
                double ex=p*k;
                
                forn(a, n)
                {
                    if(a==j)
                    {
                        tint bot=k;
                        if(j<i) bot++;
                        bot=max(l[j], bot);
                        
                        double p1=max(0LL, r[j]-bot+1);
                        p1/=(r[j]-l[j]+1);
                        ex*=p1;
                    }
                    else
                    {
                        if(a!=i)
                        {
                            tint top=k;
                            if(a>i) top--;
                            top=min(top, r[a]);
                            
                            double p1=max(0LL, top-l[a]+1);
                            p1/=(r[a]-l[a]+1);
                            ex*=p1;
                        }
                    }
                }
                ans+=ex;
            }
        }
    }
    
    printf("%.9f\n", ans);
    return 0;
}