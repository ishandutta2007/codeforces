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

int d[3], t[3];
map<tint, int> DP;
int calcdp(int a[], int mask)
{
    if(DP.count(a[0]+a[1]*100+a[2]*10000+mask*1000000)) return DP[a[0]+a[1]*100+a[2]*10000+mask*1000000];
    DP[a[0]+a[1]*100+a[2]*10000+mask*1000000]=0;
    int &ans=DP[a[0]+a[1]*100+a[2]*10000+mask*1000000];
    forn(i,3) if(a[i]<50) ans=max(ans, a[i]);
    
    forn(i, 3)
    {
        if(!(mask&(1<<i)) && a[i]<50)
        {
            int anda=1;
            forn(j,3) if(a[j]==50+i) anda=0;
            if(anda)
            {
                for(int k=max(1,a[i]-d[i]); k<=a[i]+d[i]; k++)
                {
                    anda=1;
                    forn(j,3) if(a[j]==k)
                    {
                        anda=0;
                    }
                    
                    if(anda)
                    {
                        int prev=a[i];
                        int nmask= mask|(1<<i);
                        a[i]=k;
                        ans=max(ans, calcdp(a,nmask));
                        a[i]=prev;
                    }
                }
            }
        }
    }
    
    forn(i, 3)
    {
        int b=(1<<(i+3));
        if(!(mask&b) && a[i]<50)
        {
            forn(j, 3) if(a[j]-a[i]==1 || a[i]-a[j]==1)
            {
                int prev=a[j], nmask=mask|b;
                a[j]=50+i;
                ans=max(ans, calcdp(a, nmask));
                a[j]=prev;
            }
        }
    }
    
    forn(i, 3)
    {
        int b=(1<<(i+6));
        if(!(mask&b) && a[i]<50)
        {
            int tt=-1;
            forn(j, 3) if(a[j]==50+i) tt=j;
            
            if(tt!=-1)
            for(int k=max(1, a[i]-t[i]); k<=a[i]+t[i]; k++)
            {
                int anda=1;
                forn(j,3) if(a[j]==k) anda=0;
                if(anda)
                {
                    int nmask=mask|b;
                    a[tt]=k;
                    ans=max(ans,calcdp(a, nmask));
                    a[tt]=50+i;
                }
                
            }
            
        }
    }
    return ans;
}

int start[3];

int main()
{
#ifdef ACMTUYO
    freopen("81E.in","r",stdin);
#endif
    forn(i, 3) cin >> start[i] >> d[i] >> t[i];
    cout << calcdp(start, 0) << endl;
    return 0;
}