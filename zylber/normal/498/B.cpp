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

double DP[5010][5010];
double probs[5010];
int ch[5010];

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif

    int n, T;
    cin >> n >> T;
    
    for(int i=0; i<n; i++)
    {
        cin >> probs[i] >> ch[i];
        probs[i]/=100;
    }
    probs[n]=0;
    ch[n]=T+1;
    
    memset(DP,0,sizeof(DP));
    
    DP[0][0]=1;
    for(int i=0; i<n; i++)
    {
        double prob=0;
        double rest=1;
        for(int j=0; j<ch[i]-1; j++) rest*=(1.0-probs[i]);
        for(int j=0; j<T; j++)
        {
            prob*=(1.0-probs[i]);
            prob+=probs[i]*DP[i][j];
            //cout << i << " " << j << " " << prob << " " << rest << endl;
            DP[i+1][j+1]+=prob;
            if(j+1>=ch[i]) DP[i+1][j+1]+=rest*(1.0-probs[i])*DP[i][j-ch[i]+1];
            if(j+1>=ch[i]) prob-=rest*probs[i]*DP[i][j-ch[i]+1];
            //DP[i][j+1]+=1-prob;
            
        }
    }
    
    
    
    /*for(int j=0; j<T; j++)
        DP[n][j+1]+=DP[n][j];
    */
    /*forn(i, n+1)
    {
        forn(j, T+1) cout << DP[i][j] << " ";
        cout << endl;
    }*/
    
    double ans=0;
    for(int i=1; i<=n; i++)
    {
        double prob = 1;
        forn(j, min(ch[i], T+1))
        {
            ans+=prob*i*(DP[i][T-j]);
            prob*=(1.0-probs[i]);
            //cout << ans << " " << prob << endl;
        }
        //cout << ans << endl;
    }
    printf("%.7f\n", ans);
    
    return 0;

    
}