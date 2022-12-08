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
using namespace std;

int n;
long long divs[10], ndivs[10];

long long backtrack(int pos, long long nums[], long long tot, long long haypa)
{
    /*cout << pos << " " << tot << " " << haypa << endl;
    forn(i, n) cout << nums[i] << " ";
    cout << endl;*/
    if(pos == n)
    {
        return tot+haypa;
    }
    
    long long best=tot+1;
    forn(i, pos)
    {
        if(nums[i]%nums[pos]==0)
        {
            nums[i]/=nums[pos];
            tot-=ndivs[pos]+(ndivs[pos]==0);
            best=min(best, backtrack(pos+1, nums, tot, haypa));
            nums[i]*=nums[pos];
            tot+=ndivs[pos]+(ndivs[pos]==0);
        }
    }
    best=min(best, backtrack(pos+1,nums,tot, 1));
    return best;
}

int main()
{
#ifdef ACMTUYO
    freopen("196E.in","r",stdin);
#endif
    cin >> n;
    forn(i,n) cin >> divs[i];
    sort(divs, divs+n);
    reverse(divs, divs+n);
    
    forn(i, n)
    {
        ndivs[i]=0;
        long long tmp=divs[i];
        for(long long j=2; j*j<=tmp; ++j)
        {
            while(tmp%j==0)
            {
                tmp/=j;
                ndivs[i]++;
            }
        }
        if(tmp!=1) ndivs[i]++;
        
        if(ndivs[i]==1) ndivs[i]=0;
    }
    
    long long sum=0;
    forn(i,n) sum+=ndivs[i];
    
    cout << backtrack(1, divs, sum, 0)+n << endl;
    
    return 0;
}