#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long double ld;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int dp[2][109][40009];
int MM=20001;
int n;
int infi=1e7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout<<fixed;
    cin>>n;
    vi c(n+9);
    vi b(n+9);
    for(int i=1; i<=n; i++)
    {
        cin>>c[i]>>b[i];
        c[i]*=2;
        b[i]*=2;
    }

    for(int ct=0; ct<=n; ct++)
    {
        for(int j=-20000; j<=20000; j++)
        {
            if(j<0) dp[(n+1)%2][ct][j+MM]=j;
        }
    }

    for(int i=n; i>=1; i--)
    {
        for(int ct=0; ct<=n; ct++)
        {
            for(int j=-20000; j<=20000; j++)
            {
                int x=b[i]/2;
                if(j-x<-20000)
                {
                    dp[i%2][ct][j+MM]=-infi;
                    continue;
                }
                dp[i%2][ct][j+MM]=x+dp[(i+1)%2][ct][j-x+MM];
                if(ct>0)
                {
                    dp[i%2][ct][j+MM]=max(b[i]+dp[(i+1)%2][ct-1][j+c[i]-b[i]+MM], dp[i%2][ct][j+MM]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        ld x=dp[1][i][0+MM] / 2.0;
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}