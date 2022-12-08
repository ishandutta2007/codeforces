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

int main()
{
#ifdef ACMTUYO
    //freopen("A.in","r",stdin);
#endif
    
    tint a, b, c, l;
    cin >> a >> b >> c >> l;
    
    tint ans=((l+3)*(l+2)*(l+1))/6;
    //cout << ans << endl;
    
    for(int it=0; it<3; it++)
    {
        for(int j=0; j<=l; j++)
        {
            tint tope=a+j;
            if(tope<b+c) continue;
            
            tint r=min(tope-b-c, l-j);
            //cout << r << endl;
            ans-=((r+2)*(r+1))/2;
        }
        
        swap(a,b);
        swap(a,c);
    } 
    cout << ans << endl;
    return 0;
}