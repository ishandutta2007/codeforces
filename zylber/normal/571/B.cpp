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

tint arr[300010];
tint DP[5010][5010];
tint sum[300010];
tint l1, l2;

tint calcdp(int d1, int d2)
{
    if(DP[d1][d2]!=-1) return DP[d1][d2];
    
    tint &ans=DP[d1][d2];
    
    ans=1000000000000000000LL;
    
    int quedan=d1*l1+d2*l2;
    
    if(d1+d2==0)
    {
        ans=0;
        return ans;
    }
    
    //cout << d1 << " " << d2 << " " << quedan << endl;
    //if(d1) cout << calcdp(d1-1, d2) << endl;
    //if(d2) cout << calcdp(d1, d2-1) << endl;
    if(d1) ans=min(ans, calcdp(d1-1, d2)+arr[quedan-1]-arr[quedan-l1]);
    if(d2) ans=min(ans, calcdp(d1, d2-1)+arr[quedan-1]-arr[quedan-l2]);
    
    return ans;
}

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif
    
    int n, k;
    cin >> n >> k;
    
    forn(i, n) cin >> arr[i];
    sort(arr, arr+n);
    
    //sum[0]=arr[0];
    //for(int i=1; i<n; i++) sum[i]=sum[i-1]+arr[i];
    
    memset(DP, -1, sizeof(DP));
    
    l1=n/k; l2=l1+1;
    tint d2=n%k;
    tint d1=k-d2;
    
    cout << calcdp(d1, d2) << endl;
    
    //forn(i, d1+1) forn(j, d2) cout << DP[i][j] << endl;
    return 0;
}